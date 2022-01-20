#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[1000001],head,tail,flag,hw[1000001];
int s1[1000001];
bool huiwen()
{
	for(int i=1;i<=n;i++)if(hw[i]!=hw[2*n-i+1])return false;
	return true;
}
void dfs(int step,int x)
{
	if(flag==1)return;
	else if(step==2*n)
	{
		if(huiwen())
		{
			flag=1;
			for(int i=1;i<=step;i++)
			{
				if(s1[i]==1)
					cout<<'L';
				else if(s1[i]==2)
					cout<<'R';
			}
			cout<<endl;
		}
		return;
	}
	else
	{
		s1[step+1]=1;
		hw[step+1]=a[head];
		head++;
		dfs(step+1,1);
		head--;
		
		s1[step+1]=2;
		hw[step+1]=a[tail];
		tail--;
		dfs(step+1,2);
		tail++;
		hw[step+1]=0;
		s1[step+1]=0;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
			cin>>a[i];
		head=1,tail=2*n;flag=0;
		memset(s1,0,sizeof(s1));
		memset(hw,0,sizeof(hw));
		dfs(0,0);
		if(flag==0)cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
