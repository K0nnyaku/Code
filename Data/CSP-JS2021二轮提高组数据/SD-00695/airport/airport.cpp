#include<bits/stdc++.h>
#define fo(i,x,y) for(int i=x;i<=y;++i)
#define go(i,x,y) for(int i=x;i>=y;--i)
#define sml(x,y) x=min(x,y)
#define big(x,y) x=max(x,y)
#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define umap unordered_map
using namespace std;
inline void out(int *a,int l,int r){fo(i,l,r) printf("%d ",*(a+i));puts("");}

inline int read(){
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

const int N=2e5+5;
struct Plane{
	int x,y;
	Plane(){}
	Plane(int q,int p){x=q,y=p;} 
}a[N],b[N];//每架飞机的抵达与离开时刻互不相同 
bool operator<(const Plane &X,const Plane &Y){return X.x<Y.x;} 
int n,m1,m2,ans,c[N],d[N];
set<Plane> res;

void file(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}

int main(){
	//freopen("gen.txt","r",stdin);
	file();
	cin>>n>>m1>>m2;
	fo(i,1,m1) a[i].x=read(),a[i].y=read();
	fo(i,1,m2) b[i].x=read(),b[i].y=read();
	sort(a+1,a+1+m1);sort(b+1,b+1+m2);
	set<Plane>::iterator t;
	fo(i,1,m1) res.insert(a[i]);
	fo(i,1,n){
		int rp=0,x=0;
		//printf("%d:\n",i);system("Pause");
		while(1){
			//printf("%d\n",res.size());
			t=res.lower_bound(Plane(x,0));
			if(t==res.end()) break;
			//printf("%d %d\n",(*t).x,(*t).y);
			rp++;
			x=(*t).y;
			res.erase(t);
		}
		c[i]=c[i-1]+rp;
	}res.clear();
	fo(i,1,m2) res.insert(b[i]);
	//puts("qwq");
	fo(i,1,n){
		int rp=0,x=0;
		while(1){
			t=res.lower_bound(Plane(x,0));
			if(t==res.end()) break;
			rp++;
			x=(*t).y;
			res.erase(t);
		}
		d[i]=d[i-1]+rp;
	}
	fo(i,0,n) big(ans,c[i]+d[n-i]);
	
	//out(c,0,n);out(d,0,n);//////删去！！ 

	cout<<ans;
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
------------
7
*/
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
------------
4
*/
