//SCORE=15
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a;int r,n;
long long s[505],b[505],ans=0;
//char p[6]="0()*?";
const int mod=1000000007;
void sear(int pos)
{
	//cout<<pos<<endl;
	if(pos==n)
	{
		int khn=0,str=0,kht=0;
		for(int i=1;i<=n;i++)
		{
			if(khn<0)return;
			if(str>r)return;
			if(str>0&&khn==0&&kht==0)return;
			if(s[i]==1)khn++,str=0;
			if(s[i]==2)khn--,kht=1,str=0;
			if(s[i]==3)str++;
		}
		if(str>0)return;
		if(khn==0)
		{
			ans++;
			//for(int i=1;i<=n;i++)
			//cout<<p[s[i]];
 			//cout<<endl;
		}
		return;
	}
	while(s[pos]!=4&&pos<n)pos++;
	for(int i=1;i<=3;i++)
	{
		s[pos]=i;
		sear(pos);
		s[pos]=4;
	}

}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>r;cin>>a;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]=='(')s[i]=1;
		if(a[i-1]==')')s[i]=2;
		if(a[i-1]=='*')s[i]=3;
		if(a[i-1]=='?')s[i]=4;
	}
	sear(1);
	cout<<ans;
	return 0;
}
