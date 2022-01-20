#include<bits/stdc++.h>
using namespace std;

#define IOR(x, y, z) for(int x = y; x < z; x++)
#define LOR(x, y, z) for(int x = y; x > z; x--)
#define EOR(x, y) for(int x = Head[y]; x; x = E[x].next)

struct FastIN {
	template<typename T>
	FastIN& operator>>(T& x) {
		char c, l;
		for(c = 0; !isdigit(c); c = getchar()) l = c;
		for(x = 0; isdigit(c); c = getchar()) x = x * 10 + c - '0';
		if(l == '-') x = -x;
		return *this;
	}
} IN;

const int _N = 5e2 + 10;

long long n, k, ans;
char S[_N];

bool Check();
void Force(char* S, int pos);

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);

	IN >> n >> k;
	scanf("%s", S);

	Force(S, 0);
	
	cout << ans << "\n";
	
	return 0;
} 

void Force(char* S, int pos) {
	if(pos == n) {
		ans += Check();
		return ;
	} 
	
	if(S[pos] != '?') Force(S, pos+1);
	else {
		S[pos] = '(';
		Force(S, pos+1);
		S[pos] = '*';
		Force(S, pos+1);
		S[pos] = ')';
		Force(S, pos+1);
		S[pos] = '?';
	}
}

bool Check() {
	int pos = 0, cnt = 0;
	stack<char> St;
	St.push(S[pos++]);
	while(pos < n) {
		if(S[pos] == '(') St.push('('), cnt = 0;
		else 
		if(S[pos] == '*') 
			if(++cnt > k) return false;
			else St.push('*');
		else {
			bool flag = 0, fflag = 0, ffflag = 0;
			while(!St.empty() && St.top() != '(') {
				fflag |= St.top() == '|';
				ffflag |= (St.top() == '*' && !fflag);
				flag |= (fflag && St.top() == '*');
				St.pop();
			}
			if(flag && ffflag) return false;
			if(St.empty()) return false;
			St.pop(); 
			St.push('|');
			cnt = 0;
		}
		pos++; 
	}
	
	if(St.top() != '|') return false;
	
	while(St.size() > 1) {
		St.pop();
		if(St.top() == '(' || St.top() == ')') return false;
	}
	
	return St.empty() || St.top() == '|';

}
/*
Case 1:
7 3
(*??*??
*/

/*
Case 2:
10 2
???(*??(?) 
*/























