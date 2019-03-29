#include <iostream>
#include <algorithm>
#include <limits>
#include <memory>

using namespace std;


size_t maxPDSLength(const string& str);
unique_ptr<string> manacherStr(const string& str);


int main(void)
{
	string str("abcba");
	int len = maxPDSLength(str);
	cout << "the max palindrome string length is:" << len << endl;
	return 0;
}

size_t maxPDSLength(const string& str)
{
	if(str.size() == 0)
		return 0;

	unique_ptr<string> strMNC = manacherStr(str);
	int C = -1, R = -1;
	int maxR = numeric_limits<int>::min();
	vector<int> rVec(strMNC->size(), 1);
	//core code
	for(int cur = 0; cur != strMNC->size(); ++cur){
		rVec[cur] = cur < R ? min(R-cur, rVec[2*C - cur]) : 1;
		while(cur+rVec[cur] < strMNC->size() && cur-rVec[cur] > -1){
			if((*strMNC)[cur+rVec[cur]] == (*strMNC)[cur-rVec[cur]])
				++rVec[cur];
			else
				break;
		}	
		if(cur+rVec[cur] > R){
			R = cur+rVec[cur];
			C = cur;
		}
		maxR = max(maxR, rVec[cur]);
	}
	return maxR-1;
}

unique_ptr<string> manacherStr(const string& str)
{
	if(str.size() == 0)
		return nullptr;
		
	string *pStr = new string( 2*str.size() + 1, '\0');
	int i = 0;
	for(int cur = 0; cur != pStr->size(); ++cur)
		(*pStr)[cur] = (cur & 1) == 0 ? '#' : str[i++];

	cout << "the mncStr = " << *pStr << endl;
	return unique_ptr<string>(pStr);
}
