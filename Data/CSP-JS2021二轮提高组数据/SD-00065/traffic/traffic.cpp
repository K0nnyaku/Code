#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;
int read(){
	int x=0;short f=0;char c=getchar();
	while(c<'0' || c>'9') { if(c=='-') f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=(x<<1)+(x<<3)+(c^48); c=getchar(); }
	return f ? ~x+1 : x ;
}

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	return 0;
}

