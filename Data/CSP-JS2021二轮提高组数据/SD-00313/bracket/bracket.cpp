#include<bits/stdc++.h>//20pts
#include<cstdio>
using namespace std;
long long n,k,ans=0;
char a[509];
int cheng[509],q[509];
bool check()
{
	int kuo=0,lian=0,flag=0;
	for(int i=0;i<=n;i++)
		cheng[i]=0,q[i]=0;
	for(int i=1;i<=n;i++)//(*()*()*())
	{
		if(a[i]=='*')
		{
			if(flag==0||lian==k)return false;
			if(a[i-1]!='*')q[i]=i;
			if(a[i-1]=='*')q[i]=q[i-1];
			if(a[i+1]!='*')
			{
				if(a[i+1]=='(')
				{
					if(a[q[i]-1]!=')')
						cheng[kuo]++;
				}
				else cheng[kuo]++;
			}
			if(cheng[kuo]>1)return false;
			lian++;
			continue;
		}
		if(a[i]=='(')
		{
			flag=1,lian=0,kuo++;
			continue;
		}
		if(a[i]==')')
		{
			cheng[kuo]=0;
			flag=1,lian=0,kuo--;
			if(kuo<0)return false; 
		}
	}
	if(kuo!=0)return false;
	if(a[n]=='*')return false;
	//for(int i=1;i<=n;i++)cout<<a[i];
	//	cout<<endl;
	return true;
}
//bool check(int ceng,int l,int r)
//{
//	if(ceng==1&&(a[1]=='*'||a[n]=='*'))return false;
//	int 
//}
void dfs(int now)
{
	//cout<<now<<endl;
	if(a[now+1]=='?')
	{
		a[now+1]='(';
		dfs(now+1);
		a[now+1]=')';
		dfs(now+1);
		a[now+1]='*';
		dfs(now+1);
		a[now+1]='?';
	}
	else
		if(now<n)
			dfs(now+1);//7 3 (*??*??
	else
		if(check())
			ans++,ans%=1000000007;
	return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(a[1]!='?')
		dfs(1);
	else
	{
		a[1]='(';
		dfs(1);
		a[1]=')';
		dfs(1);
		a[1]='*';
		dfs(1);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
