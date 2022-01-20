#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N=1e6+10;
int n,m1,m2,x,y,a[N],b[N],nowa,nowb,maxn,ans;
int nd1,nd2;
bool visa[N],visb[N];
struct node{
	int pt,num;
	bool tr;
};
node sa[2*N],sb[2*N];
int cmp(node a,node b){
	return a.pt<b.pt;
}
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

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	rep(i,1,m1){
		x=read();y=read();
		sa[(i<<1)-1].pt=x;sa[(i<<1)-1].tr=0;sa[(i<<1)-1].num=i;
		sa[i<<1].pt=y;sa[i<<1].tr=1;sa[i<<1].num=i;
	}
	rep(i,1,m2){
		x=read();y=read();
		sb[(i<<1)-1].pt=x;sb[(i<<1)-1].tr=0;sb[(i<<1)-1].num=i;
		sb[i<<1].pt=y;sb[i<<1].tr=1;sb[i<<1].num=i;
	}
	sort(sa+1,sa+((m1<<1)|1),cmp);
	sort(sb+1,sb+((m2<<1)|1),cmp);
	
	rep(i,0,n){
		rep(j,0,10000) visa[j]=0,visb[j]=0;
		int la=i,lb=n-i,maxa=0,maxb=0,ca=0,cb=0;
		nowa=0;nowb=0;
		rep(j,1,2*m1){
			if(sa[j].tr==0){
				nowa++;
				if(nowa>la) nowa--;
				else{
					ca++;
					visa[sa[j].num]=1;
				}
			}
			else{
				if(visa[sa[j].num]==1) nowa--;
			}
		}
		rep(j,1,2*m2){
			if(sb[j].tr==0){
				
				nowb++;
				if(nowb>lb) nowb--;
				else{
					cb++;
					visb[sb[j].num]=1;
				}
			}
			else{
				if(visb[sb[j].num]==1) nowb--;
			}
		}
		ans=max(ans,ca+cb);
	}
	
	printf("%d\n",ans);
	return 0;
} 
