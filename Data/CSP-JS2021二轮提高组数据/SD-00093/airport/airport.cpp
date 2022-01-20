#include<iostream> 
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
struct ss{
	int l,r,vis=0;	
}p1[100011],p2[100011];
bool cmp(ss a,ss b){
	return a.l<b.l;
}
struct dd{
	int a=0,last=0;	
}sum1[100011],sum2[100021];
int main()
{ 
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&p1[i].l,&p1[i].r);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&p2[i].l,&p2[i].r);
	}
	sort(p1+1,p1+1+m1,cmp);
	sort(p2+1,p2+1+m2,cmp);
	int s=0,ll=0;
	for(int j=1;j<=m1;j++){
		for(int i=1;i<=n;i++) {
			if(p1[j].l>sum1[i].last){
				sum1[i].a++;
				sum1[i].last=p1[j].r;break;
			}
		}
	}
	for(int j=1;j<=m2;j++){
		for(int i=1;i<=n;i++) {
			if(p2[j].l>sum2[i].last){
				sum2[i].a++;
				sum2[i].last=p2[j].r;break;
			}
		}
	}
	for(int i=2;i<=n;i++) sum1[i].a+=sum1[i-1].a;
	for(int i=2;i<=n;i++) sum2[i].a+=sum2[i-1].a;
	int maxx=0,ans;
	//for(int i=1;i<=n;i++) cout<<sum2[i]<<endl;
	for(int i=0;i<=n;i++) {
		sum1[i].a+=sum2[n-i].a;
		if(maxx<sum1[i].a) {
			maxx=sum1[i].a;
		}
	}
	cout<<maxx<<endl;
	return 0;
}
