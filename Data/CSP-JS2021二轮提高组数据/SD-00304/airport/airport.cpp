#include<bits/stdc++.h>
using namespace std;
const int maxm=100001;
struct planee {
	int a,b;
} na[maxm],fo[maxm];
int n,m1,m2;
bool cmmp(planee aa,planee bb) {
	return aa.a<bb.a;
}
bool cmmp2(planee aa,planee bb)
{
	return aa.b<bb.b;
}
int Nanumb(int m,int rest) {
	
	sort(na+1,na+1+m,cmmp);
	
	int inre=rest;
	if(rest==0) return 0;
	int ans=1,lq[m+1],lqn;
	lq[1]=1;lqn=1;
	int id=1;
	rest-=1;
	for(int i=2; i<=m; i++) {
		if(rest>0) {
			rest--;
			lq[lqn+1]=i;
			lqn++;
			ans++;
			continue;
		}
		int lqs=lqn-inre+1;
	sort(na+lq[lqs],na+lq[lqs]+lq[lqn],cmmp2);
		if(na[lq[lqs]].b<na[i].a) {
			lq[lqn+1]=i;
			lqn++;
			ans++;
		}
	}
	return ans;
}
int Fonumb(int m,int rest) {
	sort(fo+1,fo+1+m,cmmp);
	int inre=rest;
	if(rest==0) return 0;
	int ans=1,lq[m+1],lqn;
	lq[1]=1;lqn=1;
	
	rest-=1;
	for(int i=2; i<=m; i++) {
		if(rest>0) {
			rest--;
			lq[lqn+1]=i;
			lqn++;
			ans++;
			continue;
		}
		int lqs=lqn-inre+1;
	sort(fo+lq[lqs],fo+lq[lqn]+lq[lqs],cmmp2);	
		if(fo[lq[lqs]].b<fo[i].a) {
			lq[lqn+1]=i;
			lqn++;
			ans++;
		}
	}
	return ans;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) {
		cin>>na[i].a>>na[i].b;
	}
	sort(na+1,na+1+m1,cmmp);
	for(int i=1; i<=m2; i++) {
		cin>>fo[i].a>>fo[i].b;
	}
	
	
	
	int ans=0;
	for(int i=0; i<=n; i++) {
		int lqf=n-i;
		ans=max(ans,Nanumb(m1,i)+Fonumb(m2,lqf));
	}
	cout<<ans;
	return 0;
}
