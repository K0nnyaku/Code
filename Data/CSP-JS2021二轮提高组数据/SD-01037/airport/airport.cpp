#include <cstdio>
#include <algorithm>
class vp{
	public:
		int val,pos;
		bool operator < (vp b) const{
			return pos<b.pos;
		}
		vp& operator =(vp b){
			val=b.val;
			pos=b.pos;
			return *this;
		}
		vp(int a=0,int b=0) : pos(a),val(b){}
};
vp a[200005];
using namespace std;
int c1[100005],c2[100005];
int m1,m2,n,top=0;
int main(){
	int i,j,ans=0;
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=m1;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		a[++top]=vp(x,i);
		a[++top]=vp(y,-i);
	}
	sort(a+1,a+top+1);
	for(i=1;i<=n;++i){
		int nw=0;
		char cbt[100005]={0};
		for(j=1;j<=top;++j){
			int v,op;
			if(a[j].val>0)
				v=a[j].val,op=1;
			else
				v=-a[j].val,op=-1;
			switch(op){
				case 1:{
					if(nw<i)
						cbt[v]=1,++nw,++c1[i];
					break;
				}
				case -1:{
					if(cbt[v])
						--nw;
					break;
				}
			}
		}
	}
	top=0;
	for(i=1;i<=m2;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		a[++top]=vp(x,i);
		a[++top]=vp(y,-i);
	}
	sort(a+1,a+top+1);
	for(i=0;i<=n;++i){
		int nw=0;
		char cbt[100005]={0};
		for(j=1;j<=top;++j){
			int v,op;
			if(a[j].val>0)
				v=a[j].val,op=1;
			else
				v=-a[j].val,op=-1;
			switch(op){
				case 1:{
					if(nw<i)
						cbt[v]=1,++nw,++c2[i];
					break;
				}
				case -1:{
					if(cbt[v])
						cbt[v]=0,--nw;
					break;
				}
			}
		}
	}
	for(i=0;i<=n;++i)
		if(c1[i]+c2[n-i]>ans)
			ans=c1[i]+c2[n-i];
	printf("%d",ans);
	return 0;
}
