#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5+5;
int n;
int a[N<<1],b[N<<1],sub[N<<1];
bool flag=false;
void Init(){
	flag=false;
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(sub,0,sizeof sub);
}
void Print(){
	for(int i=1;i<=(n<<1);i++){
		if(sub[i]==1) printf("L");
		if(sub[i]==2) printf("R");
	}
	printf("\n");
}
bool check(){
	int i=1,j=2*n;
	while(i<=j){
		if(b[i]!=b[j]) return false;
		i++,j--;
	}
	return true;
}
void dfs(int num,int head,int tail){
	if(head>2*n || (!tail)) return ;
	if(flag) return ;
	if(num==2*n+1){
		if(check()){
			flag=true;
			Print();
		}
		return ;
	}
	b[num]=a[head];
	sub[num]=1;
	dfs(num+1,head+1,tail);
	b[num]=a[tail];
	sub[num]=2;
	dfs(num+1,head,tail-1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		Init();
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		dfs(1,1,2*n);
		if(!flag) printf("-1\n"); 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
