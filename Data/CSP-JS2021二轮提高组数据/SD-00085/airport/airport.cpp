#include<bits/stdc++.h>
#define mp map<int,int>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' or ch>'9'){if(ch=='-') w=-1,ch=getchar();}
	while(ch>='0' and ch<='9'){s=s*10+ch-'0',ch=getchar();}
	return s*w;
}
const int N=1000006;
int n,m1,m2;
mp tail;
mp tail2;
mp vis;
mp vis2;
int length;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=m1;i++){
		int a,b;
		a=read();
		b=read();
		length=max(length,b);
		tail[b]=a;
		vis[a]=1;
		vis[b]=-1;
	}
	for(int i=1;i<=m2;i++){
		int a,b;
		a=read();
		b=read();
		length=max(length,b);
		tail2[b]=a;
		vis2[a]=1;
		vis2[b]=-1;
	}
	long long ans=0;
	for(int i=0;i<=n;i++){
		mp in;
		mp in2;
		long long cnt=0,cnt2=0;
		long long tot=0;
		for(int j=1;j<=length;j++){
			if(vis[j]==-1 and in[tail[j]]) cnt--,in[tail[j]]=0;
			if(vis2[j]==-1 and in2[tail2[j]]) cnt2--,in2[tail2[j]]=0;
			if(cnt<i and cnt+cnt2<n){
				if(vis[j]==1){
					cnt++;
					tot++;
					in[j]=1;
				}
			}
			if(cnt2<n-i and cnt+cnt2<n){
				if(vis2[j]==1){
					cnt2++;
					tot++;
					in2[j]=1;	
				}
			}
		}
		ans=max(ans,tot);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
