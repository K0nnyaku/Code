#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000110
using namespace std;
struct node{
	int ll,rr;
}cc[N];
int T,n,tot;
int a[N];
int b[N];
int f,r;
bool oop[N],Fi;
int Stack[N],Top;
void INIT(){
	Top=0;
	tot=0;
	Fi=0;
}
void dfs(int dep){
	if(Fi){
		return ;
	}
	if(dep==(n<<1)+1){
		f=1,r=(n<<1);
		for(int i=1;i<=(n<<1);i++){
			if(!oop[i]){
				b[i]=a[f++];
			}
			else{
				b[i]=a[r--];
			}
		}
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(b[i]!=b[(n<<1)-i+1]){
				flag=0;
				break;
			}
		}
		if(!flag)return ;
		for(int i=1;i<=(n<<1);i++){
			if(oop[i]){
				printf("R");
			}
			else printf("L");
		}
		printf("\n");
		Fi=1;
		return ;
	}
	oop[dep]=0;
	dfs(dep+1);
	oop[dep]=1;
	dfs(dep+1);
}
inline int read(){
	int x=0,f=1;
	char cc=getchar();
	while(cc>'9'||cc<'0'){
		if(cc=='-'){
			f=-1;
		}
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		x=(x<<3)+(x<<1)+(cc^48);
		cc=getchar();
	}
	return x*f;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		INIT();
		n=read();
		for(int i=1;i<=(n<<1);i++){
			a[i]=read();
		}
		if(n<=25){
			dfs(1);
			if(!Fi){
				printf("-1\n");
			}
		}
		else{
			for(int i=1;i<=(n<<1);i++){
				Stack[++Top]=a[i];
				if(Stack[Top]==Stack[Top-1]){
					Top-=2;
				}
				if(Top==0){
					cc[++tot].rr=i;
				}
			}
			if(tot>2){
				printf("-1\n");
			}
			else if(tot==2){
				for(int i=1;i<=(cc[1].rr/2);i++){
					printf("L");
				}
				for(int i=1;i<=(n<<1)-cc[1].rr;i++){
					printf("R");
				}
				for(int i=1;i<=(cc[1].rr/2);i++){
					printf("L");
				}
				printf("\n");
			}
			else{
				for(int i=1;i<=(n<<1);i++){
					printf("L");
				}
				printf("\n");
			}
		}
	}
	return 0;
}
