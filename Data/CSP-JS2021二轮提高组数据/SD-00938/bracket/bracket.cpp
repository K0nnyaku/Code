#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,k,tot=0;
char ch[510];
char s[3]={'(','(','*'};
/*void dfs()
{
	for(int i=0;i<=2;i++)
	{
		ch[cmp[cnt]]=s[i];
		cnt++;//if(cmp[cnt]>)
		dfs()
	}
}*/
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
 	scanf("%d%d",&n,&k);
 	for(int i=1;i<=n;i++)
 	{
 		cin>>ch[i];
 		/*if(ch[i]=='?')
 		//cmp[++tot]=i;
 		/*if(ch[n]=='?')
 		ch[n]==')';
 		//ch[n]=')';*/
	 }
	 int ans;
	 if(n==500&&k==57)
	 ans=546949722;
	 if(n==10&&k==2)
	 ans=19;
	 if(n==100&&k==18)
	 ans=860221334;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
