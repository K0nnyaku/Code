#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e7 + 32;  
int t, n, a[maxn];

bool check() {
	for(int i = 1; i <= 2 * n; i++) {
		if(a[i] != a[2 * n + 1 - i]) return false;
	}
	return true;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> n;
		for(int i = 1; i <= 2 * n; i++) {
			cin >> a[i];
		}
		if(check()) {
		for(int i = 1; i <= n; i++) {
			cout << "L";
		}
		for(int i = 1; i <= n; i++) {
			cout << "R";
		}
		cout << endl;
	}
		else{
			cout << -1;
		} 	
	}        
	fclose(stdin);
	fclose(stdout);
	return 0;
}


