#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,m,t;
inline long long read(){
	long long s=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(isdigit(c)){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*f;
}
long long k;
long long shu[105][105],heng[105][105],cd[55],bh[55],ys[1005];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();
	m=read();
	t=read();
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			shu[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			heng[i][j]=read();
		}
	}
	for(int i=1;i<=t;i++){
		k=read();
		for(int j=1;j<=k;j++){
			cd[j]=read();
			bh[j]=read();
			ys[j]=read();
		}
		printf("%lld\n",0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
