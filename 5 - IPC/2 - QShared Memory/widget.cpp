#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QFileDialog>
#include <QBuffer>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget),
      myMemory("MySharedMemory")
{
    ui->setupUi(this);

    ui->imageLabel->setText("Please Click the Button on the Left side for selecting an Image from PC");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_toShared_clicked()
{
    if (myMemory.isAttached())
    {
        qDebug() << "Memory is attached, detaching";

        detach();
    }

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:/", tr("Images (*.png *.xpm *.jpg)"));

    QImage image;

    if (!image.load(fileName))
    {
        ui->imageLabel->setText(tr("Selected file is not an image, please select another."));

        return;
    }

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));

    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);

    QDataStream out(&buffer);
    out << image;   //write into the buffer

    int size =  buffer.size();


    qDebug() << "Size : " << size;

    if (!myMemory.create(size))
    {
        ui->imageLabel->setText(tr("Unable to create shared memory segment."));

        qDebug() << myMemory.errorString();
        qDebug()  << "Is attached : " << myMemory.isAttached();

        return;
    }

    myMemory.lock();

    char *to = (char*)myMemory.data();
    const char *from = buffer.data().data();

    memcpy(to,from,qMin(myMemory.size(), size));

    myMemory.unlock();
}


void Widget::on_fromShared_clicked()
{
    if (!myMemory.attach())
    {
        ui->imageLabel->setText(tr("Unable to attach to shared memory segment.\n" \
                                   "Load in the data first."));
        return;
    }

    QBuffer buffer;

    QDataStream in(&buffer);

    QImage image;

    myMemory.lock();

    buffer.setData((char*)myMemory.constData(), myMemory.size());
    buffer.open(QBuffer::ReadOnly);

    in >> image;   //read from buffer

    myMemory.unlock();

    myMemory.detach();

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
}

void Widget::detach()
{
    if(!myMemory.detach())
    {
        ui->imageLabel->setText("Can not detach from the shared memory");
    }
}

