#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
ll re(){
	ll x=0;int f=1;char t=getchar();
	while(t<'0'||t>'9'){if(t=='-')f=-1;t=getchar();}
	while(t>='0'&&t<='9')x=x*10+t-'0',t=getchar();
	return x*f;
}
const int N=1000010;
int n,t,n2;
int a[N],w[N];
int la[N],pda;
void dfs(int x,int l,int r){
	int pdl=0,pdr=0;
	if(x==(n<<1|1)){
		for(int i=1;i<=2*n;i++)printf("%c",la[i]);
		printf("\n");pda=1;
		return;
	}
	if(w[a[l]]&&(x!=(n<<1|1)-w[a[l]]));
	else {
		la[x]='L';
		if(!w[a[l]])w[a[l]]=x,pdl=1;
		dfs(x+1,l+1,r);
		if(pdl)w[a[l]]=0;
		la[x]=0;
	}
	if(pda)return;
	if(w[a[r]]&&(x!=(n<<1|1)-w[a[r]]));
	else {
		la[x]='R';
		if(!w[a[r]])w[a[r]]=x,pdr=1;
		dfs(x+1,l,r-1);
		if(pdr)w[a[r]]=0;
		la[x]=0;
	}
	if(pda)return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=re();
	while(t--){
		n=re();n2=n<<1,pda=0;
		for(int i=1;i<=n2;i++)a[i]=re();
		dfs(1,1,n2);
		if(!pda)printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

