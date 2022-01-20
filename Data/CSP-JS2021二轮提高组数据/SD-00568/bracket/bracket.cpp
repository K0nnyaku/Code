#include<bits/stdc++.h>
using namespace std;
int n,k,answer;
char ch[501];
int dfs(int x,char ch1)
{
	int ans=0;
	ch[x]=ch1;
	for(int i=0;i<n;i++)
	{
		if(ch[i]=='?')
		{
			ans+=dfs(i,'(');
			ch[i]='?';
			ans+=dfs(i,')');
			ch[i]='?';
			ans+=dfs(i,'*');
			ch[i]='?';
			return ans;
		}
	}
	int v=0,k1=0,vi=0,vii=0;
	if(ch[0]=='*'||ch[0]==')') return 0;
	for(int i=0;i<n;i++)
	{
		if(ch[i]=='('&&vi==0&&k1!=0&&vii==1) return 0;
		if(ch[i]==')'&&vi==1&&k1!=0&&vii==1) return 0;
		if(ch[i]=='('&&vi==0&&k1!=0) vii==1;
		if(ch[i]==')'&&vi==1&&k1!=0) vii==1;
		if(k1>k) return 0;
		if(ch[i]=='(') vi=0,v++,k1=0;
		if(ch[i]==')') vi=1,v--,k1=0;
		if(ch[i]=='*') k1++;
	}
	if(v!=0) return 0;
	if(k1!=0) return 0;
	return 1;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>ch[i];
	}
	if(ch[0]=='*'||ch[0]==')') 
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(ch[i]=='?')
		{
			answer+=dfs(i,'(');
			ch[i]='?';
			answer+=dfs(i,')');
			ch[i]='?';
			answer+=dfs(i,'*');
			ch[i]='?';
			break;
		}
	}
	cout<<answer;
	fclose(stdin);
	fclose(stdout);
}
