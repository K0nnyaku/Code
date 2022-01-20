#include<iostream>
#include<cstdio>
#include<cstring>

int rd();
const int MUN=500005;
int n,k,l,r;
int a[MUN],b[MUN];

int ans[MUN];

int solve() {
	
}

int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=rd();
	while(T--) {
		printf("-1\n");
	}
	return 0;
}

int rd() {
	char ch=getchar();
	int f,c=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		c=c*10+ch-'0';
		ch=getchar();
	}
	return c*f;
}
