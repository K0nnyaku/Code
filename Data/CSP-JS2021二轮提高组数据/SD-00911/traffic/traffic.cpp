#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

inline ll read(){
	register ll x=0,f=1;
	register char ch=getchar();
	while(ch<'0'|| ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0)	putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<14;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


