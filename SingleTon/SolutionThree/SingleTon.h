#include"boost/noncopyable.hpp"
#include"pthread.h"
template<typename T>
class SingleTon:boost::noncopyable
{
  public:
     static T& GetInstance()
     {
      pthread_once(&ponce_,&SingleTon::init);
      return *value_;
     }
  private:
    SingleTon(){};
    ~SingleTon(){};
    static void init()
    {
      value_ = new T();
    }
   
  private:
    static  T* value_;
    static  pthread_once_t ponce_;
};
  template<typename T>
  T* SingleTon<T>::value_ =NULL;
  template<typename T>
  pthread_once_t SingleTon<T>::ponce_ =PTHREAD_ONCE_INIT;
