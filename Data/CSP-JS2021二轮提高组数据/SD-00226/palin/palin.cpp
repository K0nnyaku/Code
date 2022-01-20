#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define LL long long
#define rep(i,a,b) for(long long i=(a);i<=(b);i++)
#define rop(i,a,b) for(long long i=(a);i<(b);i++)
using namespace std;
const int N=5e5+10;
int n,a[2*N],b[N],t;
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

void pr(LL now){
	for(int i=2*n-1;i>=0;i--){
		if(1ll*(1<<i)&now) putchar('L');
		else putchar('R');
	}
	putchar('\n');
	return; 
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
t=read();
while(t--){
	n=read();
	bool flag=0;
	rep(i,1,2*n) a[i]=read();
	for(LL i=(1<<(2*n))-1;i>=0;i--){
		bool fa=0;
		int head=1,tail=2*n;
		for(int j=2*n-1;j>=n;j--){
			if((1ll*1<<j)&i)b[2*n-j]=a[head],head++;
			else b[2*n-j]=a[tail],tail--;
		}
		for(int j=n-1;j>=0;j--){
			if((1ll*1<<j)&i){
				if(b[1+j]!=a[head]){
					fa=1;
					break;
				}
				head++;
			}
			else{
				if(b[1+j]!=a[tail]){
					fa=1;
					break;
				}
				tail--;
			}
		}
		if(fa==0){
			flag=1;
			pr(i);
			break;
		}
	}
	if(flag==0) printf("-1\n");
}
return 0;
} 
