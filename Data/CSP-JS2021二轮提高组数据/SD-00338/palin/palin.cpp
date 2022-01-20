#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
ll sa[1000020],sb[1000020];
ll hea,taa,tab;
ll team,n;
ll wei[500001][3];
char out1[500010],out2[500001];
void doge(ll x,ll y)
{
	if(tab==2*n)
	{
		ll a=1;
		for(int i=1;i<=n;++i)
			if(sb[i]!=sb[2*n-i+1])
				a=0;
		if(a==1);
		{
			for(int i=1;i<=2*n;++i)
				if(out1[i]>out2[i])
					break;
				else
				if(out1[i]<out2[i])
				{
					for(int j=i;j<=2*n;++j)
						out2[j]=out1[j];
					break;
				}
		}
		return;
	}
	tab++;
	sb[tab]=sa[y];
	out1[tab]='R';
	doge(x,y-1);
	sb[tab]=sa[x];
	out1[tab]='L';
	doge(x+1,y);
	tab--;
}
int main()
{
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	cin>>team;
	while(team--)
	{
		cin>>n;
		memset(wei,0,sizeof(wei));
		memset(sa,0,sizeof(sa));
		memset(sb,0,sizeof(sb));
		out2[1]='Z';
		for(int i=1;i<=2*n;++i)
			cin>>sa[i];
		tab=0;
		doge(1,2*n);
		//Êä³ö 
		if(out2[1]=='Z')
			cout<<-1<<endl;
		else
		{
			for(int i=1;i<=2*n;++i)
				cout<<out2[i];
			cout<<endl;
		}	
		for(int i=1;i<=2*n;++i)//ÖØÖÃ 
		{
			out1[i]='A';
			out2[i]='Z';
		}
	}
//	fclose(stdin);fclose(stdout);
	return 0;	
}
