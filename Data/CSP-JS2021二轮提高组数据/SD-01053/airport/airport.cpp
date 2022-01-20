#include<iostream>
#include<cstdio>
using namespace std;
int n,ma,mb;
int c,d,e,f,t,ans[5001],zhe[5001],daan[5001];
struct planein{
	long long int lai,zou;
	int s;
}a[5001];
struct planeout{
	long long int tc,tg;
	int s;
}b[5001];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>ma>>mb;
	for(int i=1;i<=ma;i++)
	{
	cin>>a[i].lai>>a[i].zou;	
	}
	for(int i=1;i<=mb;i++)
    {
		cin>>b[i].tc>>b[i].tg;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=ma;j++){if(a[j].s==0) {c=a[j].zou;ans[i]++;break;}}
		for(int j=1;j<=ma;j++)
		{
			if(a[j].lai>=c&&a[j].s!=1)
			{
				a[j].s=1;ans[i]++;c=a[j].zou;
			}	
		}
		
	}
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=mb;j++){if(b[j].s==0) {e=b[j].tg;zhe[i]++;break;}}
		for(int j=1;j<=mb;j++)
		{
			if(b[j].tc>=e&&b[j].s!=1)
			{
				b[j].s=1;zhe[i]++;e=b[j].tg;
			}
		}	
	}
	for(int i=0;i<=n;i++)
	{
		daan[i]=ans[i]+zhe[n-i];
		if(f<daan[i]) f=daan[i];
	}
	cout<<f<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;}
