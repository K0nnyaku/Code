#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lint long long
#define rint register int
using namespace std;
inline int read(){
	char c;int res=0,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-f;
	while(isdigit(c))res=res*10+c-'0',c=getchar();
	return res*f;
}
const int N=25;
int T,n,a[N],b[N],arr[N],ans[N],ansb[N];
bool flg;
void DFS(int x,int lp,int rp){
	if(x==n*2+1){
		for(rint i=1;i<=n;++i)
			if(b[i]!=b[2*n-i+1])return;
//		for(rint i=1;i<=n*2;++i)
//			cout<<b[i]<<" ";
//		cout<<endl;
		if(!flg){
			for(rint i=1;i<=n*2;++i)
				ans[i]=arr[i],ansb[i]=b[i];
			flg=true;
		}else{
			bool ck;
			for(rint i=1;i<=n*2;++i)
				if(ansb[i]!=b[i]){
					if(b[i]<ansb[i])ck=true;
					else ck=false;
					break; 
				}
			if(ck)
				for(rint i=1;i<=n*2;++i)
					ans[i]=arr[i],ansb[i]=b[i];
		}
		return;
	}
	b[x]=a[lp++];arr[x]=0;
	DFS(x+1,lp,rp);
	--lp;
	b[x]=a[rp--];arr[x]=1;
	DFS(x+1,lp,rp);
	++rp;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		memset(arr,0,sizeof arr);
		for(rint i=1;i<=n*2;++i)
			a[i]=read();
		flg=false;
		DFS(1,1,n*2);
		if(!flg)
			puts("-1");
		else{
			for(rint i=1;i<=2*n;++i)
				if(ans[i])printf("R");
				else printf("L");
			cout<<endl;
		}
	}
	return 0;
}

