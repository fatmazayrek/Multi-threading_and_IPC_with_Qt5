Hi everyone:giraffe:

In this example, I showed you how shouldn't use Signal and slots between threads with simple Widget application:fish:

In this application, a thread contains QTimer. This tread is especially created in the main thread but run method starts in the thread:lock: 

If you creat QTimer in the run method, you can't stop it in the another thread:scissors:

I hope, this example helps your studies:sunflower:
