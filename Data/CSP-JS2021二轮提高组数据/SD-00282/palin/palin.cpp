#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

#define INF 0x3f3f3f3f
#define ll long long
#define maxn 500005

using namespace std;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int T,n,a[maxn],b[maxn];

string ans;

bool flag;

inline void dfs(int l,int r,string now,int len) 
{
	if(flag) return ;
	if(len>n&&b[len]!=b[n*2-len+1]) return ;
	if(l>r){
		flag=true;
		ans=now;
		return ;
	}
	b[len+1]=a[l];
	dfs(l+1,r,now+"L",len+1);
	b[len+1]=a[r];
	dfs(l,r-1,now+"R",len+1);
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
//	freopen("palin2.in","r",stdin);
//	freopen("palin2.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		ans="-1";
		flag=false;
		for(int i=1;i<=n*2;i++) a[i]=read();
		dfs(1,n*2,"",0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/ 
