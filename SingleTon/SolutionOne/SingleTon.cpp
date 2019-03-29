#include"SingleTon.h"

class TestSingle:public SingleTon<TestSingle>
{
public:
       TestSingle():SingleTon()
       {
	cout<<"print in TestSingle::TestSingle()"<<endl;
       }
 
       ~TestSingle()
        {
         cout<<"print in TestSingle::~TestSingle()"<<endl;   
        };
};

int main()
{
TestSingle test;
return 0;
}



