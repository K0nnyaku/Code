#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+10;
int t,n,a[N],b[N];
int l,r,step[N];//1->L  2->R
bool ifend;
bool judge(){
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(b[i]!=b[(2*n+1-i)]){
			flag=false;
			break;
		}
	}
//	for(int i=1;i<=(2*n);i++) printf("%d %d  ",step[i],b[i]);
//	printf("%c\n",flag?'T':'F');
	return flag;
}
void chprint(){
	for(int i=1;i<=(2*n);i++){
		if(step[i]==1) printf("L");
		else printf("R");
	}
	printf("\n");
}
void dfs(int point){
	if(point==(2*n+1)){
		if(judge()){
			chprint();
			ifend=true;
			return;
		}
	}else{
		b[point]=a[l];
		l++;
		step[point]=1;
		dfs(point+1);
		b[point]=0;
		l--;
		step[point]=0;
		if(ifend) return;
		b[point]=a[r];
		r--;
		step[point]=2;
		dfs(point+1);
		b[point]=0;
		r++;
		step[point]=0;
		if(ifend) return;
	}
}
void sinit(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(step,0,sizeof(step));
	ifend=false;
	l=1,r=2*n;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sinit();
		for(int i=1;i<=(2*n);i++){
			scanf("%d",&a[i]);
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[(2*n+1-i)]){
				flag=false;
				break;
			}
		}
		if(flag){
			for(int i=1;i<=(2*n);i++) printf("L");
			printf("\n");
			continue;
		}
		dfs(1);
		if(!ifend) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
