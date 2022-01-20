#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int n=1,k=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-') n=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		k=k*10+ch-'0';
		ch=getchar();
	}
	return n*k;
}
const int MAXN=1e6+50;
int t,n,l,r;
int a[MAXN];
bool vis[MAXN];
int works[MAXN];
bool judge=false;
int dfs(int l,int r,int nowl,int nowr) {
	int rr1,ll1,rr2,ll2;
	if(r!=2*n) rr1=r+1;else rr1=1;
	if(l!=1) ll1=l-1; else ll1=2*n;
	if(nowl!=1) ll2=nowl-1;else ll2=2*n;
	if(nowr!=2*n) rr2=nowr+1;else rr2=1;
	if((a[ll1]==a[ll2]&&a[rr1]==a[rr2]))
	{
		if(a[ll1]<a[rr1]&&!vis[ll1]) 
		{
		vis[ll1]=true,dfs(ll1,r,ll2,nowr);	
		if(judge);
		}
	}
	else if((a[ll1]==a[rr2]&&a[rr1]==a[ll2]))
	{
		
	}
	else if((a[ll1]==a[ll2]&&a[rr1]!=a[rr2]))
	{
		
	}
	else if((a[ll1]==a[rr2]&&a[rr1]!=a[ll2]))
	{
		
	}
	else judge=false;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--) {
		n=read();
		for(int i=1; i<=2*n; i++) {
			a[i]=read(),a[2*n+i]=a[i];
		}
		if(a[1]==a[n*2]) {
			for(int i=1; i<=n; i++) {
				if(a[i]!=a[2*n+1-i]) {
					judge=false;
					break;
				}
			}
			if(judge==true) for(int i=1; i<=2*n; i++) printf("L");
			cout<<endl;
			continue;
		}
		for(int i=2; i<=2*n; i++) {
			if(a[i]==a[1]) l=i;
		}
		for(int i=1; i<2*n; i++) {
			if(a[i]==a[2*n]) r=i;
		}
		dfs(1,1,l,l);
		dfs(2*n,2*n,r,r);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

