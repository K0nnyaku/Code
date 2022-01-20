#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
struct edge{
	int xf,yf,xs,ys,l;
}b[300005],b1[300005];
int n,m,T,x,bt,k,d,p,t,f[505][505],ans;
void read(int &x){
	int f=1;char c=getchar();x=0;
	while(c<'0'||c>'9'){
		if (c=='-')f=-f;
		c=getchar(); 
	}
	while (c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}x*=f;
}
bool cmp(edge x,edge y){return x.l>y.l;}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	read(n);read(m);read(T);bt=0;
	for (int i=1;i<n;i++)for (int j=1;j<=m;j++){
		read(x);
		b[++bt].l=x;
		b[bt].xf=i;
		b[bt].yf=j;
		b[bt].xs=i+1;
		b[bt].ys=j;
	}
	for (int i=1;i<=n;i++)for (int j=1;j<m;j++){
		read(x);
		b[++bt].l=x;
		b[bt].xf=i;
		b[bt].yf=j;
		b[bt].xs=i;
		b[bt].ys=j+1;
	}d=bt;
	for (int i=1;i<=bt;i++)b1[i]=b[i];
	while (T--){
		for (int i=0;i<=n+1;i++)for (int j=0;j<=m+1;j++)f[i][j]=-1;
		read(k);bt=d;
		for (int i=1;i<=bt;i++)b[i]=b1[i];
		for (int i=1;i<=k;i++){
			read(x);read(p);read(t);
			b[++bt].l=x;
			if (p<=m){
				f[0][p]=t;
				b[bt].xf=0;
				b[bt].yf=p;
				b[bt].xs=1;
				b[bt].ys=p;
			}else if (p<=m+n){
				f[p-m][m+1]=t;
				b[bt].xf=p-m;
				b[bt].yf=m;
				b[bt].xs=p-m;
				b[bt].ys=m+1;
			}else if (p<=2*m+n){
				f[n+1][2*m+n+1-p]=t;
				b[bt].xf=n;
				b[bt].yf=2*m+n+1-p;
				b[bt].xs=n+1;
				b[bt].ys=2*m+n+1-p;
			}else{
				f[2*m+2*n+1-p][0]=t;
				b[bt].xf=2*m+2*n+1-p;
				b[bt].yf=0;
				b[bt].xs=2*m+2*n+1-p;
				b[bt].ys=1;
			}
		}ans=0;
		sort(b+1,b+bt+1,cmp);
		for (int i=1;i<=bt;i++){
			if (f[b[i].xf][b[i].yf]!=-1&&f[b[i].xs][b[i].ys]==-1)f[b[i].xs][b[i].ys]=f[b[i].xf][b[i].yf];
			else if (f[b[i].xf][b[i].yf]==-1&&f[b[i].xs][b[i].ys]!=-1)f[b[i].xf][b[i].yf]=f[b[i].xs][b[i].ys];
			else if (f[b[i].xf][b[i].yf]!=-1&&f[b[i].xs][b[i].ys]!=-1&&f[b[i].xf][b[i].yf]!=f[b[i].xs][b[i].ys])ans+=b[i].l;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
