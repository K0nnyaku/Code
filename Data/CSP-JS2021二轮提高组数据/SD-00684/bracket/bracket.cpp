#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <vector>

typedef long long int64;

using std::cin;
using std::cout;

int n, k;

std::vector<std::string> strs;

bool isValid(char* str, int len) {
	if (str[0] != '(' || str[len - 1] != ')')
		return false;
	int x = 0;
	for (int i = 0; i < len; ++i) {
		char c = str[i];
		if (c == '*')
			++x;
		else if (x != 0)
			x = 0;
		if (x > k)
			return false;
	}
	
	int ocount = 0, ccount = 0;
	for (int i = 0; i < len; ++i) {
		char c = str[i];
		if (c == '(')
			++ocount;
		if (c == ')')
			++ccount;
	}
	
	if(ocount != ccount)
		return false;
	
	std::stack<char> st;
	bool o = false;
	
	for (int i = 0; i < len; ++i) {
		char c = str[i];
		if ((c == '(' || o) && c != ')') {
			st.push(c);
			o = true;
			continue;
		}
		if ((c == ')' || !o) && c!= '(' && !st.empty()) {
			o = false;
			char ch = st.top();
			st.pop();
			while (ch != '(' && !st.empty()) {
				ch = st.top();
				st.pop();
			}
		}
	}
	return st.empty();
} 

int64 process(char rep, int pos, char* str, int len) {
	if (pos == n - 1) {
		strs.push_back(std::string(str, len));
		return 0;
	}
	if (rep) {
		str[pos] = rep;
	}
	int64 res = 0;
	int x = 0;
	for (int i = 0; i < len; ++i) {
		char c = str[i];
		if (c == '?') {
			if (pos == len - 2) {
				char* newStr = new char[len];
				memcpy(newStr, str, len);
				newStr[len - 1] = ')';
				res += process(0, i, newStr, len);
			} else {
				char* newStr = new char[len];
				memcpy(newStr, str, len);
				res += process('(', i, newStr, len);
				memcpy(newStr, str, len);
				res += process(')', i, newStr, len);
				memcpy(newStr, str, len);
				res += process('*', i, newStr, len);
			}
			return res;
		}

	}
	return res;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.ans", "w", stdout);
	
	cin >> n >> k;
	
	char str[n];
	cin >> str;
	
	process(0, 0, str, n);
	int64 ans = 0; 
	for (auto iter = strs.begin(); iter != strs.end(); iter++) {
		std::string str = *iter;
		const char* cstr = str.c_str();
		char* ccstr = new char[n];
		memcpy(ccstr, cstr, n);
		if (isValid(ccstr, n)) {
			++ans;
			cout << ccstr << std::endl;
		}
	}
	
	cout << ans % 1000000007LL;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
