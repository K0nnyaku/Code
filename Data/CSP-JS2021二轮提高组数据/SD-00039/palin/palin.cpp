#include<iostream>
using namespace std;
int a[2500],b[2500],c[2500],n,dn,l=1,r=0;
char final[2500],ans[2500];
bool ttt=1,t=1,tt=-1,tttt=1;;
void ifpalin()
{
	if(t)
	{
		for(int i=1;i<=dn;i++)
		{
			final[i]=ans[i];
			c[i]=b[i];
		}
		ttt=0;
	}
	else for(int i=1;i<=dn;i++)
	{
		if(c[i]!=b[i])
		{
			if(c[i]<b[i]) 
			{
				for(int j=1;j<=dn;j++)
				{
					final[i]=ans[i];
				}
			}
		}
	}
}
void search(int k)
{
	for(int i=0;i<=1;i++)
	{
		t=1;
		if(tt!=i)
		{
			tt=-1;
			ans[k]=76+i*6-1;
		if(i)	
		{
				b[k]=a[dn-r];
				r++;
		}
		else 
		b[k]=a[l++];
		if(k<=n)
			for(int j=1;j<k&&t;j++)
				if(b[j]==b[k]&&k!=1) t=0;
		if(l<=n&&r<=n+1) t=0;
		if(!t) 
		{
			b[k]=0;
			tt=i;
			if(i) r--;
			else l--;
		}
		if(k==dn) 
		{
			ifpalin();	
			tttt=0;
		}
		else  search(k+1);
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	for(int g=0;g<T;g++)
	{	
		cin>>n;
		dn=2*n;
		r=dn;
		for(int i=1;i<=dn;i++)
			cin>>a[i];
		search(1);
	if(tttt)
	cout<<-1;
	else for(int i=1;i<=dn;i++)
	cout<<final[i];
	cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
