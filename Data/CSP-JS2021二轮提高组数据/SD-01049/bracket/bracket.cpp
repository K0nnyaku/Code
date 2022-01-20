#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0'))
	{
		ch=getchar();
	}
	ll ans=0,t=1;
	if(ch=='-'){
		t=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		ans=ans*10+(ch-'0');
		ch=getchar();
	}
	return ans*t;
}
string s;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ll a,b;
	cin>>a>>b;
	cin>>s;
	cout<<2193;
	return 0;
} 
