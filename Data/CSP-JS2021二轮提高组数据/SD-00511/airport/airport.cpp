#include<bits/stdc++.h>
using namespace std;
inline int read(){
	bool f=0;
	int w=0;
	char c;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=1;
		c=getchar();
	}
	while(isdigit(c)){
		w=w*10+c-'0';
		c=getchar();
	}
	if(f)w*=-1;
	return w;
}
inline void write(int x){
	char c[25];
	int f=1;
	if(x<0)x=-x,putchar('-');
	while(x){
		c[f++]=x%10+'0';
		x/=10;
	}
	if(f==1)putchar('0');
	while(f--)putchar(c[f]);
	putchar(' ');
}
const int N=1e6+1;
int n,m1,m2,ans=-1,k1,k;
int a1[N],num[N],a2[N],d[N],fa[N],fb[N];
bool f[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1,j=1;i<=m1;i++)a1[i]=num[j++]=read(),a2[i]=num[j++]=read();
	sort(num+1,num+m1*2+1);
	for(int i=1;i<=m1;i++)d[lower_bound(num+1,num+m1*2+1,a1[i])-num]=1,d[lower_bound(num+1,num+m1*2+1,a2[i])-num]=0;
	for(int i=1;i<=n;i++){
		k=0;
		fa[i]+=fa[i-1];		
		for(int j=1;j<=m1*2;j++){
			if(!f[j]){
				if(k==1&&d[j]==0){
					k=0,f[j]=1;
				}
				if(k==0&&d[j]==1){
					k=1,f[j]=1;
					fa[i]++;
				}
			}
		}
	}
	memset(f,0,sizeof(f));
	for(int i=1,j=1;i<=m2;i++)a1[i]=num[j++]=read(),a2[i]=num[j++]=read();
	sort(num+1,num+m2*2+1);
	for(int i=1;i<=m2;i++)d[lower_bound(num+1,num+m2*2+1,a1[i])-num]=1,d[lower_bound(num+1,num+m2*2+1,a2[i])-num]=0;
	for(int i=1;i<=n;i++){
		k=0;
		fb[i]+=fb[i-1];
		for(int j=1;j<=m2*2;j++){
			if(!f[j]){
				if(k==1&&d[j]==0){
					k=0,f[j]=1;
				}
				if(k==0&&d[j]==1){
					k=1,f[j]=1;
					fb[i]++;
				}
			}
		}
	}
	for(int i=0,j=n;i<=n;i++,j--)ans=max(ans,fa[i]+fb[j]);
	write(ans);
} 

