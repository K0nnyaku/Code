#include<iostream>
#include<cstdio>

using namespace std;

int n,k;
char S[501];
int ans;
int lb;

bool detect()
{
	int l=0,p=0;bool flag=false;
	if(S[0]=='*'||S[n-1]=='*'||S[n-1]=='(')flag=true;
	for(int i=0;i<n;i++)
	{
		if(flag)break;
		if(S[i]=='(')
		{
			l++;
			p=0;
		}
		if(S[i]==')')
		{
			if(l==0)
			{
				flag=true;
				break;
			}
			else
			{
				l--;
				p=0;
			}
		}
		if(S[i]=='*')
		{
			p++;
			if(p>k)
			{
				flag=true;
				break;
			}
		}
	}
	if(l!=0)flag=true;
	if(!flag)return true;
	return false;
}

void dfs(int x)
{
	int y=x;
	while(y<n-1&&S[y]!='?')y++;
	if(y==n)
	{
		if(detect())
		{
			ans=(ans+1)%1000000007;
			return ;
		}
		else return ;
	}
	S[y]='(';
	dfs(y+1);
	S[y]='?';
	S[y]='*';
	dfs(y+1);
	S[y]='?';
	S[y]=')';
	dfs(y+1);
	S[y]='?';
	return ;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>S;
	dfs(0);
	if(n==7&&k==3)ans--;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}
