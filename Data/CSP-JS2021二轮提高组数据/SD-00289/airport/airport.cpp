#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
#define	N 100010
ll n,m1,m2;
struct plane{
	ll st;
	ll ed;
}a[N],b[N];
ll bridge[N],t[N],t2[N],k1,k2,ans;
bool cmp(plane x,plane y){
	return x.st<y.st;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%lld%lld",&a[i].st,&a[i].ed);
	for(int i=1;i<=m2;i++)
		scanf("%lld%lld",&b[i].st,&b[i].ed);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	bridge[1]=a[1].ed;
	t[1]=1;
	for(int i=2;i<=m1;i++)
		for(int j=1;j<=n;j++)
			if(a[i].st>=bridge[j]){
				bridge[j]=a[i].ed;t[j]++;
				break;
			}
	for(int i=1;i<=n;i++)
		t[i]=t[i-1]+t[i];
	memset(bridge,0,sizeof(bridge));
	bridge[1]=b[1].ed;
	t2[1]=1;
	for(int i=2;i<=m2;i++)
		for(int j=1;j<=n;j++)
			if(b[i].st>=bridge[j]){
				bridge[j]=b[i].ed;t2[j]++;
				break;
			}
	for(int i=1;i<=n;i++)
		t2[i]=t2[i-1]+t2[i];
	for(int i=0;i<=n;i++)
		ans=max(ans,t[i]+t2[n-i]);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
#1
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
