#include <cstdio>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
const int p=1000000007;
const int N=510;
int n,k;
//stack<int> st; //1=(,2=* 
char c[N];
int dfs(int pos,int left,int star,int pre) //×Ö·ûÎ»ÖÃ£¬×óÀ¨ºÅ¸öÊý£¬ÐÇºÅ¸öÊý£¬Ñ¡ÔñÌîÈë×Ö·û(,),* 
{
	if(star>k||left<0)
		return 0;
	if(left>n-pos+1)
		return 0;
	int ans=0;
	
	if(pre==3)
		return dfs(pos+1,left+1,star,0)+dfs(pos+1,left-1,star,2)+dfs(pos+1,left,star+1,1);
}
bool check(char c[])
{
	stack<int> st;
	int star=0;
	if(c[1]!='('||c[n]!=')')
		return 0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='(')
		{
			star=0;
			if(c[i-1]=='*'&&st.top!=0)
				st.push(0);
			st.push(1);
		}
		if(c[i]==')')
		{
			star=0;
			while(st.top!=1)
			{
				if(st.top==1)
				{
					
				}
			}
			st.pop();
			if(st.top!=0&&c[i+1]=='*')
				continue;
			if(st.top==0)
				st.pop();
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&c[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
