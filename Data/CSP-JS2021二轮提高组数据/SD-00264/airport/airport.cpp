#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,x,y;
inline int read(){
	int s=0,f=1;
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
struct node{
	int t,w,bh;
}a[100005],b[100005];
int px(struct node a1,struct node a2){
	return a1.t<a2.t;
}
int shua[100005],flag[100005],shub[100005],qzha[100005],qzhb[100005],lst,wz,ans;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),x=read(),y=read();
	for(int i=1;i<=x;i++){
		a[i].t=read();
		a[i].w=read(); 
	}
	sort(a+1,a+x+1,px);
	a[1].bh=1;
	shua[1]++;
	lst=1;
	for(int i=2;i<=x;i++){
		wz=1;
		memset(flag,0,sizeof(flag));
		for(int j=1;j<=x;j++){
			if(a[j].t<a[i].t&&a[j].w>a[i].t){
				flag[a[j].bh]=1;
			}
		}
		for(int j=1;j<=x;j++){
			if(flag[j]==0){
				wz=j;
				break;
			}
		}
		a[i].bh=wz;
		shua[wz]++;
		if(wz==1){
			lst=i;
		}
	}
	for(int i=1;i<=n;i++){
		qzha[i]=qzha[i-1]+shua[i];
	}
	for(int i=1;i<=y;i++){
		b[i].t=read();
		b[i].w=read();
	}
	sort(b+1,b+y+1,px);
	b[1].bh=1;
	shub[1]++;
	lst=1;
	for(int i=2;i<=y;i++){
		wz=1;
		memset(flag,0,sizeof(flag));
		for(int j=1;j<=y;j++){
			if(b[j].t<b[i].t&&b[j].w>b[i].t){
				flag[b[j].bh]=1;
			}
		}
		for(int j=1;j<=y;j++){
			if(flag[j]==0){
				wz=j;
				break;
			}
		}
		b[i].bh=wz;
		shub[wz]++;
		if(wz==1){
			lst=i;
		}
	}
	for(int i=1;i<=n;i++){
		qzhb[i]=qzhb[i-1]+shub[i];
	}
	ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,qzha[i]+qzhb[n-i]);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
