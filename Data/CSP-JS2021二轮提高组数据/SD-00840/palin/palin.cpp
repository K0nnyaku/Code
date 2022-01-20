#include<algorithm>
#include<cstring>
#include<cstdio>
#define ll long long
#define qwq 1000007
int t;
int n;
int a[qwq];
bool Flag;
int las[qwq];
int oa[qwq];
char ans[qwq];
inline void init(){
	for(int i=1;i<=n+n;++i)las[i]=0,oa[i]=0;
	Flag=0;
	return ;
}
void solve(int l1,int r1,int l2,int r2,int k){
//	printf("[%d,%d],[%d,%d]:%d\n",l1,r1,l2,r2,k);
	if(k>n+n){
		Flag=true;
		return ;
	}
	if(l1<=r1){
		if(oa[l1]==r1){
			ans[k]='L';
			ans[n+n-((l2-1-(r1+1)+1))]='L';
			solve(l1+1,r1-1,l2,r2,k+1);
			return ;
		}
		if(oa[l1]==l2){
			ans[k]='L';
			ans[n+n-((l2-1-(r1+1)+1))]='R';
			solve(l1+1,r1,l2+1,r2,k+1);
			return ;
		}
	}
	if(l2<=r2){
		if(oa[r2]==r1){
			ans[k]='R';
			ans[n+n-((l2-1-(r1+1)+1))]='L';
			solve(l1,r1-1,l2,r2-1,k+1);
			return ;
		}
		if(oa[r2]==l2){
			ans[k]='R';
			ans[n+n-((l2-1-(r1+1)+1))]='R';
			solve(l1,r1,l2+1,r2-1,k+1);
			return ;
		}
	}
	if(r1<l1&&r2<l2){
		Flag=true;
		return ;
	}
	return ;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n+n;++i){
			scanf("%d",&a[i]);
			if(las[a[i]])oa[i]=las[a[i]],oa[las[a[i]]]=i;
			else las[a[i]]=i;
		}
		ans[n+n]='L';
		ans[1]='L',solve(2,oa[1]-1,oa[1]+1,n+n,2);
		if(!Flag)ans[1]='R',solve(1,oa[n+n]-1,oa[n+n]+1,n+n-1,2);
		if(!Flag){
			printf("%d\n",-1);
		}
		else {
			for(int i=1;i<=n+n;++i){
				putchar(ans[i]);
			}
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
