#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

typedef long long ll;
const int MO=1e9+7,N=210;
int dp[N][N][N]={0,1};
int ge[N];
string temp;
int n,k;

void print(int i)
{
	//for(int i=0;i<n;i++)
	//{
		puts("");
		puts("");
		puts("");
		for(int j=0;j<n;j++){
			puts("");
			for(int k=0;k<n;k++)
			{
				cout<<dp[i][j][k]<<" ";
			 } 
		}
			
	//}
}

void xing(int i)
{
	for(int j=0;j<=k;j++)
		for(int l=0;l<n;l++)
			dp[i][j][l]+=dp[i-1][j-1][l]%MO;
}

void leftk(int i)
{
	for(int l=n/2+1;l>=1;l--)
		{
			int sum_o=0;
			for(int j=0;j<=n;j++)
			{
				sum_o+=dp[i-1][j][l-1]%MO;
			}
			dp[i][0][l]+=sum_o%MO;
		}
}

void rightk(int i)
{
	for(int l=n/2+1;l>=0;l--)
		{
			int sum_o=0;
			for(int j=0;j<=n;j++)
			{
				sum_o+=dp[i-1][j][l+1]%MO;
			}
			dp[i][0][l]+=sum_o%MO;
		}
}

int dp_b()
{
	for(int i=1;i<n;i++)
	{
		if(ge[i]==1)
		{
			xing(i);
		}
		if(ge[i]==2)
		{
			leftk(i);
		}
		
		if(ge[i]==3)
		{
			rightk(i);
		}
		
		if(ge[i]==0)
		{
			xing(i);leftk(i);rightk(i);
		}
	//	print(i);
	}
	
	return dp[n-1][0][0]%MO;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	//cout<<(double)sizeof(dp)/1024/1024; 
	cin>>n>>k;
	cin>>temp;
	for(int i=0;i<n;i++)
	{
		if(temp[i]=='?')ge[i]=0;
		else if(temp[i]=='*')ge[i]=1;
		else if(temp[i]=='(')ge[i]=2;
		else if(temp[i]==')')ge[i]=3;
	}
	
	int res=dp_b()%MO;
	
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
7 3
(*??*??
*/
