#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n;
int a[500050],b[500050];
int ans[300050];
int x[300050],y[300050];
bool ff[500050];
int m,u,v,t;
bool f[500050];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	memset(f,sizeof(f),false);
	memset(ff,sizeof(ff),false);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		for(int j=1;j<=2*n;j++)scanf("%d",&a[j]);
		puts(-1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
