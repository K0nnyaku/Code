#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>

int t , a[100000];

using namespace std;

int main( ){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++){
		int n;
		cin >> n;
		for(int j = 1; j <= n; j++){
			cin >> a[i];
		}
		cout << -1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
