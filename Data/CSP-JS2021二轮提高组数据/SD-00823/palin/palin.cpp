#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int read(){
	int a=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')a=a*10+c-'0',c=getchar();
	return a;
}
int n,ans;
int a[50001];
int b[50001];
int c[50001];
int d[50001];
void dfs(int t,int l,int r){
	if(t==2*n+1){
		int f=0;
		for(int i=1;i<t;i++)
		if(d[i]<c[i]){f=1;break;}
		if(!f){
			for(int i=1;i<n*2;i++){
				d[i]=c[i];
			}
			ans=1;
		}
		return ;
	}
	if(t>n){
		if(a[l]==b[2*n+1-t]){
			b[t]=a[l];
			c[t]=2;
		    dfs(t+1,l+1,r);
		}
		if(a[r]==b[2*n+1-t]){
			b[t]=a[r];
			c[t]=1;
			dfs(t+1,l,r-1);
		}
	}
	else {
		b[t]=a[l];
		c[t]=2;
		dfs(t+1,l+1,r);
		b[t]=a[r];
		c[t]=1;
		dfs(t+1,l,r-1);
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=2*n;i++){
			a[i]=read();
		}
		for(int i=1;i<=2*n;i++)d[i]=3;
		dfs(1,1,2*n);
		int f=0;
		for(int i=1;i<=n;i++)if(d[i]==3)ans=0;
		if(ans==0)printf("-1\n");
		else {
			for(int i=1;i<2*n;i++){
				if(d[i]==1)printf("%c",'R');
				else printf("%c",'L');
			}
			printf("L");
			printf("\n");
		}
	}
	
	return 0;
}

