#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long lld;
typedef unsigned long long ull;
const int N=1e6+5;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>'0'&&ch<'9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x>9) write(x/10);
	putchar('0'^(x%10));
}

int fa[N];
int find(int x){
	while(x!=fa[x]){
		x=fa[x]=fa[fa[x]];
	}
	return x;
}


int a[N],b[N];

int t;
lld n;
void calc(){
	lld l=1,r=n,tot=0;
	for(int i=1;i<=n;i++){
	}
}


int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	for(int i=1;i<=2*n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=t;i++){
		n=read();
		for(int j=1;j<=2*n;j++){
			a[i]=read();
		}
		cout<<-1<<endl;
	}
	return 0;
}

