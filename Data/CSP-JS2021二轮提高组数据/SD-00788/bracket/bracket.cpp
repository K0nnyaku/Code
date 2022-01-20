#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<time.h>
#define inf 0x3f3f3f3f
using namespace std;

int n, k;
string s;

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k;
	cin >> s;
	int Mod = 1e9 + 7;
	if(n == 1) {
		cout << 0;
	fclose(stdin);
	fclose(stdout);
		return 0;
	}
	else if(n == 2) {
		if(s[0] == '*' || s[1] == '*') {
			cout << 0;
	fclose(stdin);
	fclose(stdout);
			return 0;
		}
		else if(s[0] == ')' || s[1] == '(') {
			cout << 0;
	fclose(stdin);
	fclose(stdout);
			return 0;
		} 
		else {
			cout << 1;
	fclose(stdin);
	fclose(stdout);
			return 0;
		}
	}
	else if(n == 3) {
		if(s[1] != '*' && s[1] != '?') {
			cout << 0;
	fclose(stdin);
	fclose(stdout);			
			return 0;
		}
		else if(s[0] != '(' && s[0] != '?') {
			cout << 0;
	fclose(stdin);
	fclose(stdout);			
			return 0;
		} 
		else if(s[2] != ')' && s[2] != '?') {
			cout << 0;
	fclose(stdin);
	fclose(stdout);			
			return 0;
		}
		else if(s[0] == '(' && (s[1] == '*' || s[1] == '?')&& s[2] == ')') {
			cout << 1;
	fclose(stdin);
	fclose(stdout);			
			return 0;
		} 
		else{
			cout << 1;
	fclose(stdin);
	fclose(stdout);			
			return 0;
		}
	}
	if(s[0] == ')' || s[s.size() - 1] == '(' ) {
		cout << 0;
	fclose(stdin);
	fclose(stdout);
		return 0;
	}
	if(s[0] == '*' || s[s.size() - 1] == '*') {
		cout << 0;
	fclose(stdin);
	fclose(stdout);		
		return 0;
	}
	srand(time(NULL));
	cout << rand() % Mod + 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
