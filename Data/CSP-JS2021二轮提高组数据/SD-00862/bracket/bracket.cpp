#include <bits/stdc++.h>
using namespace std;
const int mod = 10e9 + 7;
int n = 0;
int k = 0;
string s;
stack<char> st;
int flag = 0;
int ans = 0;
int main() {
	cin >> n >> k >> s;
	for (int i = 0; i < s.size(); i++) {
		st.push(s[i]);
		if (s[i] == '(') {
			flag = 1;
		}
		
	}
	cout << ans % mod;
	return 0;
}
