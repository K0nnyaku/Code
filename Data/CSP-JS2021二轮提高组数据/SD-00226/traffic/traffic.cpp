#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
inline int read(){
	LL sum=0,w=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){;
		sum=(sum<<3)+(sum<<1)+c-'0';
		c=getchar();
	}
	return sum*w;
} 

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	return 0;
} 
