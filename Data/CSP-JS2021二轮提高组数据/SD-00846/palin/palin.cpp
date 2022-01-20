#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000005],b[1000005],ck[1000005],z,ans[1000005];
int HWS()
{
	for(int i=1;i<=n;i++)
		if(b[i]!=b[n*2-i+1])	return 0;
	return 1;
}
void DA(int k,int l,int r)
{
	if(z)	return;
	if(k==n*2)
	{
		if(HWS()==1)
		{
			z=1;
			for(int i=1;i<=n*2;i++)
			{
				if(ans[i]==1)
					cout<<"L";
				if(ans[i]==2)
					cout<<"R";
			}
			cout<<'\n';
			return;
		}
	}
	else
	{
		b[k+1]=a[l+1];
		ans[k+1]=1;
		DA(k+1,l+1,r);
		b[k+1]=a[r-1];
		ans[k+1]=2;
		DA(k+1,l,r-1);
		b[k+1]=0;
		return;
	}
}
int main()
{
	freopen("palin2.in","r",stdin);
	freopen("palin2.out","w",stdout);
	cin>>t;
	while(t--)
	{
		z=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(ans,0,sizeof(ans));
		cin>>n;
		for(int i=1;i<=n*2;i++)
			cin>>a[i];
		DA(0,0,n*2+1);
		if(z!=1)
			cout<<-1;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
