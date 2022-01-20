#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
int t,n;
int a[1000010];
bool flag;
inline int read(){
	char c=' ';int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=2*n;++i) a[i]=read();
		for(int i=1;i<=n;++i){
			if(a[i]!=a[2*n-i+1]) flag=1;
		}
		if(!flag){
			for(int i=1;i<=2*n;++i) printf("R");
			std::cout<<"\n";
		}
		else{
			puts("-1");
		}
	}
	return 0;
}
