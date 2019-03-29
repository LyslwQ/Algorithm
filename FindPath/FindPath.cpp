#include "iostream"
#include "vector"

struct binaryTreeNode
{
 int   m_nValue;
 binaryTreeNode*  m_pLeft;
 binaryTreeNode*  m_pRight;
};

void FindPath(binaryTreeNode* proot, int expectedSum);

int main()
{
 binaryTreeNode  pnode;
 binaryTreeNode  pnode1;
 binaryTreeNode  pnode2;
 binaryTreeNode  pnode3;
 binaryTreeNode  pnode4;
 binaryTreeNode* proot  =&pnode;
 binaryTreeNode* pNode1 =&pnode1;
 binaryTreeNode* pNode2 =&pnode2;
 binaryTreeNode* pNode3 =&pnode3;
 binaryTreeNode* pNode4 =&pnode4;
 proot ->m_nValue=1;
 pNode1->m_nValue=2;
 pNode2->m_nValue=5;
 pNode3->m_nValue=3;
 pNode4->m_nValue=4;
 proot ->m_pLeft =pNode1;
 proot ->m_pRight=pNode2;
 pNode1->m_pLeft =pNode3;
 pNode1->m_pRight=pNode4;
 pNode2->m_pLeft =NULL;
 pNode2->m_pRight=NULL;
 pNode3->m_pLeft=pNode3->m_pRight=NULL;
 pNode4->m_pLeft=pNode4->m_pRight=NULL;
 FindPath(proot,6); 
 return 0;
}


void FindPath(binaryTreeNode* proot, int expectedSum,
              std::vector<int>& path,int currentSum);

void FindPath(binaryTreeNode* proot, int expectedSum)
{
  if(proot==NULL)
     return;
  int currentSum=0;
  std::vector<int> path;
  FindPath(proot,expectedSum,path,currentSum);  
}


void FindPath(binaryTreeNode* proot, int expectedSum,
              std::vector<int>& path, int currentSum)
{ 

 path.push_back(proot->m_nValue);
 currentSum += proot->m_nValue;
 if(currentSum==expectedSum&& proot->m_pLeft==NULL&&proot->m_pRight==NULL)
 {
  std::vector<int>::iterator it=path.begin();
  while(it <path.end())
  {
    std::cout<< *it<<'\t';
    it++;
  }
  std::cout<<std::endl;
 }

  if(proot->m_pLeft  !=NULL)
  FindPath(proot->m_pLeft, expectedSum, path, currentSum);
  if(proot->m_pRight !=NULL)
  FindPath(proot->m_pRight,expectedSum, path, currentSum);

  path.pop_back();
}




























