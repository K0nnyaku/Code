#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxn=500005;
ll n,a[maxn],b[maxn];
char s[maxn];
int main(){ll _o;
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	for(cin>>_o;_o--;){
		cin>>n;bool OK=false;
		for(ll i=0;i<n*2;i++)cin>>a[i];
		for(ll x=0;x<(1ll<<(n*2));x++){
			for(ll i=0;i<n*2;i++)
				if(x&(1ll<<i))s[n*2-i-1]='R';else s[n*2-i-1]='L';
			ll i=0,j=n*2-1,ok=1;
			for(ll k=0;k<n*2;k++)
				if(s[k]=='L')b[k]=a[i++];
				else b[k]=a[j--];
			for(ll k=0;k<n;k++)
				if(b[k]!=b[n*2-k-1]){ok=0;break;}
			if(ok){cout<<s<<endl;OK=true;break;} 
		}
		if(!OK)cout<<-1<<endl;
	}return 0;
}
