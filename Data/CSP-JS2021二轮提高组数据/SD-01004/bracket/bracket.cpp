#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 20;
string s;
int n,k;
int stac[maxn],len[maxn];
bool vis[maxn];
int ans,top,flag,sum,cnt;
void che()
{
		for(int i=0;i<n;i++) cout<<s[i];
		for(int i=0;i<n;i++) printf("i = %d vis = %d\n",i,vis[i]);
//		printf("\n");
}
void dfs(int x)
{

	if(s[x]=='?'||s[x]=='('||s[x]==')'||s[x]=='*')
	{
		if(s[x]=='?')
		{
			s[x]='(';
			dfs(x+1);
			s[x]=')';
			dfs(x+1);
			s[x]='*';
			dfs(x+1);
			s[x]='?';
		}
		else dfs(x+1);
	}
	else
	{		
		for(int i=0;i<n;i++)
		{
			if(s[i]=='*')
			{
				len[i]=len[i-1]+1;
				if(len[i]>k)
				{
					flag=1;
					break;
				}
				if(s[i-1]!='*')
				{
				for(int j=i+1;j<n;j++)
					if(s[j]==')'&&!vis[j])
					{
						vis[j]=1;
						cnt++;
						break;
					}
				for(int j=i-1;j>=0;j--)
					if(s[j]=='('&&!vis[j])
					{
						vis[j]=1;
						cnt++;
						break;
					}
				if(cnt!=2) flag=1;
				cnt=0;
				}
			}
			if(s[i]=='(') stac[++top]=1;
			if(s[i]==')') stac[++top]=-1;
		}
		
		for(int i=1;i<=top;i++) sum+=stac[i];
		if(sum!=0) flag=1;	
		if(!flag)
		{
			ans++;
//			che();	
		}
		for(int i=0;i<n;i++) vis[i]=0;
//		for(int i=0;i<n;i++) cout<<s[i];
//		printf("sum = %d",sum);		
//		printf("\n");
		flag=0;
		top=0;
		sum=0;
	}
	return ;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	dfs(0);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
