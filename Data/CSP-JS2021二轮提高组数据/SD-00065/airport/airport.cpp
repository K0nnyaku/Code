#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#define max(x,y) (x>y?x:y)
typedef long long ll;
const int N=100005;
int read(){
	int x=0;short f=0;char c=getchar();
	while(c<'0' || c>'9') { if(c=='-') f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=(x<<1)+(x<<3)+(c^48); c=getchar(); }
	return f ? ~x+1 : x ;
}
int n,m1,m2,k,FLY,ans=-1,sum1,sum2;
std::priority_queue<std::pair<int,int> > q;
struct Node{
	int G,L;
};
Node con1[N],con2[N];
bool cmp(Node a,Node b){
	return a.G<b.G;
}
int mycheck(){
	FLY=sum1=sum2=0; 
	for (int i=1;i<=m1;++i){
		if(!q.empty()){
			while(con1[i].G >= con1[q.top().second].L && !q.empty()){
				q.pop(); --FLY;
			}
		}
		if(FLY<k){
			++FLY;++sum1;
			q.push(std::make_pair(-con1[i].L,i));
		}
	}
	while(!q.empty()) q.pop();
	FLY=0; 
	for (int i=1;i<=m2;++i){
		if(!q.empty()){
			while(con2[i].G >= con2[q.top().second].L && !q.empty()){
				q.pop(); --FLY;
			}
		}
		if(FLY<(n-k)){
			++FLY;++sum2;
			q.push(std::make_pair(-con2[i].L,i));
		}
	}
	return sum1+sum2;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read(); k=m1+m2;
	for (int i=1;i<=m1;++i){
		con1[i].G=read(),con1[i].L=read();
	}
	std::sort(con1+1,con1+1+m1,cmp);
	for (int i=1;i<=m2;++i){
		con2[i].G=read(),con2[i].L=read();
	}
	std::sort(con2+1,con2+1+m2,cmp);
	for (k=0;k<=n;++k){  
		ans=max(mycheck(),ans);
	}
	printf("%d\n",ans);
	return 0;
}
