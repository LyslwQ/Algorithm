/*
 * note: 区间统一用“左闭右开”表示。
 */

#include <iostream>
#include "MergeSort.h"

#define MAX_SIZE  100000

using namespace std;

static vector<int> help(MAX_SIZE);

void merge(IteratorType begin, IteratorType minIt, IteratorType end);

void mergeSort(IteratorType begin, IteratorType end)
{
	if(begin == end || end - begin == 1)
		return;

	IteratorType minIt = begin + (end - begin)/2;	
	mergeSort(begin, minIt);
	mergeSort(minIt, end);
	merge(begin, minIt, end);
}

void merge(IteratorType begin, IteratorType minIt, IteratorType end)
{
	IteratorType p1 = begin, p2 =  minIt;
	IteratorType it = help.begin();
	while(p1 != minIt && p2 != end)
		*(it++) = *p1 <= *p2 ? *(p1++):*(p2++);
	while(p1 != minIt)
		*(it++) = *(p1++);
	while(p2 != end)
		*(it++) = *(p2++);

	p1 = begin;
	it = help.begin();
	while(p1 != end)
		*(p1++) = *(it++);
}
