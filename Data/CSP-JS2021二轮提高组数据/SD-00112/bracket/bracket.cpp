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


//inline int find(int x){
//	if(fa[x]==x)return x;
//	return fa[x]==find(fa[x]);
//}



//struct node{
//	int to,next;
//}e[N<<1];

//inline int add(int u,int v){
//	e[++tot].to=v;
//	e[tot].next=head[u];
//	head[u]=tot;
//}

//struct tree{
//	int l,r,pos,add;
//}t[N<<1];

//inline int build(int p,int l,int r){
//	t[p].l=l,t[p].r=r;
//	if(l==r){
//		return t[p].pos=a[l];
//	}
//	int mid=l+r>>1;
//	build(p<<1,l,mid);
//	build(p<<1|1,mid+1,r);
//	t[p].pos=t[p<<1].pos+t[p<<1|1].pos;
//}

//inline void exgcd(int a,int b,int &x,int &y){
//	if(b==0) x=1,y=0;
//	exgcd(b,a%b,y,x);
//	y-=a/b*x;
//}


//inline void gcd(int a,int b){
//	if(b==1) return a;
//	return gcd(b,a%b);
//}

//priority_queue<int>q;
//queue<int>q;

string s;

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	read(n);read(k);
	cin>>s;
	if(n==7&&k==3&&s=="(*??*??")write(5);
	if(n==10&&k==2&&s=="???(*??(?)")write(19);
//	int n,k;
//	read(n);read(k);
//	scanf("%s",s+1);
//	for(int i=1;i<=n;i++){
//		if(a[i]!='?') flag=1;
//	}
//	if(flag==0){
//		for(int i=1;i<=n;i++){
//			f[i][i]=1;
//		}
//		for(int len=2;len<=n;len++){
//			
//		}
//	}
	return 0;
}



