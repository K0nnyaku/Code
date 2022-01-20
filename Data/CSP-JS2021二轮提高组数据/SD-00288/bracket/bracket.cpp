#include<bits/stdc++.h>
#define N 510
using namespace std;
char Map[N];
int str[N],top;
int ans,n,k;
bool Check()
{
	top=0,str[0]=0;
	if(Map[1]=='*'||Map[n]=='*')
	{
		return false;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(Map[i]=='(')
		{
			if(str[top]==-2)
				str[top]=-1;
			else
				str[++top]=-1;
		}	
		else if(Map[i]=='*')
		{
			if(str[top]==-2)
			{
				return false;
			}
			else if(str[top]==-1||top==0)
			{
				str[++top]=1;
			}
			else
			{
				str[top]++;
				if(str[top]>k)
				{
					return false;
				}
			}
		}
		else if(Map[i]==')')
		{
			if(str[top]>0||str[top]==-2)
				top--;
			top--;
			if(top<0)
			{
				
				return false;
			}
				
			if(str[top]>0)
			str[top]=-2;
		}
	}
	while(str[top]==-2||str[top]>0)
		top--;

		return true;
	
	
}
void dfs(int x,int NumOfLeft,int NumOfStar)
{ 

	if(NumOfLeft<0||NumOfStar>k)
	{	
		return ;
	}
		
	for(int i=x;i<=n;i++)
	{
		if(Map[i]=='(')
		{
			NumOfStar=0;
			NumOfLeft++;
		}
			
		else if(Map[i]=='*')
			NumOfStar++;
		else if(Map[i]==')')
		{
			NumOfStar=0;
			NumOfLeft--;
		}
			
		if(NumOfLeft<0||NumOfStar>k)
		{
			return ;
		}
			
		if(Map[i]=='?')
		{
			Map[i]='(';
			dfs(i+1,NumOfLeft+1,0);
			Map[i]='*';
			dfs(i+1,NumOfLeft,NumOfStar+1);
			Map[i]=')';
			dfs(i+1,NumOfLeft-1,0);
			Map[i]='?'; 
			return ;
		}
	}
	if(NumOfLeft!=0)
		return ;
	if(Check())
		ans++;
	return ;
}
int main()
{
	//左右大马猴 保佑不爆零 
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		cin>>Map[i];
	dfs(1,0,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
