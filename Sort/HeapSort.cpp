#include <iostream>
#include "HeapSort.h"

using namespace std;
/*
 *  note: 外部传进来的end表示容器的end（），并不是指最后一个元素，
 *        但在该文件的实现中，end表示最后一个元素。
 */

void heapInsert(IteratorType begin, int index);
void heapAdjust(IteratorType begin, int root, int tail);
void swap(IteratorType fisrt, IteratorType second);

void heapSort(IteratorType begin, IteratorType end)
{
	if(begin == end || begin == end-1) //操作元素个数为0或1
		return;

	//构建大根堆
	int tail = end-begin -1; //堆最后一个元素的坐标
	for(int index = 0; index <= tail; ++index)
		heapInsert(begin, index);

	//依次从大根堆取出堆顶，放到堆数组的后面，缩小堆的大小，
	//最后得到排好序的升序数组。
	while(0 != tail){
		swap(begin, begin + tail);
		heapAdjust(begin, 0, --tail);
	}
}	

void heapInsert(IteratorType begin, int index)
{
	int father = (index-1)/2;
	while(*(begin+index) > *(begin+father)){
		swap(begin+index, begin+father);
		index  = father;
		father = (index-1)/2;
	}
}

void heapAdjust(IteratorType begin, int root, int tail)
{
	int index = root;
	int bigger;
	int left = index*2+1;
	//一直循环，直到叶子节点。
	while(left <=  tail){
		bigger = (left+1)<=tail && *(begin+left+1) > *(begin+left) ? (left+1):left;
	
    	if(*(begin+index) < *(begin+bigger)){
			swap(begin+index, begin+bigger);
			index = bigger;
			left  = index *2 +1;
		}
		else
			break;
	}
}

void swap(IteratorType fisrt, IteratorType second)
{
	if(fisrt == second)
		return;
	IteratorType::value_type tmp = *fisrt;
	*fisrt  = *second;
	*second = tmp;
}
