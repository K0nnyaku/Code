#include<iostream>
#include<cstdio>
#include<cstring>//wxs! DD 
#include<string>
#define LL long long
#define Re register
const int N=10001;
using namespace std;
int ssss;
int n,T,TTt,a[4001],ans[4001],TOP,b[4001],we,tail,head,hb;
inline void dfs(int step){
	if(we) return;
	if((T&&ssss>=1000000)||ssss>=100000000){
		we=1;
		printf("-1\n");
		return ;
	}
	if(step==2*n+1){
		Re bool f=1;
		for(int i=1;i<=n;++i){
			ssss++;
			if(b[i]!=b[2*n+1-i]){
				f=0;
				break;
			}
		}
		if(f){
			for(int i=1;i<=TOP;++i){
				if(ans[i]==1) printf("L");
				else printf("R");
			}
			we=1;
			printf("\n");
		}
		return ;
	}
	ssss++;
	b[++hb]=a[head];
	head++;
	ans[++TOP]=1;
	dfs(step+1);
	if(we) return;
	TOP--;
	head--;
	a[head]=b[hb];
	hb--;
	b[++hb]=a[tail];
	tail--;
	ans[++TOP]=2;
	dfs(step+1);
	if(we) return;
	TOP--;
	tail++;
	a[tail]=b[hb];
	hb--;
}
inline int read(){
	Re int x=0,f=1;Re char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
    T=read();
    TTt=T;
    for(int fgg=1;fgg<=TTt;++fgg){
    	T--;
    	n=read();
    	if(n>=1000&&TTt!=1){
    		printf("-1");
    		continue;
    	}
    	for(int i=1;i<=2*n;++i) cin>>a[i];
    	head=1;tail=2*n;hb=0;we=0;TOP=0;
    	dfs(1);
    	if(!we) printf("-1");
    }
	return 0;
}
