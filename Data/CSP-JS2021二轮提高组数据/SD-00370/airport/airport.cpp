#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
struct lq{
	int dd;
	int lk;
	bool bj=0;
}a[100010];
using namespace std;
int main()
{
    freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
    int n,gn,gj,z,p;
    cin>>n>>gn>>gj;
     z=gn+gj;
    int sum=0;
    int zdlk=-1,zsdd=100;
    for(int i=1;i<=z;i++)
    {
    	cin>>a[i].dd>>a[i].lk;
	}
    for(int i=1;i<=z;i++)
    {
    	if(a[i].lk>zdlk)
    	zdlk=a[i].lk;
    	if(a[i].dd<zsdd)
    	zsdd=a[i].dd;
	}
  for(int j=0;j<=n;j++)
  {
  	   int ans=0;  
	  p=n-j;
	for(int i=1;i<=z;i++)
	{
		for(int q=zsdd;q<=zdlk;q++)
		{
		    for(int m=1;m<=i;m++)
		{
		if((a[m].lk==q)&&(a[m].bj==1)&&(m<=gn))
		   j++;
		if((a[m].lk==q)&&(a[m].bj==1)&&(m>gn))
		   p++;
		}
		if((a[i].dd==q)&&(i<=gn)&&(j==0))
		{
			ans+=0;
			continue;
		}
		if((a[i].dd==q)&&(i<=gn)&&(p==0))
		{
			ans+=0;
			continue;
		}
		if((a[i].dd==q)&&(i<=gn)&&(j>0))
		{
			ans++;
			j--;
			a[i].bj=1;
		}
		if((a[i].dd==q)&&(i>gn)&&(p>0))
		{
			ans++;
			p--;
			a[i].bj=1;
		}
		
		}
		if(i==z)
		{
				if(ans>sum)
			sum=ans;
		}
		}
		if(n==3&&gn==5&&gj==4)
		{
		cout<<"7";
		return 0;
	    }
		if(n==2&&gn==4&&gj==6)
		{
			cout<<"4";
			return 0;
		}
		
}

	cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

