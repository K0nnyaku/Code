#include<iostream>
#include<string.h>
using namespace std;
const int MAX=100000005;
const int N=100005;
int n,m1,m2;
int de1[MAX],de2[MAX],v1[N],v2[N];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1,a,b;i<=m1;i++){
		scanf("%d%d",&a,&b);
		int deep=0;
		for(int f=a;f<=b;f++)de1[f]++,deep=max(de1[f],deep);
		v1[deep]++;
	}
	for(int i=1,a,b;i<=m2;i++){
		scanf("%d%d",&a,&b);
		int deep=0;
		for(int f=a;f<=b;f++)de2[f]++,deep=max(de2[f],deep);
		v2[deep]++;
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,v1[i]+v2[n-i]);
	}
	printf("%d",ans);
	return 0;
}
