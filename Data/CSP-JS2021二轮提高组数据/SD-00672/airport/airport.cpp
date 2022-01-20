#include<bits/stdc++.h>
const int M=100000001;
using namespace std;
long long maxx=-1,tree[100000005],tree2[100000005],n,m1,m2;
struct node{
	int xxx,yyy;
}a1[100005],a2[100005];
void build(long long x,long long y){
	long long res=0;
	while(x<=M){
		tree[x]+=y;
		x+=x&-x;
	}
}
void build2(long long x,long long y){
	long long res=0;
	while(x<=M){
		tree2[x]+=y;
		x+=x&-x;
	}
}
long long sum (long long x){
	long long res=0;
	while(x!=0){
		res+=tree[x];
		x-=x&-x;
	}
	return res;
}
long long sum2 (long long x){
	long long res=0;
	while(x!=0){
		res+=tree2[x];
		x-=x&-x;
	}
	return res;
}
long long read(){
	int k=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')k=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return k*x;
}
int cmp(node xxxx,node yyyy){
	return xxxx.xxx<yyyy.xxx; 
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=m1;i++){
		a1[i].xxx=read();
		a1[i].yyy=read();
	}
	sort(a1+1,a1+m1+1,cmp);
	if(a1[m1].yyy>maxx)maxx=a1[m1].yyy;
	
	for(int i=1;i<=m1;i++){
		build(a1[i].xxx,1);
		build(a1[i].yyy+1,-1);
	}
	for(int i=1;i<=m2;i++){
		a2[i].xxx=read();
		a2[i].yyy=read();
	}
	sort(a2+1,a2+m2+1,cmp);
	if(a2[m2].yyy>maxx)maxx=a2[m2].yyy;
	for(int i=1;i<=m2;i++){
		build2(a2[i].xxx,1);
		build2(a2[i].yyy+1,-1);
	}
	int k1=0,k2=0,a=1,b=1,ans1=0,ans2=0,ans=0,c1[100005],c2[100005]; 
	for(int i=0;i<=n;i++){
		k1=0,k2=0,a=1,b=1,ans1=0,ans2=0;
		int x=i,y=n-i;
		for(int j=a1[1].xxx;j<=a1[m1].xxx;j=a1[a].xxx){
			a++;
			int d=sum(j);
			if(d<=i){
				ans1++;
			}
			else {
				c1[++k1]=a-1;
				build(j,-1);
				build(a1[a-1].yyy+1,1);
			}
			
			if(j==a1[m1].xxx)break;
		}
		for(int j=a2[b].xxx;j<=a2[m2].xxx;j=a2[b].xxx){
			b++;
			int d=sum2(j);
			if(d<=y){
				ans2++;
			}
			else {
				c2[++k2]=b-1;
				build2(j,-1);
				build2(a2[b-1].yyy+1,1);
			}
			if(j==a2[m2].xxx)break;
		}
		ans=max(ans,ans1+ans2);
		for(int j=1;j<=k1;j++){
		
			build(a1[c1[j]].xxx,1);
			build(a1[c1[j]].yyy+1,-1);
		}
		for(int j=1;j<=k2;j++){
			build2(a2[c2[j]].xxx,1);
			build2(a2[c2[j]].yyy+1,-1);
		}
	}
	cout<<ans<<" ";
}
