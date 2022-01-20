#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct node{
	int a,b;
}g1[100005],g2[100005];
int n,m1,m2,ans;
bool cmp(node l,node r){
	if(l.a==r.a)	return l.b<r.b;
	else	return l.a<r.a;
}
int AP1(int k){
	priority_queue < int , vector<int> , greater<int> > q;
	int usd=0,cnt=0;
	for(int i=1;i<=m1;i++){
		while(q.empty()==0&&q.top()<g1[i].a){
			q.pop();
			usd--;
		}
		if(usd<k){
			q.push(g1[i].b);
			usd++;
			cnt++;
		}
	}
	return cnt;
}
int AP2(int k){
	priority_queue < int , vector<int> , greater<int> > q;
	int usd=0,cnt=0;
	for(int i=1;i<=m2;i++){
		while(q.empty()==0&&q.top()<g2[i].a){
			q.pop();
			usd--;
		}
		if(usd<k){
			q.push(g2[i].b);
			usd++;
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%i%i%i",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%i%i",&g1[i].a,&g1[i].b);
	for(int i=1;i<=m2;i++)
		scanf("%i%i",&g2[i].a,&g2[i].b);
	sort(g1+1,g1+m1+1,cmp);
	sort(g2+1,g2+m2+1,cmp);
	for(int i=0;i<=n;i++){
		int f=AP1(i)+AP2(n-i);
		if(f>ans)
			ans=f;
	}
	printf("%i",ans);
	return 0;
}
