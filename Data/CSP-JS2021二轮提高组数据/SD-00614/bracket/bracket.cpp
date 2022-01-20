#include<bits/stdc++.h>
using namespace std;
char a;
int n,k,b[500],nas,ans;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a=='(') b[i]=1;
		if(a==')') b[i]=2;
		if(a=='*') b[i]=3;
		if(a=='?') b[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]==3)
		{
			nas++;
		}
		if(b[i]==0)
		{
			//if(nas<=k&&nas!=0)a[i]=3;
			if(nas<=k&&nas!=0)nas=0,ans+=nas/2+1;
		}
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
}
