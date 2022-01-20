#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define mx2(a,b) (a>b?a:b)
#define MAXN 100005
using namespace std;
inline int read(void){
	int ans=0;
	char us=getchar();
	while(us<'0'||us>'9')us=getchar();
	while(us>='0'&&us<='9'){
		ans=(ans<<1)+(ans<<3)+(us^48);
		us=getchar();
	}
	return ans;
}
int ans;
int us;
int n;
int m1,m2;
struct fly{
	int a;
	int b;
}flys[MAXN];
bool cmp(fly a,fly b){
	return a.a<b.a;
}
int lq[MAXN];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	int i,j,k;
	int maxi;
	int l=0,r=(n>>1)-1;
	m1=read();m2=read();
	for(i=1;i<=m1+m2;++i){
		flys[i].a=read();
		flys[i].b=read();
	}
	sort(flys+1,flys+m1+1,cmp);
	sort(flys+m1+1,flys+m1+m2+1,cmp);
	ans=0;
	int n1,n2;
	for(j=0;j<=n;++j){
		n1=j;
		n2=n-j;
		for(i=1;i<=n1;++i)lq[i]=0;
		us=0;
		for(i=1;i<=m1;++i){
			maxi=0;
			for(k=1;k<=n1;++k)
				if((maxi==0||lq[k]>lq[maxi])&&lq[k]<flys[i].a)maxi=k;
			if(maxi!=0){
				++us;
				lq[maxi]=flys[i].b;
			}
		}
		for(i=1;i<=n2;++i)lq[i]=0;
		for(i=m1+1;i<=m2+m1;++i){
			maxi=0;
			for(k=1;k<=n2;++k)if((maxi==0||lq[k]>lq[maxi])&&lq[k]<flys[i].a)maxi=k;
			if(maxi!=0){
				++us;
				lq[maxi]=flys[i].b;
			}
		}
		ans=mx2(ans,us);
	}
	printf("%d",ans);
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
//
