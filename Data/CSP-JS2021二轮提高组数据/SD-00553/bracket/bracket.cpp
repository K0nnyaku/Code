#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

const int _ = 1e5 + 100;
int n, k, ans = 0; 

char S[_];

bool check(int L, int R) {
//	assert(L < R);
	if(L >= R) return false;
	int tmp = 0, okc = 0, dpc = 0; // if(S[L] != '(') return 0;
	for(int i = L; i <= R; i++) {
		tmp += ( S[i] == '(' ? 1 : (S[i] == ')' ? -1 : 0)  );
		okc += (tmp == 0 && S[i] == ')');
		if(tmp == 0) {
			dpc += (S[i] == '*');
			if(dpc > k) return false;
		} else dpc = 0;
	}
		
	if(tmp != 0) return false;
	
	if(okc != 1) { // AB
		int tmp = 0, last = L;
		for(int i = L; i <= R; i++) {
			if(tmp == 0 && S[i] == '(') last = i;
			tmp += ( S[i] == '(' ? 1 : (S[i] == ')' ? -1 : 0)  ); 
			if(tmp == 0 && S[i] == ')') {
				if(!check(last, i)) return false;
			}
		}
		return true;
	} else {
		if(S[L] == '(' && S[R] == ')') ; else return 0;
		
		//()
		if(R - L == 1) return true;
		bool ok = false;
		// (S) 
		ok = ((R - L - 1) <= k); for(int i = L + 1; i <= R - 1; i++) if(S[i] != '*') { ok = false; break; }
		if(ok) return ok;
		
		//(A)
		if(check(L + 1, R - 1)) return true;
		
		//(SA)
		if(S[L + 1] == '*') {
			int now = L + 1, cnt = 0; while(S[now] == '*' && now <= R - 1) cnt++, now++;
			now += 1;
			if(cnt <= k && check(now, R - 1)) return true;
		}
		
		//(AS)
		if(S[L + 1] == '*') {
			int now = R - 1, cnt = 0; while(S[now] == '*' && now >= L + 1) cnt++, now--;
			now -= 1;
			if(cnt <= k && check(L + 1, now)) return true;
		}
		
		return false;
	}
	
	
}
/*
int now = L, cnt = 0; while(S[now] == '*' && now <= R) cnt++, now++;
if(cnt > k) 
*/

void _check(){ ans += check(1, n); }

void dfs(int now) {
	if(now == n + 1) return _check();
	if(S[now] != '?') dfs(now + 1);
	else {
		S[now] = '('; dfs(now + 1);
		S[now] = ')'; dfs(now + 1);
		S[now] = '*'; dfs(now + 1);
	}
}

int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d%s", &n, &k, S + 1);
	if(n <= 10) dfs(1); else ans = 0;
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}

