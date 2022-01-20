#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,ans=0;
char a[100050];
void dfs(int l) {
	if(l==n) {
		int x=0,d=0,las[1050];
		for(int i=0;i<n;i++) {
			if(a[i]=='*')x++;
			else {
				x=0;
				if(a[i]=='(')d++,las[d]=i;
				else {
					if(a[i+1]=='*'&&a[las[d]-1]=='*') {
						return ;
					}
					d--;
				}
			}
			if(x>k)return ;
		}
		if(d==0)ans++;
		return ;
	}
	if(a[l]=='?') {
		if(l==0) a[l]='(',dfs(l+1),a[l]='?';
		else if(l==n-1) {
			a[l]=')';
			dfs(l+1);
			a[l]='?';
		} else {
			a[l]='*';dfs(l+1);
			a[l]='?';
			a[l]=')';dfs(l+1);
			a[l]='?';
			a[l]='(';dfs(l+1);
			a[l]='?';
		}
	}
	else {
		dfs(l+1);
	}
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	dfs(0);
	cout<<ans<<endl;
	return 0;
}

