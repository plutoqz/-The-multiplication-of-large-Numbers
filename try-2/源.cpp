#include <iostream>
#include <algorithm>
#include <string>
#include "Seq.h"
using namespace std;


int main()
{
	string zero;//用户输入的式子“xxxxx*xxxxx#”
	string first;
	string second;//两个大数乘数用string存储
	cout << "请输入算式：xxx*xxx#"<<endl;
	cin >> zero;
	for (int i = 0; i < zero.length();i++) {
		int m = zero[i];
		if( m!=35&&m!=42&&!(29<m<40)){
			cout << "error";
			break;
		}
	}
	int k = zero.find('*');
	int t = zero.find('#');
	first = zero.substr(0, k);
	second = zero.substr(k + 1, t - k - 1);

	SeqList<int> seq_first(first.length());
	SeqList<int> seq_second(second.length());
	SeqList<int> seq_result(first.length() + second.length());

	for (int i = 0; i < first.length(); i++) {
		int n = first[first.length()-i-1]-'0';
		seq_first.Insert(i, n);
	}
	for (int i = 0; i < second.length(); i++) {
		int n = second[second.length()-i-1]-'0';
		seq_second.Insert(i, n);
	}
	for (int i = 0; i < first.length() + second.length(); i++) {
		int n = 0;
		seq_result.Insert(i, n);
	}

	for (int n = 1; n <= seq_second.Length(); n++) {
		for (int m = 1; m <= seq_first.Length(); m++) {
			int a, b;
			seq_first.getData(m, a);
			seq_second.getData(n, b);
			int c = a * b;
			int d ;
			seq_result.getData(n + m - 1, d);
			c = d + c;
			seq_result.setData(n + m - 1, c);

		}

	}
	for (int i = 1; i <= seq_result.Length(); i++) {
		int u ;
		seq_result.getData(i, u);
		int v = u % 10;
		seq_result.setData(i, v);
		if (u > 9) {				
			int w;
			seq_result.getData(i + 1, w);
			int t = w + u / 10;
			seq_result.setData(i + 1, t);
			
		}
	}

	int r = 1;
	int j;
	seq_result.getData(seq_result.Length(), j);
	if (j!=0) {
		r = 0;
	}
	for (int i= seq_result.Length()-r;i>0;i--) {
		int n ;
		seq_result.getData(i, n);
		cout << n;
	}
}