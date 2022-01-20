#include<bits/stdc++.h>
using namespace std;
long long n,mn,mw,dpa[100005],dpb[100005],ans1[100005],ans2[100005];
struct node{
	long long l,r;
}a[100005],b[100005];
long long cmp(node A,node B){return A.l<B.l;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>mn>>mw;
	for(long long i=1;i<=mn;i++)
		cin>>a[i].l>>a[i].r;
	for(long long i=1;i<=mw;i++)
		cin>>b[i].l>>b[i].r;
	sort(a+1,a+1+mn,cmp);
	sort(b+1,b+1+mw,cmp);
	for(long long i=1;i<=mn;i++)
		for(long long j=1;j<=n;j++)
			if(dpa[j]<a[i].l)
			{
				dpa[j]=a[i].r;
				ans1[j]++;
				break;
			}
	long long k=0;
	for(long long i=1;i<=n;i++)	ans1[i]+=k,k=ans1[i];
	for(long long i=1;i<=mw;i++)
		for(long long j=1;j<=n;j++)
			if(dpb[j]<b[i].l)
			{
				dpb[j]=b[i].r;
				ans2[j]++;
				break;
			}
	k=0;
	for(long long i=1;i<=n;i++)	ans2[i]+=k,k=ans2[i];
	long long ans=-1;
	for(long long i=0;i<=n;i++)
		ans=max(ans,ans1[i]+ans2[n-i]);
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
