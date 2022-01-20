#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;
const int N=1e6+10;
int a[N];
int n,t;

bool flag=true;

/*inline void dfs(int i){
	if(i==2*n){
		return;
	}
	else{
		for(int i=1;i<=2*n;++i){
			if()
		}
	} 
}*/

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("plain.in","r",stdin);
	freopen("plain.out","w",stdout);
	t=read();
	for(int i=1;i<=t;++i){
		n=read();
		for(int j=1;j<=2*n;++j){
			a[i]=read();
		}
		for(int j=1;j<=n;++j){
			if(a[j]!=a[2*n-j]){
				flag=false;
			}
		}
		if(flag){
			for(int i=1;i<=2*n;++i){
				printf("L");
			}
		}
		if(flag==false && a[1]==a[2*n]){
			printf("-1");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
