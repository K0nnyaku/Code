#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N = 505, mod = 1e9 + 7;

ll n, k, ans;
ll zkh;
char s[N];
void check(){
	
	int l = 0, xing = 0;
	for(int i = 1; i <= n; i++){
		if(xing > k) return;
		if(s[i] == '('){
			xing = 0;
			l++;
		}
		else if(s[i] == ')'){
			if(l > 0){
				l--;
				if(l > 0 && s[i + 1] == '*') return;
				xing = 0;
			}
			else{
				return;
			}
		}
		else if(s[i] == '*'){
			xing++;
		}
	}
	if(l > 0 || xing > 0) return;
	ans = (ans + 1) % mod;	
}
void dfs(ll t){
	
	if(t > n){
		if(zkh == 0) check();
		return;
	}
	
	if(s[t] != '?'){
		if(s[t] == '('){
			zkh++;
		}
		else if(s[t] == ')') zkh--;
		
		dfs(t + 1);
		
		if(s[t] == '(') zkh--;
		else if(s[t] == ')') zkh++;
	}
	else{
		if(zkh > 0){
			s[t] = ')';
			zkh--;
			dfs(t + 1);
			s[t] = '?';
			zkh++;
		}
		
		s[t] = '(';
		zkh++;
		dfs(t + 1);
		s[t] = '?';
		zkh--;
		bool flag = 0;
		for(int i = 1; i < t; i++){
			if(s[i] == '('){
				flag = 1;
				break;
			}
		}
		if(flag || zkh > 0){
			s[t] = '*';
			dfs(t + 1);
			s[t] = '?';
		}
	}
}
int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	dfs(1);
	printf("%lld", ans % mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
