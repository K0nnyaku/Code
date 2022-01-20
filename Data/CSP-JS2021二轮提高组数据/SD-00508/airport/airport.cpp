#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
struct node{
	int st,ed;
	bool operator<(const struct node x)const{
		return st<x.st;
	} 
}gn[1000000],gw[1000000];
set<node>s;
set<node>::iterator it; 
set<node>::iterator itt; 
int sum1[1000000],sum2[1000000],n,m1,m2;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&gn[i].st,&gn[i].ed);
		s.insert((node){gn[i].st,gn[i].ed});
	}
	int cur=0;
	while(s.size()){
		cur++;it=s.begin();
		sum1[cur]=sum1[cur-1]+1;
		node o=*it;int p=o.ed;
		while(1){
			itt=(--s.end());s.erase(s.find(*it));
			node r=*itt;
			if(r.st<p)break;			
			it=s.upper_bound((node){p,0});
			node t=*it;
			p=t.ed;
			sum1[cur]++;
		}
	} 
	//for(int i=1;i<=cur;i++)cout<<sum1[i]<<" ";
	for(int i=cur+1;i<=n;i++)sum1[i]=sum1[i-1];
	s.clear();
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&gw[i].st,&gw[i].ed);
		s.insert((node){gw[i].st,gw[i].ed});
	}
	cur=0;
	while(s.size()){
		cur++;it=s.begin();
		sum2[cur]=sum2[cur-1]+1;
		node o=*it;int p=o.ed;
		while(1){
			itt=(--s.end());s.erase(s.find(*it));
			node r=*itt;
			if(r.st<p)break;			
			it=s.upper_bound((node){p,0});
			node t=*it;
			p=t.ed;
			sum2[cur]++;
		}
	} 
	for(int i=cur+1;i<=n;i++)sum2[i]=sum2[i-1];
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,sum1[i]+sum2[n-i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

