#include"iostream"
using namespace std;

bool VerifySequenceOfBST(const int sequence[],int length);
int main()
{

 int testArry[]={7,4,6,5};
 bool result=VerifySequenceOfBST(testArry,sizeof(testArry)/sizeof(int));
 cout<<"the Sequence is the postorder of BST?"<<':'<<result<<endl;
 return 0;
}


bool VerifySequenceOfBST(const int sequence[], int length)
{
  if(sequence==NULL||length<=0)
     return false;
  
  int root=sequence[length-1];
  int i=0;
  while(i<length-1&&sequence[i]<root)
     i++;
  
  int j=i;
  while(j<length-1)
  {
   if(sequence[j]<root)
   return false;
   j++;
  }
  
  bool left=true; 
  if(i>0)
  left=VerifySequenceOfBST(sequence,i);
  bool right=true;
  if(length-i-1>0)
  right=VerifySequenceOfBST(sequence+i,length-i-1);
 
  return (left&&right);
} 



