#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
int u[100010],e[100010],maxn=0,a2[100000001],b2[100000001],ans=0;
bool a1[100000001],b1[10000001];
struct node{
	int x,y;
}a[200010];
struct node1{
	int x,y;
}b[200010];
int cmp(node a,node b){
	return a.x<b.x;
}
int cmp1(node1 a,node1 b){
	return a.x<b.x;
}
int find(int m){
	if(m==0)
		return 0;
	int v=m2,p=0,ans1=0;
	for(int i=1;i<=2*m2;i++){
		if(e[i]==1){
			v--;
			if(p<m){
				ans1++;
				p++;
				b1[b2[b[i].x]]=1;	
			}
			else b1[b2[b[i].x]]=0;	
		}
		if(e[i]==-1&&b1[b[i].x]==1){
			p--;
		}
		if(m-p>=v)
			return ans1+v;	
	}
	return ans1;
}
int find1(int m){
	if(m==0)
		return 0;
	int v=m1,p=0,ans1=0;
	for(int i=1;i<=2*m1;i++){
		if(u[i]==1){
			v--;
			if(p<m){
				ans1++;
				p++;
				a1[a2[a[i].x]]=1;	
			}
			else a1[a2[a[i].x]]=0; 
		}
		if(u[i]==-1&&a1[a[i].x]==1){
			p--;
		}
		if(m-p>=v)
			return ans1+v;
		if(ans+ans1+v<maxn) break;		
	}
	return ans1;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i*2-1].x,&a[i*2].x);
		a[i*2-1].y=1;
		a[i*2].y=-1;
		a2[a[i*2-1].x]=a[i*2].x;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i*2-1].x,&b[i*2].x);
		b[i*2-1].y=1;
		b[i*2].y=-1;
		b2[b[i*2-1].x]=b[i*2].x;
	}
	sort(a+1,a+2*m1+1,cmp);
	sort(b+1,b+2*m2+1,cmp1);
	for(int i=1;i<=2*m1;i++)
		u[i]=a[i].y;
	for(int i=1;i<=2*m2;i++)
		e[i]=b[i].y;
	int m;
	for(int i=0;i<=min(n,m1);i++){
		m=n-i;
		if(m>=m2)
			ans=m2;
		else ans=find(m);
		if(maxn<ans+m1) ans+=find1(i);	 
		maxn=max(maxn,ans);
	}
	printf("%d",maxn);
	return 0;
}
