#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
ll T,n,a[500005],b[500005];
string ans,pre;
bool check() {
	for(int i=1;i<=n/2;i++) {
		if(b[i]!=b[n-i+1]) return false;
	}
	return true;
}
void dfs(string s,ll l,ll r) {
	if(ans!=""&&s>ans) return ;
	if(s.size()==n) { 
		if(!check()) return ;
		if(ans=="") ans=s;
		ans=min(ans,s);
		return ; 
	}
	b[s.size()+1]=a[l];
	dfs(s+"L",l+1,r);
	b[s.size()+1]=0;
	b[s.size()+1]=a[r];
	dfs(s+"R",l,r-1);
	b[s.size()+1]=0;
}
int main() {
	freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
	T=read();
	while(T--) {
		ans=pre;
		n=read();
		n=n*2;
		for(int i=1;i<=n;i++) a[i]=read();
		if(n<=100) {
			dfs(pre,1,n);
			if(ans!="")cout<<ans<<'\n';
			else cout<<-1<<'\n';
		}
		else {
			for(int i=1;i<=n;i++) b[i]=a[i];
			if(check()) {
				for(int i=1;i<=n;i++) cout<<'L';
				cout<<'\n';
			}
			else cout<<-1<<'\n';
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
