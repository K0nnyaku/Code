#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N = 1e5+10; 
template<class T>
inline void read(T &x){
	x = 0;
	char c=getchar();
	bool t = false;
	while(c<'0'||c>'9'){if(c=='-')t=true;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x = x*(t?-1:1);
}
struct node{
	int l,r,idx;
}ap[N];//国际 
struct Node{
	int s,t,idx;
}na[N];//国内 
int n,ma,mb;
int lowbit(int x){
	return x&(-x);
}
bool cmp1(Node x,Node y){
	return x.s<y.s;
}
bool cmp2(node x,node y){
	return x.l<y.l;
}
int sa[N];
void add1(int x){
	while(x<=n){
		sa[x]+=1;
		x+=lowbit(x);	
	}
}
int sb[N];
void add2(int x){
	while(x<=n){
		sb[x]+=1;
		x+=lowbit(x);
	}
}
int getsa(int x){
	int t = 0;
	while(x>=1){
		t+=sa[x];
		x-=lowbit(x);
	}
	return t;
}
int getsb(int x){
	int t = 0;
	while(x>=1){
		t+=sb[x];
		x -= lowbit(x);
	}
	return t;
}

bool vis[N];
int l[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(ma);read(mb); 
	for(int i=1;i<=ma;i++){
		read(na[i].s);read(na[i].t); 
	}
	for(int i=1;i<=mb;i++){
		read(ap[i].l);read(ap[i].r);
	}
	sort(na+1,na+1+ma,cmp1);
	for(int i=1;i<=ma;i++){
		l[i] = na[i].s;
	}
	int idx = 0 ;
	int sum = 0 ;
	int tg = 0;
	for(int i=1;i<=ma;i++){
		if(vis[i])continue;
		int j = i;
		sum++;
		idx++;
		add1(sum);
		while(j<=ma){
			if(na[j].t>na[ma].s)break;
			int d = lower_bound(l+j+1,l+1+ma,na[j].t) - l;
			if(vis[d]){
				tg = 0;
				for(int k=d+1;k<=ma;k++){
					if(!vis[k]){
						d = k;	
						tg = 1;
						break;
					}  
				}
				if(!tg)break;	
			}
			vis[d] = 1;
			j = d;
			idx++;
			add1(sum);
			if(idx==ma)break;
		}
		if(idx==ma)break;
	}
		
	sum = 0;
	memset(l,0,sizeof(l));
	memset(vis,0,sizeof(vis));
	sort(ap+1,ap+1+mb,cmp2);
	idx = 0;
	for(int i=1;i<=mb;i++){
		l[i] = ap[i].l;
	}
	for(int i=1;i<=mb;i++){
		if(vis[i])continue;
		sum++;
		add2(sum);
		int j = i;
		idx++;
		while(j<=mb){
			if(ap[j].r>ap[mb].l)break;
			int d = lower_bound(l+j+1,l+1+mb,ap[j].r) - l;
			if(vis[d]){
				tg = 0;
				for(int k=d+1;k<=mb;k++){
					if(!vis[k]){
						d = k;
						tg = 1;
						break;
					}
				}
				if(!tg)break;
			}
			vis[d] = 1;
			j = d;
			add2(sum); 
			idx++;
			if(idx==mb)break;
		}
		if(idx==mb)break;
	}
	int Max = 0,ans = 0 ;
	for(int i=0;i<=n;i++){
		ans = 0;
		ans = ans+getsa(i);
		ans = ans+getsb(n-i);
		Max = max(Max,ans);
	}
	cout<<Max;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
