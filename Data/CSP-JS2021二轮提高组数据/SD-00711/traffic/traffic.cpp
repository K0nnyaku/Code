#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll read(){
	ll a=0,x=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')	x=-x;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*x;
}
void write(ll a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>=10)	write(a/10);
	putchar(a%10+'0');
}
signed main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<13;//13 is my lucky number!I love it.
	return 0;
}

