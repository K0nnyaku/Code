#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
long long ans = 0;
string str;
int n, k;
int Find[510];
bool check() {
	int l = 1, r = n, las = k;
	int num = 0;
	for(int i = 1; i <= n; ++i) {
		if(str[i] == '(') {
			las = k;
			++num;
			continue;
		}
		if(str[i] == ')') {
			--num;
			if(num < 0) {
				return false;
			}
			las = k;
			continue;
		}
		if(str[i] == '*') {
			--las;
		}
		if(las < 0) {
			return false;
		}
	}
	if(num == 0) {
		return true;
	}
	return false;
}
void work(int i) {
	if(Find[i + 1] == -1) {
		if(check()) {
			++ans;
		}
		return;
	}
	str[i] = '*';
	work(Find[i + 1]);
	str[i] = '(';
	work(Find[i + 1]);
	str[i] = ')';
	work(Find[i + 1]);
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k;
	cin >> str;
	str = '0' + str;
	if((str[1] == ')' || str[n] == '(') || (str[1] == '*' || str[n] == '*')) {
		cout << 0 << endl;
		return 0;
	}
	str[1] = '(';
	str[n] = ')';
	memset(Find, -1, sizeof Find);
	for(int i = n - 1; i > 0; --i) {
		if(str[i] == '?') {
			Find[i] = i;
		} else {
			Find[i] = Find[i + 1];
		}
	}
	if(Find[2] == -1) {
		cout << check() << endl;
	}
	work(Find[2]);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
