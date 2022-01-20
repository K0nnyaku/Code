#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int M=500500;
int a[M];
int t,n;
inline int read(){
	int x=0;
	char ch=getchar();
	bool flag=true;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			flag=false;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return flag?x:~(x-1);
}
int main(){
	t=read();
	if(t==1){
		printf("-1\n");
		return 0;	
	}
	while(t--){
		n=read();
		for(int i=1;i<=n*2;i++)
			a[i]=read();
		for(int i=1;i<=n*2;i++)
			printf("L");
		printf("\n");
	} 
	return 0;
}

