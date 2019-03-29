#include <stdlib.h>
#include <iostream>
#include "QuickSort.h"

using namespace std;

vector<IteratorType> partition(IteratorType begin, IteratorType end);
void swap(IteratorType first, IteratorType second);
void sortProcess(IteratorType begin, IteratorType end);


/*
 * note: 外部传进来的end表示容器的end（），并不是指最后一个元素，
 *       但在该文件的实现中，end表示最后一个元素。
 */
void quickSort(IteratorType begin, IteratorType end)
{
	//IteratorType::value_type val01 = *begin, val02 = *(end-1);
	if(begin == end || end-begin == 1)	//元素个数为0或1
		return;
	sortProcess(begin, end-1);
}

void sortProcess(IteratorType begin, IteratorType end)
{	
	if(begin >= end)	//partition之后的异常边界会在这里过滤
		return;
	vector<IteratorType> p = partition(begin, end);
	sortProcess(begin,  p[0]-1);
	sortProcess(p[1]+1, end);
}

/*
 * note:将操作数分成小于，等于，大于x的三个区域，
 * 		并返回等于区域的边界。
 */
vector<IteratorType> partition(IteratorType begin, IteratorType end)
{
	swap(begin + random()%(end-begin+1), end);//采用随机快排
	IteratorType less = begin-1;
	IteratorType more = end;
	IteratorType curr = begin;
	while(curr != more){
		if(*curr < *end)
			swap(curr++, ++less);	//放进小于区域
		else if(*curr > *end)
			swap(curr, --more);		//放进大于区域
		else
			++curr;					//放进等于区域
	}
	swap(more, end);
	vector<IteratorType> vec { less+1, more-1};
	return vec;
}

void swap(IteratorType first, IteratorType second)
{
	if(first == second)
		return;
	IteratorType::value_type tmp = *first;
	//int tmp = *first;
	*first  = *second;
	*second = tmp;
}
