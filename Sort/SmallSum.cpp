/*
 * note: @1.求最小和：对于数组中的每一个数，将其左边比该数小的数累计，
 *       得到最小和。
 *       @2.解法：求数组中一个数左边比该数小的数并累加，
 *                问题可转换为求右边比该数大的数的个数（表明该会被累加的次数），
 *                将个数乘于该数，最后累加。
 *       @3.该解法可通过归并排序，在归并的过程，即可知道右边比该数大的数的个数。
 *          最终时间复杂度可由master公式获得：N*logN.
 */

#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 10000; //定义辅助容器的大小

int  smallSum(vector<int>& array);
int  sortMerge(vector<int>& array, int left, int right);
int  merge(vector<int>& arrary, int left, int min, int right);

int main(void)
{
	vector<int> array {1,2,3,0,4,0,5};
	int sum = smallSum(array);
	cout << "the smallSum is " << sum << endl;
	for(int i = 0; i < array.size(); ++i)
		cout << array[i] << " ";
	cout << endl;
	return 0;
}

int smallSum(vector<int>& array)
{
	if(array.size() < 2)
		return 0;
	
	return sortMerge(array, 0, array.size()-1);
}

int sortMerge(vector<int>& array, int left, int right)
{
	if(left == right)
		return 0;
	
	int minIndex = left + ((right-left)>>1);
	return sortMerge(array, left, minIndex)
	       +sortMerge(array, minIndex+1, right)
	       +merge(array, left, minIndex, right);
}

int merge(vector<int>& array, int left, int min, int right)
{
	int p1 = left, p2=min+1;
	int sum = 0;
	static vector<int> help(MAX_SIZE);
	int i = 0;
	while(p1 != min+1 && p2 != right+1){
		sum += array[p1] < array[p2] ? array[p1]*(right - p2 + 1):0;
		help[i++] = array[p1] < array[p2] ? array[p1++]:array[p2++];
	}	

	while(p1 != min+1)
		help[i++] = array[p1++];

	while(p2 != right+1)
		help[i++] = array[p2++];

	p1 = 0;
	p2 = left;
	while(p2 != right+1)
		array[p2++] = help[p1++];
	
	return sum;
}





