#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=1000005;
set<int>S;
struct Flights{
	int l,r;
}f[maxn];
bool cmp(Flights A,Flights B)
{
	return A.l<B.l;
}
int del1[maxn],del2[maxn],sum1[maxn],sum2[maxn];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int k,m,n,summ,rr,t,i;
	set<int>::iterator K;
	scanf("%d%d%d",&k,&m,&n);
	for(i=1;i<=m;++i)scanf("%d%d",&f[i].l,&f[i].r);
	sort(&f[1],&f[m],cmp);
	summ=rr=0;
	for(i=1;i<=m;++i)
	{
		t=0;
		for(K=S.begin();K!=S.end();++K)
			if((*K)<f[i].l)
			{
				++t;
				summ--;
			}
			else break;
		while(t--)S.erase(S.begin());
		S.insert(f[i].r);summ++;
		if(f[i].l>rr)
		{
			del1[1]++;
			rr=f[i].r;
		}
		else del1[summ]++;
	}
	for(i=1;i<=n;++i)scanf("%d%d",&f[i].l,&f[i].r);
	sort(&f[1],&f[n],cmp);
	summ=rr=0;
	for(i=1;i<=n;++i)
	{
		t=0;
		for(K=S.begin();K!=S.end();++K)
			if((*K)<f[i].l)
			{
				++t;
				summ--;
			}
			else break;
		while(t--)S.erase(S.begin());
		S.insert(f[i].r);summ++;
		if(f[i].l>rr)
		{
			del2[1]++;
			rr=f[i].r;
		}
		else del2[summ]++;
	}
	for(i=1;i<=k;++i)sum1[i]=sum1[i-1]+del1[i];
	for(i=1;i<=k;++i)sum2[i]=sum2[i-1]+del2[i];
	//for(i=1;i<=k;++i)printf("d:%d %d\n",del1[i],del2[i]);
	int ans=0;
	for(i=0;i<=k;++i)
	if(sum1[i]+sum2[k-i]>ans)
	ans=sum1[i]+sum2[k-i];
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}

