#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int qread(){
	int number=0;int zhengfu=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') zhengfu=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') number=(number<<1)+(number<<3)+(ch^48),ch=getchar();
	return number*zhengfu;
}
int q,n,a[1001000],l,r,b[1001000],d[1001000],t;
void dfs(int dep){
	if(dep-1>n&&b[dep-1]!=b[2*n-dep+2]){
		return;
	}
	if(t==1){
		return;
	}
	if(t==0&&dep==2*n+1){
		for(int i=1;i<=2*n;i++){
			if(d[i]==-1){
				cout<<'L'; 
			}
			if(d[i]==1){
				cout<<'R';
			}
		}
		t=1;
		return;
	}
	d[dep]=-1;
	b[dep]=a[l++];
	dfs(dep+1);
	d[dep]=0;
	l--;
	d[dep]=1;
	b[dep]=a[r--];
	dfs(dep+1);
	d[dep]=0;
	r++;
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	q=qread();
	while(q--){
		t=0;
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		n=qread();
		for(int i=1;i<=2*n;i++){
			a[i]=qread();
		}
		l=1,r=2*n;
		dfs(1);
		if(t) printf("\n");
		else{
			printf("-1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
2
1 1 2 2

2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

LRRLLRRRRL
-1
*/
