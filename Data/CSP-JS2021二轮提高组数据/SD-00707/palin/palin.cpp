#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector> 
#include<ctime>
#include<cstdlib>

using namespace std;

typedef unsigned long long ull; 
typedef pair<int,int> PII;
typedef long long ll;

const int N=1e6+5;

int t;
int n;
int a[N];
int b[N];
char tmp[N];
char ans[N];
bool flag;
bool cutt;
int vis[N];

int read(){
	int a=0,b=1;
	char ch=getchar();
	while((ch<'0' || ch>'9') && ch!='-'){
		ch=getchar();
	}
	if(ch=='-')
	{
		b=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a*b;
}

bool check(){
	for(int i=1;i<=n;i++){
		if(b[i]!=b[2*n-i+1]) return false;
	}
	return true;
}
void dfs(int tou,int wei,int s){
	if(cutt && s<=n+1) return ;
	if(s>n+1){
		if(b[s-1]!=b[n+n+2-s]) return ;
	}
	if(ans[s-1]<tmp[s-1]) return ;//不是最优 
	if(s==2*n+1){
		if(check()){
			flag=1;
			for(register int i=1;i<=2*n;i++){
				ans[i]=tmp[i];
			} 
		}
		return ;
	}
	
	b[s]=a[tou];
	tmp[s]='L';
	vis[b[s]]++;
	if(vis[b[s]]>1){
		cutt=1;
	}
	dfs(tou+1,wei,s+1);
	cutt=0;
	vis[b[s]]--;
	
	b[s]=a[wei];
	tmp[s]='R';
	vis[b[s]]++;
	if(vis[b[s]]>1){
		cutt=1;
	}
	dfs(tou,wei-1,s+1);
	cutt=0;
	vis[b[s]]--;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		flag=0;
		n=read();
		cutt=0;
		for(register int i=1;i<=2*n;i++){
			vis[i]=0;
			ans[i]='Z';
			a[i]=read();
		}
		dfs(1,2*n,1);
		if(!flag) printf("-1\n");//a序列的头、尾、执行次数 
		else{
			for(register int i=1;i<=2*n;i++){
				printf("%c",ans[i]);
			}
			printf("\n");
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
//21!9-324@emb

