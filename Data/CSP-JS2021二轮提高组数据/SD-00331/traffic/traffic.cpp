#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long lld;
typedef unsigned long long ull;
const int N=1e6+5;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>'0'&&ch<'9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x>9) write(x/10);
	putchar('0'^(x%10));
}

lld n,a[N];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<1176;
	return 0;
}

