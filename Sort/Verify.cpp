/*
 * note: 对数器--用于验证算法的正确性
 */

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "sort/SelectSort.h"
#include "sort/MergeSort.h"
#include "sort/QuickSort.h"
#include "sort/HeapSort.h"

using namespace std;

vector<int>* generateRandomArray(int maxSize, int maxValue);
vector<int>* copyArray(vector<int>* arr);
bool isEqual(vector<int>* arr01, vector<int>* arr02);


int main(void)
{
	int maxSize = 10000, maxValue = 10000;
	int testTime = 1000, tt = 0;
	while(++tt <= testTime){
		unique_ptr<vector<int>> arr(generateRandomArray(maxSize, maxValue));
		unique_ptr<vector<int>> arr01(copyArray(arr.get()));
		unique_ptr<vector<int>> arr02(copyArray(arr.get()));
		sort(arr01->begin(), arr01->end());
		//selectSort(arr02->begin(), arr02->end());
		//mergeSort(arr02->begin(), arr02->end());
		//quickSort(arr02->begin(), arr02->end());
		heapSort(arr02->begin(), arr02->end());
		if(isEqual(arr01.get(), arr02.get()))
			cout << "test Result: nice!!!" << endl;
		else{
			//打印出错结果
			vector<int>::iterator it = arr01->begin();
			cout << "原数组：" << endl;
			for(;it != arr01->end(); ++it)
				cout << *it << ", ";	
			it = arr02->begin();
			cout << "\n排序后数组" << endl;
			for(;it != arr02->end(); ++it)
				cout << *it << ", ";	
			cout << "\ntest Result: error!!!" << endl; 
		}
	}
	return 0;
}

vector<int>* generateRandomArray(int maxSize, int maxValue)
{
	int length = random() % maxSize;	
	vector<int>* arr = new vector<int>(length);
	for(int i = 0; i < length; ++i)
		(*arr)[i] = random() % maxValue;
	return arr;
}


vector<int>* copyArray(vector<int>* arr)
{
	if( arr == nullptr)
		return nullptr;
	vector<int>* copyArr = new vector<int>(arr->size());
	*copyArr = *arr;
	return copyArr;
}

bool isEqual(vector<int>* arr01, vector<int>* arr02)
{
	return *arr01 == *arr02;
}

