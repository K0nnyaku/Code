#include<bits/stdc++.h>
using namespace std;
const int M=1000001;
int n,k,m,sz[M],tot,ans=0;
char s[M],c[M];
int a[M];
int pd(char s[]) {
	int e=0,o=0,u=0;
	for(int i=1;i<=n;++i) {
		if(c[i]=='(')e++;
		if(c[i]==')')o++;  
		if(c[i]=='*')u++;
		//if(c[i]=='('&&c[i+1]==')')return 0;
	}
	if(c[1]==')')return 0;
	if(c[n]=='('||c[n]=='*')return 0;
	if(e!=o)return 0;
	if(u!=k)return 0;
	return 1;
}
void dfs1(int x) {
	if(x==m+1) {
		int v=0;
		for(int i=1;i<=n;++i)c[i]=s[i];
		for(int i=1;i<=n;++i) {
			if(c[i]=='?') {
				if(a[++v]==1)c[i]='*';
				if(a[v]==0)c[i]='('; 
				if(a[v]==2)c[i]=')'; 
			}
		}
		if(pd(c)) {
		ans++;} 
		return ;
	}
	for(int i=0;i<=2;++i) {
		a[x]=i;
		dfs1(x+1);
	}
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) {
		cin>>s[i];
		if(s[i]=='?') {
			m++;
			sz[++tot]=i;
		}
	}
	tot=0;
	dfs1(1);
	cout<<ans-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


