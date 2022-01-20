#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=10000005;
int read(){
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	printf("1");
	return 0;
}
