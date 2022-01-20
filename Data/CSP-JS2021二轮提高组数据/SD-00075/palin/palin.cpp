#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=500005;
int T;
int n;
string ans;
int a[2*N],b[N];
bool f;
bool used[N];
int read(){
	int f=1,x=0;
	char c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return f*x;
}
void dfs(int now,string s,int h,int l,int tot){
	if(f==1) return;
	if(now==n+1){
		string k=s;
		for(int i=1;i<=n;i++){
			if(a[h]!=b[i]&&a[l]!=b[i]) return;
			else if(a[h]==b[i]) h++,k+="L";
			else l--,k+="R";
		}
		ans=k;
		f=1;
		return;
	}
	if(!used[a[h]]){
		used[a[h]]=1;
		b[tot]=a[h];
		dfs(now+1,s+"L",h+1,l,tot-1);
		used[a[h]]=0;
	}
	if(!used[a[l]]){
		used[a[l]]=1;
		b[tot]=a[l];
		dfs(now+1,s+"R",h,l-1,tot-1);
		used[a[l]]=0;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		f=0;
		memset(b,0,sizeof(b));
		memset(used,0,sizeof(used));
		n=read();
		for(int i=1;i<=n*2;i++) a[i]=read();
		dfs(1,"",1,2*n,n);
		if(f) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
