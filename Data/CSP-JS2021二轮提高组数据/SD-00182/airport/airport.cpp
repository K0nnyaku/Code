#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=2000001;
struct op {
	int ks,js;
}gn[M],gw[M];
bool cmp(op x,op y) {
	return x.ks<y.ks;
}
priority_queue<int,vector<int> ,greater<int> >q;
priority_queue<int,vector<int>,greater<int> >p;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)scanf("%d%d",&gn[i].ks,&gn[i].js); 
	for(int i=1;i<=m2;++i)scanf("%d%d",&gw[i].ks,&gw[i].js); 
	sort(gn+1,gn+m1+1,cmp);
	sort(gw+1,gw+m2+1,cmp);
	int a=0,b=n,ans=-1;
	while(b>=0) {
		int res=0;
		for(int i=1;i<=a;++i){q.push(gn[i].js);} 
		int g=a+1; 
		if(a!=0){
			for(int i=g;i<=m1;++i){
 				if(gn[i].ks<q.top())continue;
				q.pop();
				q.push(gn[i].js);
				g++;
			}
		}
		g--;res+=g;	
		for(int i=1;i<=b;++i){p.push(gw[i].js);}
		int gg=b+1; 
		if(b!=0) {
			for(int i=gg;i<=m2;++i){
				if(gw[i].ks<p.top())continue;
				p.pop();
				p.push(gw[i].js);
				gg++;
			}
		}
		gg--;res+=gg;
		ans=max(res,ans);
		while(!q.empty())q.pop(); 
		while(!p.empty())p.pop(); 
		a++;
		b--;
	}
	printf("%d",ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}


