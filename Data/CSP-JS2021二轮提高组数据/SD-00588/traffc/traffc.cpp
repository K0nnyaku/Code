#include<cstdio>
#include<iostream>
using namespace std;
int redd(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main(){
	freopen("traffc.in","r",stdin);
	freopen("traffc.out","w",stdout);
	printf("%d",rand());
	return 0;
}
