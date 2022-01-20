//zhn 记住 你就是个大菜鸡 放平心态
//消注释！！！return 0！！！
//打暴力啊啊啊，别乱想正解，你想不出来
//实在不行直接打暴力，打完暴力之后“正解”和暴力分区
//别忘了用快读
//orz zrz qlr qyc zyz ljc zsy wyh wym lyt dln
//rp++
//sdsy nb！！！ 
#include<cstdio>

//28pts
//猜结论题肯定的 

int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int t; 
int n;
int a[1000010];
int ans[1000010];
char lasts[1000010];
int last[1000010];
bool flag=0;
char anss[1000010];

bool check(){
	for(int i=1;i<=n;i++){
		if(ans[i]!=ans[2*n-i+1]) return 0;
	}
	return 1;
}

bool check1(){
	for(int i=1;i<=n;i++){
		if((int)anss[i]<(int)lasts[i]) return 1;
		if((int)anss[i]>(int)lasts[i]) return 0;
	}
	return 0;
}

void dfs(int now,int kt,int jw){
	if(now==2*n+1){
		if(check()){
			if(check1()){
				for(int i=1;i<=2*n;i++) last[i]=ans[i];
				for(int i=1;i<=2*n;i++) lasts[i]=anss[i];
				flag=1;
			}
		}
		return;
	}
	ans[now]=a[kt];
	anss[now]='L';
	dfs(now+1,kt+1,jw);
	ans[now]=a[jw];
	anss[now]='R';
	dfs(now+1,kt,jw-1);
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) last[i]=100000000;
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=2*n;i++) lasts[i]='Z';
		flag=0;
		dfs(1,1,2*n);
		if(!flag) printf("-1\n");
		else{
			for(int i=1;i<=2*n;i++) printf("%c",lasts[i]);
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
