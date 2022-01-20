// 一定要成为C站知名博主啊哈哈哈 
#include<cstdio>
#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;

int a[1000001], n, n2;

struct queueue {
	int head, tail;
	string b, z;
};

queue<queueue> q;

short m[100];

int hw(string s) {
	memset(m, 0, sizeof(m));
	int len = s.length();
	for(int i = 0; n2 > len && i < len; i++){
		if(m[s[i]]++ > 1)return -1;
	}
	int len1 = s.length() - 1, len2 = s.length() / 2;
	for(int i = 0; i < len2; i++) {
		if(s[i] != s[len1 - i])return 0;
	}
	return 1;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);

	int nnnn;
	cin >> nnnn;
	while(nnnn--) {
		cin >> n;
		n2 = 2 * n;
		for(int i = 1; i <= n2; i++)cin >> a[i];
		queueue temp, x;
		char c[2] = {'0', '\0'}, l[2] = {'L', '\0'}, r[2] = {'R', '\0'};
		temp.b = "";
		temp.z = "";
		temp.head = 1;
		temp.tail = n2;
		string test = "";
		q.push(temp);
		bool answered = 0;

		while(!q.empty() && !answered) {
			temp = q.front();
			q.pop();
			if(temp.head <= temp.tail) {
				x = temp;
				c[0] = a[x.head++] + 48;
				x.b = x.b + c;
				x.z += l;
				if(x.b.length() < n2 && hw(x.b) != -1) {
					q.push(x);
				} else {
					if(hw(x.b) == 1) {
						cout << x.z << endl;
						answered = 1;
						break;
					}
				}

				x = temp;
				c[0] = a[x.tail--] + 48;
				x.b = x.b + c;
				x.z += r;
				if(x.b.length() < n2 && hw(x.b) != -1) {
					q.push(x);
				} else {
					if(hw(x.b) == 1) {
						cout << x.z << endl;
						answered = 1;
						break;
					}
				}
			}
		}

		if(!answered)cout << -1 << endl;
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}
