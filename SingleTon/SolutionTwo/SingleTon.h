//***************************************************
//**
//* Written by YS [April 9 2018]
//* Describtion:饿汉模式，线程安全，互斥锁，
//* Note:单例模式方案二
//**
//***************************************************
#include<pthread.h>
#include<iostream>
using namespace std;
template<typename T>
class SingleTon
{
 private:
      SingleTon(){};
      SingleTon(const SingleTon&){};
	  SingleTon& operator=(const SingleTon&){};
	  
	  static T* mp_instance;
	  static pthread_mutex_t mutex;
public:
      static T& GetInstance();
};

template<typename T>
T* SingleTon<T>::mp_instance=NULL;

template<typename T>
pthread_mutex_t SingleTon<T>::mutex = PTHREAD_MUTEX_INITIALIZER;



template<typename T>
T& SingleTon<T>::GetInstance()
{
cout<<"print in SingleTon::GetInstance()"<<endl;
 if(mp_instance==NULL)
 {
   pthread_mutex_lock(&mutex);
   if(mp_instance==NULL)
   {
     T* temp=new T();
	 mp_instance = temp;
     return *mp_instance;
   }
   pthread_mutex_unlock(&mutex);
 }
 return *mp_instance;
}
