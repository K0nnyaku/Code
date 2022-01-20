#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100050
int n,m1,m2;
struct plane{ 
	int s,e;
}a[N],b[N];
int ans=0;
bool cmp(plane x,plane y){
	if(x.s>y.s) return false;
	return true;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].s,&a[i].e);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].s,&b[i].e);
	}
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int gn=0;gn<=n;gn++){//Ã¶¾Ù 
		int gy=n-gn;
		int nu=0,yu=0;
		int ans1=m1,ans2=m2;
		if(gn==0) ans1=0;
		if(gy==0) ans2=0;
		priority_queue<int> Q;
		priority_queue<int> q;
		for(int i=1;i<=m1;i++){
			while(Q.size()&&-Q.top()<a[i].s){
				//cout<<i<<"->"<<-Q.top()<<endl;
				Q.pop();
				nu--;
				nu=max(nu,0);
				//cout<<nu<<endl;
			}
			if(nu==gn){
				//cout<<a[i].s<<" "<<a[i].e<<endl;
				ans1--;
				continue;
			}
			else Q.push(-a[i].e);
			nu++;
		}
		//while(Q.size()) Q.pop();
		for(int i=1;i<=m2;i++){
			while(q.size()&&-q.top()<b[i].s){
				//cout<<i<<"->"<<-q.top()<<endl;
				q.pop();
				yu--;
				yu=max(yu,0);
				//cout<<yu<<endl;
			}
			if(yu==gy){
				//cout<<b[i].s<<" "<<b[i].e<<endl;
				ans2--;
				continue;
			}
			else q.push(-b[i].e);
			yu++;
		}
		ans1=max(0,ans1);
		ans2=max(0,ans2);
		//cout<<gn<<" "<<gy<<" "<<ans1<<" "<<ans2<<endl;
		ans=max(ans,ans1+ans2);
	}
	printf("%d\n",ans);
	return 0;
} 

