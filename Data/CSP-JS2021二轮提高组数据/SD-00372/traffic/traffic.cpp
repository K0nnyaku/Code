#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;
long long int n,m,T,mp1[501][501],mp2[501][501],k,ans,ret,mtx[501][501];
double lim;
time_t bgin,ed;
struct data{
	long long int t1,t2,t3;
}rec[51];
long long int read(void){
	long long int tans=0;
	char ch=getchar();
	while((ch<'0')||(ch>'9'))
		ch=getchar();
	while((ch>='0')&&(ch<='9')) 
		tans=tans*10+ch-'0',
		ch=getchar();
	return tans;
};
inline long long int fmin(const long long int a,const long long int b){
	return a<b?a:b;
};
inline pair<long long int,long long int>getk(const long long int val){
	pair<long long int,long long int>tmp;
	if((val>=1)&&(val<=m)){
		tmp.first=1,
		tmp.second=val;
		return tmp;
	};
	if((val>=m+1)&&(val<=m+n)){
		tmp.first=val-m,
		tmp.second=m;
		return tmp;
	};
	if((val>=m+n+1)&&(val<=(m<<1)+n)){
		tmp.first=(m<<1)+n-val+1,
		tmp.second=n;
		return tmp;
	};
	tmp.first=(m<<1)+(n<<1)-val+1,
	tmp.second=1;
	return tmp; 
};
int main(void){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand((unsigned)time(NULL));
	scanf("%lld%lld%lld",&n,&m,&T);
	lim=2.8/(double)T;
	for(register long long int i=1;i<=n-1;i++)
		for(register long long int j=1;j<=m;j++)
			mp1[i][j]=read();
	for(register long long int i=1;i<=n;i++)
		for(register long long int j=1;j<=m-1;j++)
			mp2[i][j]=read();
	while(T--){
		bgin=clock(),
		k=read(),
		ans=0x3f3f3f3f3f3f3f3f;
		for(register long long int i=1;i<=k;i++)
			rec[i].t1=read(),
			rec[i].t2=read(),
			rec[i].t3=read();
		while(true){
			ret=0;
			for(register long long int i=1;i<=n;i++)
				for(register long long int j=1;j<=m;j++)
					mtx[i][j]=rand()&1;
			for(register long long int i=1;i<=k;i++)
				if(mtx[getk(rec[i].t2).first][getk(rec[i].t2).second]!=rec[i].t3)
					ret+=rec[i].t1;
			for(register long long int i=1;i<=m;i++)
				for(register long long int j=1;j<=n-1;j++)
					if(mtx[j][i]!=mtx[j+1][i])
						ret+=mp1[j][i];
			for(register long long int i=1;i<=n;i++)
				for(register long long int j=1;j<=m-1;j++)
					if(mtx[i][j]!=mtx[i][j+1])
						ret+=mp2[i][j];
			ans=fmin(ans,ret),
			ed=clock();
			if((double)(ed-bgin)/CLOCKS_PER_SEC>=lim)
				break;
		};
		printf("%lld\n",ans);
	};
	fclose(stdin);
	fclose(stdout);
	return 0;
};
