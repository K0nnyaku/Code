#include<iostream>
#include<cstdio>
#include<cstring>
#define M 2001
using namespace std;
int T,n,w;
string a[M],b[M];
char c[M];
inline void dfs(int h,int t,int cntt){
	if(cntt>2*n){
		w=1;
		return;
	}
	if(w)return;
	if(cntt>n){
		if(b[2*n-cntt+1]==a[h]){
			b[cntt]=a[h];
			c[cntt]='L';
			dfs(h+1,t,cntt+1);
			b[cntt]="";
		}
		if(w)return;
		if(b[2*n-cntt+1]==a[t]){
			b[cntt]=a[t];
			c[cntt]='R';
			dfs(h,t-1,cntt+1);
			b[cntt]="";
		}
		else return;
	}
	if(cntt<=n){
		if(a[h]>a[t]){
			b[cntt]=a[t];
			c[cntt]='R';
			dfs(h,t-1,cntt+1);
			if(w)return;
			c[cntt]='L';
			b[cntt]=a[h];
			dfs(h+1,t,cntt+1);
			if(w)return;
			b[cntt]="";
		}
		else{
			b[cntt]=a[h];
			c[cntt]='L';
			dfs(h+1,t,cntt+1);
			if(w)return;
			b[cntt]="";
			b[cntt]=a[t];
			c[cntt]='R';
			dfs(h,t-1,cntt+1);
			if(w)return;
			b[cntt]="";
		}
	}
	
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)cin>>a[i];
		w=0;
		dfs(1,2*n,1);
		if(w==1){
			for(int j=1;j<=2*n;j++)cout<<c[j];
			printf("\n");
//			for(int j=1;j<=2*n;j++)cout<<b[j]<<" ";
		}
		else printf("-1\n");
	}
	
	fclose(stdin);
	fclose(stdout);
}
