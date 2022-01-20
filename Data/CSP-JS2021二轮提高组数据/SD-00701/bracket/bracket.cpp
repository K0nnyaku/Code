#include <bits/stdc++.h>
using namespace std;

const int P= 1e9+7;
int n, k, ans1, l, r, req, ans2, ans3, ans4, stk[100001];
char s[100010], now[100001];

void dfs1(int t, int f,int req) {
//	cout << t << " " << req << " " << f << endl;
//	for(int i = 1;i <= t;i ++) cout << s[i];
//	cout <<endl;
	if(f > k) return ;
	if(req < 0) return;
	if(t == n+1) {
		memset(stk, 0, sizeof stk);l = 0;
		int fl = 0;
		int len = 1;
		for(int i = 1;i <= n;i ++){
			if(s[i] == '*' && s[i-1] == '*') continue;
			if(s[i] == '(' && now[len] == '*' && now[len-1] == ')') now[len] = '(';
			else now[++len] = s[i]; 
		} 
		for(int i = 1;i <= len;i ++) {
			if(now[i] == '(') l ++, stk[l] = 1;
			if(now[i] == ')') l --;
			if(now[i] == '*' && now[i-1] !='*' && stk[l] == 0) return;
			if(now[i] == '*' && now[i-1] != '*' && stk[l]) stk[l] --;
		}
		
		if(!req && now[len] != '*'){
//			for(int i=1;i<=n;i++)cout<<s[i];
//			cout<<endl;
			ans1++;
			ans1 = ans1%P; 
		}
		return ;
	}
	if(s[t] == '(') {
		dfs1(t+1, 0, req +1);
		return ;
	}
	if(s[t] == ')') {
		dfs1(t+1, 0, req - 1); 
		return ;
	} 
	if(s[t] == '*') {
		dfs1(t+1, f+1, req); 
		return ;
	}
	if(s[t] == '?') {
//		cout << "&";
		s[t] = '(';
		dfs1(t+1, 0,req+1);
//		cout << "%";
		s[t] = ')';
		dfs1(t+1, 0,req-1);
		s[t] = '*';
		dfs1(t+1, f+1,req);
		s[t] = '?';
		return;
	}
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin >> n >> k;

	for(int i = 1;i <= n;i ++) {
		cin >> s[i];
	}
	
	dfs1(1, 0,0);
	cout << ans1 << endl;
	
	return 0;
}
