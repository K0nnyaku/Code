#include<iostream> 
#include<algorithm>  
#include<cstdio> 
#include<cmath> 
#include<queue> 
#define MAXN 500010 
using namespace std; 
struct fre{ 
	int x,y; 
}; 
int cmp(fre a,fre b){ 
	return a.x<b.x; 
} 
int n,m,k; 
fre s1[MAXN],s2[MAXN]; 
int ask(int nu,fre *a,int r){   
	if(nu==0) return 0; 
	else if(r<=nu) return r;  
	priority_queue<int>p; 
	int ans=1; 
	p.push(-a[1].y); 
	for(int i=2;i<=r;i++){ 
		if(a[i].x<-p.top()&&p.size()<nu){ 
			p.push(-a[i].y); 
			ans++; 
		} 
		else if(a[i].x>=-p.top()){ 
			p.pop(); 
			ans++; 
			p.push(-a[i].y); 
		} 
		if(p.size()>nu) break; 
	} 
	return ans; 
} 
int main(){ 
	freopen("airport.in","r",stdin); 
	freopen("airport.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k); 
	if(n==0) { 
		printf("%d\n",0); 
	} 
	for(int i=1;i<=m;i++){ 
		scanf("%d%d",&s1[i].x,&s1[i].y); 
	} 
	for(int i=1;i<=k;i++){ 
		scanf("%d%d",&s2[i].x,&s2[i].y); 
	} 
	sort(s1+1,s1+1+m,cmp); 
	sort(s2+1,s2+1+k,cmp); 
	int dan=0; 
	for(int i=0;i<=n;i++){ 
		int j=n-i; 
		int ansa=ask(i,s1,m); 
		int ansb=ask(j,s2,k); 
		dan=max(dan,ansa+ansb); 
	} 
	printf("%d\n",dan); 
	return 0; 
} 
