#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

template<typename T = int>
inline T read(){
	T x=0,w=1;
	char ch=getchar();
	
	while(!isdigit(ch)){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}	
	
	return x*w;
}
template<typename T = int>
inline void write(T x){
	static int sta[56],tp=0;
	if(x<0){
		putchar('-');
		x=-x;
	}else if(x==0){
		putchar('0');
		return;
	}
	while(x){
		sta[++tp]=x%10,x/=10;
	}
	while(tp){
		putchar(sta[tp--]+'0');
	}
	return;
}

const int N=1e5+5;
int n,m1,m2;
int n1,n2;
int cnt1,cnt2;
int l,r;

struct Pln {
	int a;
	int b;
	bool operator < (const Pln& p) const {
		if(a<p.a){
			return true;
		}else if(a==p.a){
			return b<p.b;
		}else return false;
	}
};
Pln p1[N], p2[N];
priority_queue<int, vector<int>, greater<int> > qu;
int ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	n=read(),m1=read(),m2=read();
	for(register int i=1;i<=m1;i++) p1[i]={read(),read()};
	for(register int i=1;i<=m2;i++) p2[i]={read(),read()};
	sort(p1+1,p1+m1+1);
	sort(p2+1,p2+m2+1);
//	for(register int i=1;i<=m1;i++){
//		write(p1[i].a);
//		putchar(' ');
//		write(p1[i].b);
//		putchar('\n');
//	}
//	for(register int i=1;i<=m2;i++){
//		write(p2[i].a);
//		putchar(' ');
//		write(p2[i].b);
//		putchar('\n');
//	}
	for(register int i=0;i<=n;i++){
		n2=n-i,cnt1=cnt2=0;
		if(i!=0){
			qu = priority_queue<int, vector<int>, greater<int> >();
			for(register int j=1;j<=i;j++){
				qu.push(p1[j].b);
			}
			cnt1+=i;
			int id;
			for(id=i+1;id<=m1;id++){
				if(p1[id].a>qu.top()){
					qu.pop();
					int tms = 1;
					while(!qu.empty() && qu.top()<p1[id].a){
						qu.pop();
						tms++;
					}
					for(register int tmi=1;tmi<=tms;tmi++) qu.push(p1[id++].b);
					id--;
					cnt1+=tms;
				}
			}
		}
		if(i!=n){
			qu = priority_queue<int, vector<int>, greater<int> >();
			for(register int j=1;j<=n2;j++){
				qu.push(p2[j].b);
			}
			cnt2+=n2;
			int id;
			for(id=n2+1;id<=m2;id++){
//				cerr<<id<<" "<<p2[id].a<<" "<<qu.top()<<endl;
				if(p2[id].a>qu.top()){
					qu.pop();
					int tms = 1;
					while(!qu.empty() && qu.top()<p2[id].a){
						qu.pop();
						tms++;
					}
					for(register int tmi=1;tmi<=tms;tmi++) qu.push(p2[id++].b);
					id--;
					cnt2+=tms;
				}
			}
		}
//		cerr<<i<<" "<<n-i<<" "<<cnt1<<" "<<cnt2<<endl;
		ans=max(ans,cnt1+cnt2);
	}
	
	write(ans);
	putchar('\n');
		
	return 0;
}
