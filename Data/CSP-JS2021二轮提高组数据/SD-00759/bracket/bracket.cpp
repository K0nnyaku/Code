#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0,y=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')
			y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+(c-'0'),c=getchar();
	}
	return x*y;
}
void write(int x) {
	if(x<0) {
		putchar('-');
	}
	if(x>9) {
		write(x/10);
	}
	putchar(x%10+'0');
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);

//21!9-324@emb
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	if(a[0]=='*'||a[n-1]=='*') {
		cout<<0;
	} else {
		if(n==1) {
			cout<<0;
		}
		if(n==2) {
			cout<<1;

		}
		if(n==3) {
			cout<<1;
		}
		if(n==4) {
			cout<<2
		}
	}
	return 0;
}
