#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio> 
#include<string>
#include<queue>

using namespace std;

int n, k;
char c[1000], c1[1000];
long long ans, m = 1e9 + 7;
bool check(){
	c1[n - 1] = ')';
	int r1;
	if(c1[0] == '*') return false;
	for(int i = 0; i < n; i++){
		if(c1[i] == ')'){
			r1 = i;
			break;
		}
	}
	int flag = 0;
	for(int i = r1 + 1; i < n; i++){
		if(c1[i] == '(') flag = 1;
		if(c1[i] == ')'){
			if(flag == 0 && i - r1 != 1) return false;
			flag = 0;
			r1 = i;
		}
	}
	return true;
}
void dfs(int id, int ln, int cnt){
	if(ln < 0) return ;
	if(cnt > k) return ;
	if(ln == 1 && id == n - 1 && check()){
		ans = (ans + 1) % m;
		return ;
	}
	if(c[id] == '(') c1[id]='(',dfs(id + 1, ln + 1, 0);
	else if(c[id] == '*') c1[id]='*',dfs(id + 1, ln, cnt + 1);
	else if(c[id] == ')'){
		c1[id]=')',dfs(id + 1, ln - 1, 0);
	}
	else if(c[id] == '?'){
				c1[id]='(';
				dfs(id + 1, ln + 1, 0);
				
					c1[id]=')';
					dfs(id + 1, ln - 1, 0);
				


				c1[id]='*';
				dfs(id + 1, ln, cnt + 1);
			
	}
}
int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k;
	cin >> c;
	dfs(0, 0, 0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
