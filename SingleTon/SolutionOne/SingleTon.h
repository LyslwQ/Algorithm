//********************************************
//**
//* Written by YS [April 10 2018]
//* FileName: SingleTon.h
//* Describtion:可继承的单例模式实现
//**
//********************************************
#include<iostream>
#include<assert.h>
using namespace std; 
template<typename T>
class SingleTon
{
 
private:
        static T* m_instance;
protected:
        SingleTon()
        {
         cout<<"print in SingleTon::SingleTon()"<<endl;
         assert(!m_instance);
         if(m_instance==NULL)
            m_instance=static_cast<T*>(this); 
        }

        ~SingleTon()
         {
          cout<<"print in SingleTon::~SingleTon()"
              <<endl;
           m_instance=NULL;
         }
public:
      T& GetInstance()
 	 {
          return *m_instance;
         }

      T* GetInstancePtr()
         {
          return m_instance;
         }  
};

template<typename T>
T* SingleTon<T> ::m_instance=NULL;
