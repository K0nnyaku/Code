#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=530,MOD=1e9+7;
long long f[N][N],t[N][N];
int n,k;
bool v[N][N],w[N][N];
char a[N];
long long check(int l,int r);
long long ck(int l,int r)
{
	if(w[l][r]) return t[l][r];
	w[l][r]=1;
	int ans=0;
	if(l>=r) return 0;
	if((a[l]=='(' && a[r]==')') || (a[l]=='(' && a[r]=='?') || (a[l]=='?' && a[r]==')') || (a[l]=='?' && a[r]=='?'))
	{
		bool flag=true;int tot=0; 
		for(int i=l+1;i<=r-1;i++)
		{
			if((a[i]!='*' && a[i]!='?') || tot+1>k){flag=false;break;}
			tot++;
		}
		if(flag) ans+=1;
		ans+=check(l+1,r-1);ans%=MOD;
		tot=0;
		for(int i=l+1;i<=r-1;i++)
		{
			if((a[i]!='*' && a[i]!='?') || tot+1>k) break;
			ans+=check(i+1,r-1);tot++;
			ans%=MOD;
		}tot=0;
		for(int i=r-1;i>=l+1;i--)
		{
			if((a[i]!='*' && a[i]!='?') || tot+1>k) break;
			ans+=check(l+1,i-1);tot++;
			ans%=MOD;
		}
	}
	t[l][r]=ans;
	return ans;
}

long long check(int l,int r)
{
	if(v[l][r]) return f[l][r];
	v[l][r]=1;
	if(l>=r){return 0;}
	if((a[l]=='(' && a[r]==')') || (a[l]=='(' && a[r]=='?') || (a[l]=='?' && a[r]==')') || (a[l]=='?' && a[r]=='?'))
	{
		bool flag=true;int tot=0; 
		for(int i=l+1;i<=r-1;i++)
		{
			if((a[i]!='*' && a[i]!='?') || tot+1>k){flag=false;break;}
			tot++;
		}
		if(flag) f[l][r]+=1;
		f[l][r]+=check(l+1,r-1);f[l][r]%=MOD;
		tot=0;
		for(int i=l+1;i<=r-1;i++)
		{
			if((a[i]!='*' && a[i]!='?') || tot+1>k) break;
			f[l][r]+=check(i+1,r-1);tot++;
			f[l][r]%=MOD;
		}tot=0;
		for(int i=r-1;i>=l+1;i--)
		{
			if((a[i]!='*' && a[i]!='?') || tot+1>k) break;
			f[l][r]+=check(l+1,i-1);tot++;
			f[l][r]%=MOD;
		}
	}
	w[l][r]=1;t[l][r]=f[l][r];
	for(int i=l+1;i<=r-1;i++)
	{
		int tot=0;
		f[l][r]+=check(l,i)*ck(i+1,r);f[l][r]%=MOD;
		for(int j=i+1;j<=r;j++)
		{
			if((a[j]!='*' && a[j]!='?') || tot+1>k) break;
			f[l][r]+=check(l,i)*ck(j+1,r);tot++;
			f[l][r]%=MOD;
		}
	}
	return f[l][r];
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	printf("%lld",check(1,n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
