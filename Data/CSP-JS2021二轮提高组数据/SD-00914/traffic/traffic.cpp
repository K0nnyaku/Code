#include<iostream>
#include<cstdio>
#include<cstring>

int rd();

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int a=rd();
	printf("%d\n",a);
	return 0;
}

int rd(){
	char ch=getchar();
	int f,c=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		c=c*10+ch-'0';
		ch=getchar();
	}
	return c*f;
}
