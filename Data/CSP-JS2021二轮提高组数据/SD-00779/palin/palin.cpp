#include<iostream>
#include<cstdio>
using namespace std;
inline int rn(){
	char c=getchar();
	int ans=0,d=1;
	while(c<'0'||c>'9'){
		if(c=='-') d=-d;
		c = getchar();
	}while(c>='0'&&c<='9'){
		ans = ans*10+(c^48);
		c = getchar();
	}return ans*d;
}
void out(int n){
	if(n<0){
		putchar('-');
		n = -n;
	}
	if(!n){
		putchar('0');
		return;
	}
	char f[100];
	int top=0;
	while(n){
		f[++top] = n%10 + '0';
		n/=10;
	}while(top){
		putchar(f[top--]);
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n = rn();
	out(-1);
	return 0;
}
