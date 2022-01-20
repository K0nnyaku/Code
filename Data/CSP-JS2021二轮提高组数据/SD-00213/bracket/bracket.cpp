#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,k,len,ansa;
string s;
void dfs(int layer,string ans)
{
	if(layer==n-1)
	{
		ansa++;
		return ;
	}
	if(s[layer]=='?')
	for(int i=1;i<=3;i++)
	{
		if(i==1) dfs(layer+1,ans+'(');
		else if(i==2) dfs(layer+1,ans+')');
		else dfs(layer+1,ans+'*');
	}
	else dfs(layer+1,ans+s[layer]);
}
int main()
{
//	clock_t c1=clock();
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	//================================================
	cin>>n>>k;
	cin>>s;len=s.length();
	dfs(0,"");
	printf("%d",ansa%1000000007);
	//================================================
	fclose(stdin);
	fclose(stdout);
//	cerr<<endl<<"Time:"<<clock()-c1<<"ms"<<endl;
	return 0;
}
/*
7 3
(*??*??
*/
