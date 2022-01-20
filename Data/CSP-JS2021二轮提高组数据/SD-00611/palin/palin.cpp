#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1,c=getchar();
	while(c>57||c<48){if(c=='-')f=-1;else f=1;c=getchar();}
	while(c<58&&c>47)x=(x<<1)+(x<<3)+c-48,c=getchar();
	return x*f;
}
int n,t,a[1000005],b[1000005];
bool solved,stp[1000005];//l0r1
void dfs(int l,int r){
	if(l>r){
		solved=1;
		for(int i=1;i<=n;++i)putchar(stp[i]?'R':'L');
		putchar('\n');
		return;
	}
	if(n-r+l>n>>1&&b[1+r-l]!=a[l]&&b[1+r-l]!=a[r])return;
	b[n-r+l]=a[l],stp[n-r+l]=0;
	if(n-r+l<=n>>1)dfs(l+1,r);
	else if(b[n-r+l]==b[1+r-l])dfs(l+1,r);
	if(solved)return;
	b[n-r+l]=a[r],stp[n-r+l]=1;
	if(n-r+l<=n>>1)dfs(l,r-1);
	else if(b[n-r+l]==b[1+r-l])dfs(l,r-1);
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		n=read()<<1,solved=0;
		for(int i=1;i<=n;++i)a[i]=read();
		if(n>50){
			printf("-1\n");
			continue;
		}
		dfs(1,n);
		if(!solved)printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
