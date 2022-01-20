#include<bits/stdc++.h>
namespace MAIN{

using namespace std;
typedef long long LL;
#define pii pair<int,int>
#define fs first
#define sc second
const int N=1.1e4,mod=998244353;
int a[N],n,b[N];
bool opt[N];
void print(){
	for(int i=1;i<=n*2;i++)putchar(opt[i]==0?'L':'R');
	putchar('\n');
}
void dfs(int l,int r){
	if(l>r){print();throw 0;}
	int k=2*n-(r-l+1);
	if(k<=n||a[l]==b[2*n+1-(k+1)])opt[k+1]=0,b[k+1]=a[l],dfs(l+1,r);//L
	if(k<=n||a[r]==b[2*n+1-(k+1)])opt[k+1]=1,b[k+1]=a[r],dfs(l,r-1);//R
}
void work(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)scanf("%d",a+i);
	try{dfs(1,2*n);}
	catch(int){return;}
	puts("-1");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)work();
	return 0;
}

}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	MAIN::main();
	return 0;
}

