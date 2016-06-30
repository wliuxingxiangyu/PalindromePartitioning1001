//#include "stdafx.h"//���� �½� win32����̨ ����Ŀ,�����Դ���Ԥ����ͷ�ļ���
#include "iostream"
#include <vector>
#include <string>
#define n 6  //��Ϊ����vector<vector<string> > sub_palins[n]�����Сn����Ϊ����.

using namespace std;

vector<vector<string> > partition(string s) {
	//const int n = s.size();
	vector< vector<bool> > p(n, vector<bool>(n, false));
	// p[i,j]��ʾs[i,j]�Ƿ����
	for (int i = n - 1; i >= 0; --i)
		for (int j = i; j < n; ++j)
			p[i][j] = (s[i] == s[j] ) && ((j - i < 2) || p[i + 1][j - 1]);

	vector<vector<string> > sub_palins[n]; // sub_palins����"Ԫ������Ϊ2ά����":����int arr[n]
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; ++j){

			if (p[i][j]) {  //s[i]~s[j]����ǻ��Ĵ�
				const string palindrome = s.substr(i, j - i + 1);//s[i]~s[j]��Ļ��Ĵ�
				cout << "i=" << i << ",j=" << j << ",palindrome="<< palindrome <<endl;
				if (j + 1 < n) {//j��i��n-1.
					for (auto v : sub_palins[j + 1]) {//v����ָ�� 2ά����"sub_palins[j + 1]"��1ά����
						v.insert(v.begin(), palindrome);//������palindrome����v����ǰ��,��Ϊi�ǴӺ���ǰ������.
						sub_palins[i].push_back(v);
					}
				}else {  //j + 1= n//��j=n-1.,�ż������յ�return���
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
	cout << "���" << endl;
	return 0;
}