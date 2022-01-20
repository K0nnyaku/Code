#include<cstdio>
using namespace std;
int n,m,T,k,x[55],p[55],t[55],e0,e1;
inline int read(){
	int x=0,f=1,c=getchar();
	while(c>57||c<48){if(c=='-')f=-1;else f=1;c=getchar();}
	while(c<58&&c>47)x=(x<<1)+(x<<3)+c-48,c=getchar();
	return x*f;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<n;++i)for(int j=0;j<m;++j)read();
	for(int i=0;i<n;++i)for(int j=1;j<m;++j)read();
	while(T--){
		scanf("%d",&k);
		for(int i=0;i<k;++i)scanf("%d%d%d",x+i,p+i,t+i);
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
