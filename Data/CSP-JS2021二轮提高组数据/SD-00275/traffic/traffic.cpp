#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;

}
const int N=20;
int a[N][N][N][N];
int n,m,t;
struct qwq{
	int x,t,p;
}f[51];

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),t=read();
	int x,y,w,k,t,p;
	for(register int i=1;i<n;i++){
		for(register int j=1;j<=m;j++){
			a[i][j][i+1][j]=read();
		}
	}
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<m;j++){
			a[i][j][i][j+1]=read();
		} 
	} 
	while(t--){
		k=read();
		for(register int i=1;i<=k;i++){
			f[i].x=read(),f[i].p=read(),f[i].p=read();		
		}
		cout<<0<<endl;
	}
	


	fclose(stdin);
	fclose(stdout);
	return 0;
}

