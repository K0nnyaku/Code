#include<iostream>
#include<cstdio>
using namespace std;
const int N=521,mod=1e9+7;
int n,K,f[N][N],g[N][N]; char s[N];
void add(int &x,int y){(x+=y)%=mod;}
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(); K=read();
	scanf("%s",s+1);
	f[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=K;k++){
				int w=f[j][k];
				if(s[i+1]=='(')add(g[j+1][0],w);
				else if(s[i+1]==')' && j)add(g[j-1][0],w);
				else if(s[i+1]=='*' && k<K)add(g[j][k+1],w);
				else{
					add(g[j+1][0],w);
					if(j)add(g[j-1][0],w);
					if(k<K && i)add(g[j][k+1],w);
				}
			}
		}
		for(int j=0;j<=n;j++)
			for(int k=0;k<=K;k++)
				f[j][k]=g[j][k],g[j][k]=0;
//		for(int j=0;j<=n;j++)
//			for(int k=0;k<=K;k++)
//				if(f[j][k])cout<<"f "<<i<<" "<<j<<" "<<k<<" = "<<f[j][k]<<endl;
	}
	cout<<f[0][0]<<endl;
	return 0;
}
//(*??*??
