#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int k,n,len,ans;
char s[510],s_[510];
bool yasuo(int &i)
{
	int sum=0,id=i;
	char ls_[510]={""};
	for(int j=0;j<len;j++)
		ls_[j]=s_[j];
	while(ls_[i]=='*')sum++,i++;
	if(sum>k)return 0;
	if(id!=i)s_[id]='R';
	for(int j=id+1;j<len;j++,id++)
		s_[j]=ls_[id];
	if(s_[i]=='(')
	{
		int i_=i;
		while(s_[i+1]=='R')i++;i++;
		if(s[i]==')')
		{
			s_[id]='R';
			for(int j=id+1;j<=i;i++)
				s_[j]=s_[j+id];
		}
	}
	return 1;
//	while(i==)
}
bool pd()
{
	for(int i=0;i<len;i++)
	{
		if(yasuo(i)==0)return 0;
//		for(int )
	}
}
void dfs(int i,char ch)
{
	if(i==len)
	{
		s_[i]=ch;
		if(pd())ans++;
	}
	if(s[i]=='?')
	{
		s_[i]='*',dfs(i+1,'*');
		s_[i]='(',dfs(i+1,'(');
		s_[i]=')',dfs(i+1,')');
	}
	else 
	{
		s_[i]=ch;
		dfs(i+1,s[i+1]);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	len=strlen(s);
	dfs(0,s[0]); 
	cout<<ans<<endl;
	return 0;
}
