#include <stdlib.h>
#include <iostream>
#include <vector>
#include "sort/QuickSort.h"
#include "sort/HeapSort.h"

using namespace std;

int main(void)
{
	vector<int> vec {3,4,1,5,6};

//	int i = 0;
//	while(i < 10)
//		cout << random() << endl;

	vector<int>::iterator it;
//	cout << "before sort:" << endl;
//	for(it = vec.begin();it != vec.end(); ++it)
//        cout <<*it << ",";
//	cout <<endl;
	heapSort(vec.begin(), vec.end());
	cout << "after sort:" << endl;
	for(it = vec.begin();it != vec.end(); ++it)
        cout <<*it << ",";
	cout <<endl;
	return 0;
}
