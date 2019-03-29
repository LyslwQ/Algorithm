#include <stdlib.h>
#include <climits>
#include <iostream>
#include <vector>
#include "BucketSort.h"

using namespace std;


int bucketSort(IteratorType begin, IteratorType end);

int main(void)
{
	vector<int>  vec { 100, -1,2,10,1};
	int maxGap = bucketSort(vec.begin(), vec.end());
	cout << maxGap << endl;
	return 0;
}




int bucketSort(IteratorType begin, IteratorType end)
{
	if(begin == end || end - begin == 1)
		return 0;
	int min = INT_MAX, max = INT_MIN;
	long length = end - begin;
	for(long i = 0; i < length; ++i){
		if(*(begin+i) > max)
			max = *(begin+i);
		if(*(begin+i) < min)
			min = *(begin+i);
	}

	if(min == max)
		return 0;
	int maxs[length+1], mins[length+1];
	for(long i = 0; i < length+1; ++i){
		maxs[i] = INT_MIN;
		mins[i] = INT_MAX;
	}

	int bucketIndex;
	for(long i = 0; i < length; ++i){
		bucketIndex = (*(begin+i)-min)*length/(max-min);
		if( *(begin+i) > maxs[bucketIndex])
			maxs[bucketIndex] = *(begin+i);
		if(*(begin+i) < mins[bucketIndex])
			mins[bucketIndex] = *(begin+i);

	}

	for(int i = 0; i < length + 1; ++i){
		cout << "maxIndex=" << maxs[i] << endl;
		cout << "minIndex=" << mins[i] << endl;
	}

	int lastMax = maxs[0], result=0;	
	for(int i =1; i < length+1; ++i){
		if(maxs[i] == INT_MIN && mins[i] == INT_MAX)
			continue;
		if(mins[i]-lastMax > result)
			result = mins[i] - lastMax;
		lastMax = maxs[i];
	}
	
	return result;
}

