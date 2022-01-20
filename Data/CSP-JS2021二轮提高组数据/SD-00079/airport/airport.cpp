#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
struct plane{ll in,out,time};
plane nat[114514],inter[114514];
ll nuse[114514],iuse[114514];
ll n,pn,pi,t1,t2,Max=-1;
bool comp(plane a,plane b){
	return a.time<b.time;
	/*if(a.in<b.in)return true;
	else if(a.in>b.in)return false;
	else return a.time>b.time;*/
	//return a.floor<b.floor;
}
ll find(plane a){
	if(a.)
	
}
int main(){
	freopen("airport.in","r",stdin);
	//freopen("airport.out","w",stdout);
	scanf("%lld %lld %lld",&n,&pn,&pi);
	
	for(ll i=1;i<=pn;i++){
		scanf("%lld %lld",&t1,t2);
		nat[i].in=t1;
		nat[i].out=t2;
		nat[i].time=t2-t1;
	}
	sort(nat+1,nat+pn+1,comp);
	
	
	for(ll i=1;i<=pi;i++){
		scanf("%lld %lld",&t1,t2);
		inter[i].in=t1;
		inter[i].out=t2;
		inter[i].time=t2-t1;
	}
	sort(inter+1,inter+pi+1,comp);

	for(ll i=0;i<=n;i++){
		ll nn=i,ni=n-i;
		for(int j=1;j<=nn;j++){
			
		}
		for(int j=1;j<=ni;j++){
			
		}
		
	}
	printf("%lld",Max);
	
	fclose(stdin);
	//fclose(stdout);
	return 0;
}
