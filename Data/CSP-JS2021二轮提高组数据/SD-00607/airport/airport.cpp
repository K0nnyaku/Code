#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e5+10;
inline int read(){
	int s=0,w=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int n,m1,m2,h[maxn][2],ans=0,num[maxn];
int ans_p,ans_q;
struct node{
	int a,b;
}f1[maxn],f2[maxn];
bool cmp(node a,node b){
	if(a.a==b.a)return a.b<b.b;
	return a.a<b.a;
}
int work(int x,int y){
	int ans=0,cnt=0;
	for(int i=1;i<=x;i++)h[i][1]=h[i][0]=0;
	if(x!=0){
		for(int i=1;i<=m1;i++){
			if(cnt<x)
				h[++cnt][0]=f1[i].a,h[cnt][1]=f1[i].b,ans++;
			else{
				for(int j=1;j<=x;j++){
					if(h[j][1]<=f1[i].a){
						h[j][0]=f1[i].a,h[j][1]=f1[i].b,ans++;
						break;
					}
						
				}
			}
		}
	}
	cnt=0;
	for(int i=1;i<=y;i++)h[i][1]=0,h[i][0]=0;
	if(y!=0)
	for(int i=1;i<=m2;i++){
		if(cnt<y)
			h[++cnt][0]=f2[i].a,h[cnt][1]=f2[i].b,ans++;
		else{
			for(int j=1;j<=y;j++){
				if(h[j][1]<=f2[i].a){
					h[j][0]=f2[i].a,h[j][1]=f2[i].b,ans++;
					break;
				}
					
			}
		}
	}
	return ans;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
		f1[i].a=read(),f1[i].b=read();
	for(int i=1;i<=m2;i++)
		f2[i].a=read(),f2[i].b=read();
	sort(f1+1,f1+m1+1,cmp);
	sort(f2+1,f2+m2+1,cmp);
	for(int p=0;p<=n;p++){
		int q=n-p;
		int tmp=work(p,q);
		if(ans<tmp){
			ans=tmp;
			ans_p=p,ans_q=q;
		} 
	}
	printf("%d\n",ans);
	return 0;
}
