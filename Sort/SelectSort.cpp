#include "SelectSort.h"

static void swap(vector<int>::iterator indexI, vector<int>::iterator indexJ);

void selectSort(vector<int>::iterator begin, vector<int>::iterator end)
{
	
	vector<int>::iterator minIndex;
	vector<int>::iterator indexI = begin;
	for(; indexI != end; ++indexI){
		minIndex = indexI;
		for(vector<int>::iterator indexJ = indexI; indexJ != end; ++indexJ){
			minIndex = *indexJ < *minIndex ? indexJ:minIndex;
		}
		swap(minIndex, indexI);
	}
}

void swap(vector<int>::iterator indexI, vector<int>::iterator indexJ)
{
	int tmp = *indexI;
	*indexI = *indexJ;
	*indexJ = tmp;
}

