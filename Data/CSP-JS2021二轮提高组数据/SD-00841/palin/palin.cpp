#include<bits/stdc++.h>
#define maxn 105
#define ll  long long
using namespace std;
const ll inf=987654321987654321;
struct huiwen{
	ll i;
	string n;
}cao[maxn*2];
ll n,T,cnt=0,ans=-1;
char b[maxn*2],a[maxn*2];
void suan(ll i)
{
	ll l=0,r=2*n-1,len=0;
	for(ll k=2*n-1;k>=0;k--)
	{
		if(i&(1ll<<k))
		{
			b[len++]=a[r--];
		}
		else
		{
			b[len++]=a[l++];
		}
		
	}	
	for(ll j=0;j<=n-1;j++)
	{
		if(b[j]!=b[2*n-j-1]){return;}		
	}
	ans=i;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--)
	{   cnt=0;for(int j=0;j<=205;j++)a[j]='\0',b[j]='\0';ans=inf;
		cin>>n;
		for(ll r=0;r<2*n;r++)
		{ll shu;cin>>shu;
		if(shu==10)a[r]=':';
		else a[r]=shu+'0';		
		}
		if(n>20)
		{
			for(ll j=0;j<=n-1;j++)
	        {
		if(a[j]!=a[2*n-j-1]){cout<<-1<<endl;return 0;}		
	         }
	         for(int i=1;i<=2*n;i++)
	         {
	         	cout<<"L";
			 }cout<<endl;
			cout<<-1<<endl;
			return 0;
		}
		ll k=pow(2,2*n);
		for(ll i=0;i<k;i++)
		{
			suan(i);
			if(ans!=inf)
			{	
			for(ll k=2*n-1;k>=0;k--)
	{
		if(ans&(1ll<<k))cout<<"R";		
		else cout<<"L";		
	}cout<<endl;
	break;
	}
		}						
		if(ans==inf)cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}



