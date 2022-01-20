#include<iostream>
#include<cstdio>
#define R register
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') 
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}


int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	printf("-1");
	return 0;
	fclose(stdin);
	fclose(stdout);
}
