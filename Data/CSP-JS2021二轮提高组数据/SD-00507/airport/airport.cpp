#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#define ll long long

using namespace std;

const int N=100050;
const int M=100050;

struct node{
    int pla,id,opt;
	bool operator <(const node &a)const{
	    return pla<a.pla;
	}	
}a[N<<1],b[N<<1];

int ans;

priority_queue <int,vector<int>,greater<int> > q;

int n,m1,m2,tot1,tot2;
int cnt1[N],cnt2[N];
int col1[N],col2[N];
int sum1[N],sum2[N];

void setting(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}

void solve1(){
	
	for(int i=1;i<=m1;++i) q.push(i);
	
    for(int i=1;i<=tot1;++i){
	    if(a[i].opt==0){
	       int s=q.top();
		   q.pop();
		   col1[a[i].id]=s;
		   ++cnt1[s];	
		}
		else q.push(col1[a[i].id]);
	}	
	
	while(!q.empty()) q.pop();
	for(int i=1;i<=m1;++i) sum1[i]=sum1[i-1]+cnt1[i]; 
}

void solve2(){
	
	for(int i=1;i<=m2;++i) q.push(i);
	
	for(int i=1;i<=tot2;++i){
		if(b[i].opt==0){
		   int s=q.top();
		   q.pop();
		   col2[b[i].id]=s;
		   ++cnt2[s];	
		}
		else q.push(col2[b[i].id]);
	}
	
	for(int i=1;i<=m2;++i) sum2[i]=sum2[i-1]+cnt2[i];
}

int main(){
	
   setting();
   scanf("%d %d %d",&n,&m1,&m2);
   
   for(int i=1;i<=m1;++i){
   	    int u,v;
		scanf("%d %d",&u,&v);
		a[++tot1].pla=u,a[tot1].opt=0,a[tot1].id=i;
		a[++tot1].pla=v,a[tot1].opt=1,a[tot1].id=i;
   }
   
   for(int i=1;i<=m2;++i){
   	    int u,v;
   	    scanf("%d %d",&u,&v);
   	    b[++tot2].pla=u,b[tot2].opt=0,b[tot2].id=i;
   	    b[++tot2].pla=v,b[tot2].opt=1,b[tot2].id=i;
   }
   
   sort(a+1,a+1+tot1);
   sort(b+1,b+1+tot2);
   
   solve1();
   solve2();
   
   for(int i=0;i<=n;++i) ans=max(ans,sum1[i]+sum2[n-i]);
   printf("%d",ans);
   
   fclose(stdin);
   fclose(stdout);
   return 0;
}

