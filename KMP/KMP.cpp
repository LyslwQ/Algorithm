#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int>*  getNextArray(const string& str2);
bool findSubStr(const string& str1, const string& str2);

int main()
{
	string str1("");
	string str2("ababc");

	if(findSubStr(str1, str2))
		cout << "find it" << endl;
	else
		cout << "can't find it" << endl;

//	for(int i = 0; i < p->size(); ++i)
//		cout << (*p)[i] << endl;
//	return 0;
}

bool findSubStr(const string& str1, const string& str2)
{
	vector<int>* p = getNextArray(str2);
	
	int str1Index = 0, str2Index = 0;
	while(str1Index < str1.size() && str2Index < str2.size()){
		if(str1[str1Index] == str2[str2Index]){
			++str1Index;
			++str2Index;
		}
		else if(str2Index == 0){
			++str1Index;
		} 
		else{
			str2Index = (*p)[str2Index];
		}
	}
	delete p;
	return str2Index >= str2.size() ? true : false;
}


vector<int>* getNextArray(const string& str2)
{
	if(str2.size() == 1)
		return new vector<int> {-1};

	vector<int>* next = new vector<int>(str2.size(), -1);
	int cn  = 0;
	int cur = 2;
	(*next)[0]   = -1;
	(*next)[1]   = 0;

	while(cur < str2.size()){
		if(str2[cur-1] == str2[cn])
			(*next)[cur++] = ++cn;
		else{
			if((*next)[cn] != -1)
				cn = (*next)[cn];
			else{
				(*next)[cur++] = 0;
			}
		}
	}
	return next;
}
