#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,l=0,m1,m2,ans=0,sum=0;
int x=0,cnt[100010],xz=0,xd=0;
struct N{
	int u,v;
}a[100010];
struct M{
	int s,f;
}c[100010];
int cmp(N d,N g){
	return d.u<g.u;
}
int ccmp(M h,M j){
	return h.s<j.s;
}
void dfs(int k,int chu,int st){
	    while(k>0){
		  	 ans++;
		  	 if(st==1||chu==1)xz=a[st].v;
		  	 else xz=min(xz,a[st].v);
		  	 st++;
		  	 k--;
		}
		int x=0;
		while(x<m1&&st<=m1){
			if(st==m1){	
				if(xz>=a[m1].u)break;
				else{
				ans++;
				break;
				}
			}
		 	for(int i=st;i<=m1;i++){
				if(a[i].u>xz){
				    x=i;
				break;
		     }
		 }
		if(x!=0)ans++;
		if(chu==1){
			if(x!=0)xd=a[x].v;
			else xd=a[st].v;
		}
		else xd=min(xd,a[x].v);
		if(x!=0)st=x+1;
		else st=m1;
	}
}
void bfs(int k,int chu,int st){
    	while(k>0){
		  	 sum++;
		  	 if(st==1||chu==1)xd=c[st].f;
		  	 else xd=min(xd,c[st].f);
		  	 st++;
		  	 k--;
		}
		int x=0;
		while(x<m2&&st<=m2){
			if(st==m2){
				if(xd>=c[m2].s)break;
				else{			
					sum++;
					break;
				}
			}
		 	for(int i=st;i<=m2;i++){
				if(c[i].s>xd){
				  x=i;
				  break;
				}
			}
		if(x!=0)sum++;
		else st=m2;
		if(chu==1){
			if(x!=0)xd=c[x].f;
		}
		else xd=min(xd,c[x].f);
		if(x!=0)st=x+1;
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].u,&a[i].v);
	sort(a+1,a+m1+1,cmp);
	for(int i=1;i<=m2;i++)scanf("%d%d",&c[i].s,&c[i].f);
	sort(c+1,c+m2+1,ccmp);
	xz=a[1].v;xd=c[1].f;
	for(int i=0;i<=n;i++){
		ans=sum=0;
		if(i==0)ans=0;
		else dfs(i,i,1);
		if(i==n)sum=0;
		else bfs(n-i,n-i,1);
		cnt[++l]=ans+sum;
	}
	sort(cnt+1,cnt+l+1);
    cout<<cnt[l]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
