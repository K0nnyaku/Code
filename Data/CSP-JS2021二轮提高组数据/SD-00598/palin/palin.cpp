#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#define MAXSTR "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR"

using namespace std;

int a[102];
int b[102];
int n;

int pp(int x) {
	return 2 * n - 1 - x;
}

bool pl(int* s) {
	int flag = true;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[pp(i)]) {
			flag = false;
		}
	}
	return flag;
}

int get(int num, int x) {
	return (num >> x) % 2;
}

long long pow(int x) {
	return (long long)2 << (x - 1);
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		
		cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			cin >> a[i];
		}
		
		if (pl(a)) {
			for (int i = 0; i < 2 * n; i++) {
				putchar('L');
			}
			cout << endl;
			continue;
		}
		
		if (n >= 20) {
			cout << -1 << endl;
			continue;
		}
		
		bool f = false;
		string minans = MAXSTR;
		string ans;
		
		long long t_ = pow(2 * n);
		for (long long num = 0; num < t_; num++) {
			
			memset (b, 0, sizeof(b));
			int l, x1, x2;
			l = 0;
			x1 = 0;
			x2 = 2 * n - 1;
			for (int i = 0; i < 2 * n; i++) {
				int t = get(num, i);
				if (t == 0) {
					b[l] = a[x1];
					x1++;
				}
				else {
					b[l] = a[x2];
					x2--;
				}
				l++;
			}
			/*
			cout << num << " ";
			for (int i = 0; i < 2 * n; i++) {
				cout << b[i] << " ";
			}
			cout << endl;
			*/
			if (pl(b)) {
				ans.clear();
				f = true;
				for (int i = 0; i < 2 * n; i++) {
					int t = get(num, i);
					if (t == 0) {
						ans += 'L';
					}
					else {
						ans += 'R';
					}
				}
				if (ans < minans) {
					minans = ans;
				}
			}
		}
		if (f) {
			cout << minans << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
