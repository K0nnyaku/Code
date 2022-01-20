#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
int T,n,a[500500],l,r;
char qwe[500500];
inline int coutt(){
	for(int i=1;i<=n*2;i++)printf("%c",qwe[i]);//cout<<qwe[i];
	printf("\n");
	return 1;
}
int WC[500500];
inline int dfs2(int now){
	if(now>n)return coutt();
	
	if(WC[a[l]]==n-now+1){
		qwe[n+now]='L';l++;
		if(dfs2(now+1)==1)return 1;
		l--;
	}
	if(WC[a[r]]==n-now+1){
		qwe[n+now]='R';r--;
		if(dfs2(now+1)==1)return 1;
		r++;
	}
	return 0;
}
inline int dfs(int now){
	if(now>n)return dfs2(1);
	if(WC[a[l]]==0){
		WC[a[l]]=now;
		qwe[now]='L';l++;
		if(dfs(now+1)==1)return 1;
		l--;
		WC[a[l]]=0;
	}
	if(WC[a[r]]==0){
		WC[a[r]]=now;
		qwe[now]='R';r--;
		if(dfs(now+1)==1)return 1;
		r++;
		WC[a[r]]=0;
	}
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	for(int i=1;i<=T;i++){
		n=read();
		int nn=2*n;
		l=1;r=nn;
		for(int i=1;i<=nn;i++)a[i]=read(),WC[i]=0;
		if(!dfs(1))printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
