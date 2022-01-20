#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
inline void file(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}
inline int rd(){
	register int x=0;
	register char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x; 
}
int n,m1,m2,m,tot,ans;
struct evt{
	int at,tp,to;
	inline bool operator <(const evt &x)const{return at<x.at;}
}p[200010];
bool in[100010];
inline int mmax(const int &x,const int &y){return x>y?x:y;}
inline int solve(const int &lm){
	for(int i=1;i<=m;++i)in[i]=0;
	int am=lm,bm=n-lm,sum=0;
	for(int i=1;i<=tot;++i)
		if(p[i].tp&1){
			if(p[i].tp&2)
				am+=in[p[i].to];
			else
				if(am)--am,in[p[i].to]=1,++sum;
		}
		else{
			if(p[i].tp&2){
				if(bm)--bm,in[p[i].to]=1,++sum;
			}
			else
				bm+=in[p[i].to];
		}
	return sum;
}
int main(){
	file();
	n=rd(),m1=rd(),m2=rd(),m=m1+m2;
	if(n>=m)return printf("%d\n",m),0;
	for(int i=1;i<=m1;++i){
		p[++tot]=(evt){rd(),1,i};
		p[++tot]=(evt){rd(),3,i};
	}
	for(int i=1;i<=m2;++i){
		p[++tot]=(evt){rd(),2,i+m1};
		p[++tot]=(evt){rd(),4,i+m1};
	}
	sort(p+1,p+tot+1);
	for(int i=0;i<=n;++i)
		ans=mmax(ans,solve(i));
	printf("%d\n",ans);
	return 0;
}
