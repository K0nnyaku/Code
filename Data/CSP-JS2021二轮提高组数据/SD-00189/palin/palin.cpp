#include<bits/stdc++.h>
using namespace std;
const int maxn=554514;
int t,n;
int num[maxn*2],choose[maxn],flag[maxn];
/*
1->left     2->right
*/
bool if_ans_found=false;
void dfs(int num_l,int num_r,int r){
	if(r>2*n){
		int c_l=1,c_r=2*n;
		while(c_l<=c_r){
			if(choose[c_l]==choose[c_r]) c_l++,c_r--;
			else {
				if_ans_found=true;
				break;
			}
		}
		return;
	}
	if(if_ans_found) return;
	choose[r]=num[num_l];
	flag[r]=1;
	dfs(num_l+1,num_r,r+1);
	if(if_ans_found) return;
	choose[r]=num[num_r];
	flag[r]=2;
	dfs(num_l,num_r-1,r+1);
} 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		n=0;
		if_ans_found=false;
		memset(num,0,sizeof(num));
		memset(choose,0,sizeof(choose));
		memset(flag,0,sizeof(flag));
		scanf("%d",&n);
		if(!t&&n>1000){
			printf("-1\n");
			return 0;
		}
		if(n>1000){
			for(int i=1;i<=(int)(n/2+0.5);++i) printf("L");
			for(int i=(int)(n/2+0.5);i<=n;++i) printf("R");
			return 0;
		}
		for(int i=1;i<=2*n;++i) scanf("%d",&num[i]);
		dfs(1,2*n,1);
		char L='L',R='R';
		if(!if_ans_found){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=2*n;++i) printf("%c",flag[i]==1 ? L : R);
		printf("\n");
	}
	return 0;
}
