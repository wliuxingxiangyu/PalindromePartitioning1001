//#include "stdafx.h"//可以 新建 win32控制台 空项目,不用自带的预编译头文件。
#include "iostream"
#include <vector>
#include <string>
#define n 6  //因为定义vector<vector<string> > sub_palins[n]数组大小n必须为常量.

using namespace std;

vector<vector<string> > partition(string s) {
	//const int n = s.size();
	vector< vector<bool> > p(n, vector<bool>(n, false));
	// p[i,j]表示s[i,j]是否回文
	for (int i = n - 1; i >= 0; --i)
		for (int j = i; j < n; ++j)
			p[i][j] = (s[i] == s[j] ) && ((j - i < 2) || p[i + 1][j - 1]);

	vector<vector<string> > sub_palins[n]; // sub_palins数组"元素类型为2维向量":类似int arr[n]
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; ++j){

			if (p[i][j]) {  //s[i]~s[j]间的是回文串
				const string palindrome = s.substr(i, j - i + 1);//s[i]~s[j]间的回文串
				cout << "i=" << i << ",j=" << j << ",palindrome="<< palindrome <<endl;
				if (j + 1 < n) {//j从i到n-1.
					for (auto v : sub_palins[j + 1]) {//v依次指向 2维向量"sub_palins[j + 1]"的1维向量
						v.insert(v.begin(), palindrome);//新来的palindrome插在v的最前面,因为i是从后往前遍历的.
						sub_palins[i].push_back(v);
					}
				}else {  //j + 1= n//即j=n-1.,才加入最终的return结果
					sub_palins[i].push_back(vector<string> { palindrome });
				}
			}

		}
	}
	return sub_palins[0];
}

int main() {
	string s = "abbacc";
	partition(s);
	cout << "输出" << endl;
	return 0;
}