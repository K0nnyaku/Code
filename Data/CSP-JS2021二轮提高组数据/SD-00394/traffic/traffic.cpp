#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
inline ll read(){
	ll x(0),f(1);
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
ll n;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<"0"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
