#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[10010];
string s;
int l,r;

bool lf(int h,int b[],int m)
{
	int ll=l,rr=r;
	for(int i=h;i<=n/2;i++)
	{
		if(a[l]==a[r])
		{
		b[i]=a[ll];
		}
		if(a[ll]<a[rr])
		{
         	b[i]=a[ll];
			ll++;
		}
		else 
		{
			b[i]=a[rr];
			rr++;
		}
		for(int j=1;j<=i;j++)
			if(b[i]==b[j])return 0;
    }
	return 1;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t>0)
	{
	scanf("%d",&n);
	r=n;
	l=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}	
		
	
 for(int i=1;i<=n/2;i++)
	{
		if(a[l]==a[r])
		{
		s[i]='L';	
		}
		if(a[l]<a[r])
		{
			if(lf(i,a,a[l])==1)
			{
			s[i]='L';
			l++;
			}
			else 
			{
			s[i]='R';
			r--;
			}
		}
		if(a[l]>a[r]) 
		{
		s[i]='R';
		r--;
		}
	}
	cout<<s;
	t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
