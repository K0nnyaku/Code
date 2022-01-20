#include<bits/stdc++.h>
using namespace std;
int n,k,ans,ans1[505],ck[505],ck1[505],l,r;
string s;
void KHD()
{
	l=-1,r=-1;
	for(int i=0;i<n;i++)
	{
		if(ans1[i]==1&&ck[i]==0)
			l=i;
		else if(ans1[i]==2&&l!=-1&&ck[i]==0)
		{
			r=i;
			return;
		}
	}
}
int KH()
{
	int zz=0,zzz=0;
	for(int i=0;i<n;i++)
	{
		if(ans1[i]==1)	zz++;
		if(ans1[i]==2)	zzz++;
	}
	if(zz!=zzz)	return 0;
	memset(ck,0,sizeof(ck));
	memset(ck1,0,sizeof(ck1));
	int kk=0;
	while(kk<=n)
	{
		l=-1;
		r=-1;
		KHD();
		if(l==-1||r==-1)
			return 0;
		ck[l]=ck[r]=1;
		int z=0;
		ck1[l]=ck1[r]=1;
		for(int i=l+1;i<r;i++)
		{
			if(ans1[i]!=3)	z=0;
			if(ans1[i]==3)	z++;
			if(z>k)
				return 0;
			if((ans1[i]==1||ans1[i]==2)&&ck1[i]!=1)
				return 0;
			ck1[i]=1;
			kk++;
		}
		kk+=2;
	}
	return 1;
}
void BRACKET(int z)
{
	if(z==n)
	{
		if(KH()==1)
		{
			ans++;
			ans%=1000000007;
		}
		return;
	}
	else if(ans1[z]!=4)
		BRACKET(z+1);
	else if(ans1[z]==4)
	{
		ans1[z]=1;
		BRACKET(z+1);
		ans1[z]=2;
		BRACKET(z+1);
		ans1[z]=3;
		BRACKET(z+1);
		ans1[z]=4;
	}
	return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
			ans1[i]=1;
		else if(s[i]==')')
			ans1[i]=2;
		else if(s[i]=='*')
			ans1[i]=3;
		else if(s[i]=='?')
			ans1[i]=4;
	}
	BRACKET(0);
	ans%=1000000007;
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
