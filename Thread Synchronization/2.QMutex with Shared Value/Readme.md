Hi everyone:hand:

In this example, I showed you how Threads can share a Class with simple QWidget application

In this Widget there are 2 Threads whose share a common increment function of a Class. 

When you **Click** the button, two threads start. But ıf you don't use a QMutex, these 2 Threads starts simultaneously:anger: 

I used a QMutexLocker in this example so, one threads wait for other thread:point_right 

![image](https://user-images.githubusercontent.com/91613858/219558962-f3ea0561-bd18-4eec-ad8b-49465c2314aa.png)
