#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<functional>
#define inf 0x3f3f3f3f
#define Mod 1000000007
using namespace std;
typedef long long ll;
int rd(){
	int res(0), fl(1);
	char c;c=getchar();
	while(!isdigit(c)){
		if(c=='-') fl=-1; c=getchar();
	}
	while(isdigit(c)){
		res=(res<<3)+(res<<1)+c-'0';
		c=getchar();
	}
	return res*fl;
}
const int maxn=510;
char str[maxn], str2[maxn];
int n, k, top, stk[maxn], cnt, ans;
void check(){
	top=0, cnt=0;
	for(int i(1);i<=n;++i){
		if(str2[i]=='*'){
			cnt++;
			if(cnt > k) return;
			continue;
		}
		cnt=0; 
		if(str2[i]=='(') stk[++top]=i;
		if(str2[i]==')'){
			if(top<=0) return;
			if(str2[stk[top]-1]=='*'&&str2[i+1]=='*') return;
			if(top>0) top--;
		
		}
	}
	if(top>0) return;
//	cout << (str2+1) << endl;
	ans++;
}
void dfs(int dep){
	if(dep>n){
//		cout << (str2+1) << endl;
		check(); return; 
	}
	if(str[dep]!='?') dfs(dep+1);
	else{
		str2[dep]='*'; dfs(dep+1);
		str2[dep]='('; dfs(dep+1);
		str2[dep]=')'; dfs(dep+1);
	}
	return;
}
int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n=rd();k=rd();
	for(int i(1);i<=n;++i){cin>>str[i]; str2[i]=str[i];}
	if(str[1]=='?') str[1]='(', str2[1]='(';
	if(str[n]=='?') str[n]='(', str2[n]=')';
//	cout << (str+1) << endl << (str2+1) << endl; 
	dfs(1);
	printf("%d\n", ans);
	return 0;
}

