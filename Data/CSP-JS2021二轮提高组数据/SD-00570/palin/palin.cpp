#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
int n,a[200100],cnt;
char b[200100],c[201001];
bool biaoji=0;
string ans,sunti;
bool flagg=0;
bool cmp() {
	for(int i=1; i<=n; i++) {
		if(b[i]!=b[2*n+1-i]) {
			return false;
		}
	}
	return true;
}
void dfs(int pos,int pre,int kai) {
	string s;
	if(pos==2*n+1) {
		if(cmp()) {
			for(int i=1; i<=2*n; i++) {
				s+=c[i];
			}
			ans=min(s,ans);
			flagg=1;
			return ;
		} else return;
	}
	if(pos>2*n+1){
		return ;
	}
	c[++cnt]='L';
	b[cnt]=a[pre];
	dfs(pos+1,pre+1,kai);
	--cnt;
	c[++cnt]='R';
	b[cnt]=a[kai];
	dfs(pos+1,pre,kai-1);
	--cnt;
	//memset(vis,0,sizeof(vis));
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		ans="ZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		sunti="ZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		cin>>n;
		biaoji=0;
		for(int i=1; i<=2*n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			if(a[i]!=a[2*n+1-i]) {
				biaoji=1;
				break;
			}
		}
		if(biaoji==0) {
			for(int i=1; i<=2*n; i++) {
				cout<<"L";
			}
			cout<<endl;
		} else {
			dfs(1,1,2*n);
			if(ans!=sunti) {
				cout<<ans<<endl;
			} else cout<<"-1"<<endl;
		}
	}

    fclose(stdin);
    fclose(stdout);
	return 0;
}
