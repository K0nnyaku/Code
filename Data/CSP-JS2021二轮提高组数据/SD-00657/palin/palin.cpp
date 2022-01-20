#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[10010],n,t,b[10010],k=0;
long long v=1,ans[100010];
bool huiwen(){
	int ll1=1,rr1=2*n;
	while(ll1!=rr1){
		if(b[ll1]!=rr1)return 0;
	}
	return 1;
}
int l=0,r=0;
long long dfs(int tip){
	if(tip==n){
		if(huiwen()){
			ans[++k]=v;
			return v;
		}
		return 1;
	}
	b[++tip]=a[++l];
	v*=10;
	v++;
	dfs(tip);
	l++;
	v/=10;
	b[tip]=a[--r];
	v*=10;
	dfs(tip);
	tip--;
	v/=10;
	++r;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		scanf("%d",&n);
		n*=2;
		r=n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		long long v1=dfs(1);
		int minn=0x3f3f3f3f;
		for(int i=1;i<=k;i++){
			int x=ans[i];
			minn=min(minn,x);
		}
		
		char s[10010];
		if(k==0)cout<<"-1"<<endl;continue;
		k=0;
		while(v!=1){
			char ss;
			int x=v1%10;
			v1/=10;
			if(x)ss='L';
			else ss='R';
			s[++k]=ss;
		}
		for(int i=k;i>0;i--){
			cout<<s[i];
		}
		cout<<endl;
		memset(b,0,sizeof(b));
		v=1;
		k=0;
		
	}
	//我是傻逼 
	//我是傻逼 
	//我是傻逼 
	return 0;
}
