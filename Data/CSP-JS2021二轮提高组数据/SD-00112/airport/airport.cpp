//rp++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define N 1000010
#define INF 0x3f3f3f
#define ll long long
#define ld long double
using namespace std;
inline void read(int &x){
	x=0;int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
}

inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	write(x/10);
	putchar(x%10+'0');
}
int sum,xx[N];
int n,m[2];
int f[2][N];
struct node{
	int a,b;
}a[2][N];
int cmp(node x,node y){
	return x.a<y.a;
}
inline int work(int key,int kk){
	memset(xx,0,sizeof(xx));
	sum=0;
	int cnt=0;
	if(kk==0) return 0;
	for(int i=1;i<=m[key];i++){
		int flag=0;
		int minn=INF;
		int x=0;
		for(int j=1;j<=sum;j++){
			if(a[key][i].a>xx[j]&&xx[j]<minn){
				minn=xx[j];
				flag=1;
			}
		}
		if(flag){
			cnt++;
			xx[x]=a[key][i].b;
			continue;
		}
		if(sum+1<=kk) xx[++sum]=a[key][i].b,cnt++;
	}
		
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m[0]);read(m[1]);
	if(m[0]+m[1]<=n){
		write(m[0]+m[1]);
		return 0;
	}
	for(int i=1;i<=m[0];i++){
		cin>>a[0][i].a>>a[0][i].b;
	}
	for(int i=1;i<=m[1];i++){
		cin>>a[1][i].a>>a[1][i].b;
	}
	sort(a[0]+1,a[0]+1+m[0],cmp);
	sort(a[1]+1,a[1]+1+m[1],cmp);
	int maxn=0;
	for(int i=0;i<=n;i++){
		maxn=max(maxn,work(0,i)+work(1,n-i));
	}
	write(maxn);
	return 0;
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11 
4 15
7 17
12 16
*/


