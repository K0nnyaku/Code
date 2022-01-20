#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1000005;
long long T,n,a[maxn],lsh[maxn],to[maxn],cnt;
int now[maxn],tot;
char s[maxn];
bool vis[maxn];
inline long long read(){
	long long s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
bool solve(int x){
	tot=0;
	int flag=0;
	int l=1,r=2*n,xl=x-1,xr=x+1;
	s[2*n]='L';
	if(to[x]==l)l++,s[++tot]='L';
	else r--,s[++tot]='R';
	for(int i=1;i<=2*n;i++)vis[i]=0;
	vis[x]=1;
	while(true){
		flag=0;
		if(vis[l]&&vis[r])return 1;
		if(l<=xl&&!vis[to[xl]]){
			if(to[xl]==l)flag=1,vis[xl]=1,l++,xl--,s[++tot]='L',s[2*n-tot+1]='L';
			else if(to[xl]==r)flag=2;
		}
		if(r>=xr&&!vis[to[xr]]){
			if(to[xr]==l)flag=1,vis[xr]=1,l++,xr++,s[++tot]='L',s[2*n-tot+1]='R';
			else if(to[xr]==r&&!flag)flag=1,vis[xr]=1,r--,xr++,s[++tot]='R',s[2*n-tot+1]='R';
		}
		if(flag==2)vis[xl]=1,r--,xl--,s[++tot]='R',s[2*n-tot+1]='L';
		if(!flag)return 0;
	}
}
void output(){
	for(int i=1;i<=2*n;i++)printf("%c",s[i]);
	printf("\n");
}
void clear(){
	cnt=0;
	for(int i=1;i<=2*n;i++)now[i]=0,to[i]=0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		clear();
		for(int i=1;i<=2*n;i++)a[i]=read(),lsh[++cnt]=a[i];
		sort(lsh+1,lsh+2*n+1);
		cnt=unique(lsh+1,lsh+2*n+1)-lsh-1;
		for(int i=1;i<=2*n;i++){
			a[i]=lower_bound(lsh+1,lsh+cnt+1,a[i])-lsh;
			if(!now[a[i]])now[a[i]]=i;
			else to[i]=now[a[i]],to[now[a[i]]]=i;
		}
		if(solve(to[1]))output();
		else if(solve(to[2*n]))output();
		else printf("-1\n");
	}
	return 0;
} 
