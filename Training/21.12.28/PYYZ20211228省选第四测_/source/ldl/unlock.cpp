#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=521;
const long double eps=1e-10;
int n,K,vis[N],p[N],stk[N];
long double C[N][N],f[N][N];
bool cmp(const int &x,const int &y){return x>y;};
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("unlock.in","r",stdin);
	freopen("unlock.out","w",stdout);
	int aq=read();
	while(aq--){
		n=read(); K=read();
		for(int i=1;i<=n;i++)p[i]=read();
		for(int i=1;i<=n;i++)vis[i]=0;
		int top=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue; int cnt=0;
			int x=i; while(!vis[x])vis[x]=1,x=p[x],++cnt;
			stk[++top]=cnt;
//			cerr<<"cnt="<<cnt<<endl;
		}
		C[0][0]=C[1][0]=C[1][1]=1;
		sort(stk+1,stk+top+1,cmp);
		for(int i=2;i<=stk[1];i++){
			C[i][0]=1;
			for(int j=1;j<=i;j++)
				C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
		f[0][0]=1;
		long double q=n,q1=n-K;
		for(int i=1;i<=top;i++){
			long double mx=0;
			for(int j=i;j<=K;j++){
				for(int k=1;k<=stk[i];k++){
					if(k>j)break;
					f[i][j]+=f[i-1][j-k]*C[stk[i]][k];
				} mx=max(mx,f[i][j]);
			}
//			for(int j=1;j<=K;j++)cout<<"f"<<i<<" "<<j<<"="<<f[i][j]<<endl;
			long double ml=1,ml2=1;
			while(mx>1e20 && q>K)mx/=q,ml*=q,--q;
			while(mx<eps && q1>0)mx*=q1,ml2*=q1,--q1;
			for(int j=i;j<=K;j++)f[i][j]*=ml2/ml;
		}
		while(q>K)f[top][K]/=q,--q;
		while(q1>0)f[top][K]*=q1,--q1;
		cout<<f[top][K]<<endl;
		printf("%0.10Lf\n",f[top][K]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=K;j++)f[i][j]=0;
	}
	return 0;
}
