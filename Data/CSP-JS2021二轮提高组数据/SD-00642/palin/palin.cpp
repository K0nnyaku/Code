#include<cstdio>
#include<cstring>
const int MAXA=5e5+5;
const int MAXN=1e6+5;
using namespace std;
int t,n,a[MAXN];
char op[MAXN],top=0;
int res[MAXN]={0},rtop=0;
char vis[MAXA]={0};
int check(int x,int l,int r){
	if(l==r){
		for(int i=1;i<=top;i++)printf("%c",op[i]?'R':'L');
		printf("L\n");
		return 1;
	}
	if(res[x]==a[l]){
		op[++top]=0;
		if(check(x-1,l+1,r))return 1;
		top--;
	}
	if(res[x]==a[r]){
		op[++top]=1;
		if(check(x-1,l,r-1))return 1;
		top--;
	}
	return 0;
}
int make(int x,int l,int r){
	if(!x)return check(n,l,r);
	if(!vis[a[l]]){
		op[++top]=0;
		res[++rtop]=a[l];
		vis[a[l]]=1;
		if(make(x-1,l+1,r))return 1;
		vis[a[l]]=0;
		rtop--;
		top--;
	}
	if(!vis[a[r]]){
		op[++top]=1;
		res[++rtop]=a[r];
		vis[a[r]]=1;
		if(make(x-1,l,r-1))return 1;
		vis[a[r]]=0;
		rtop--;
		top--;
	}
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		memset(vis,0,sizeof(vis));
		top=rtop=0;
		if(!make(n,1,n<<1))printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

