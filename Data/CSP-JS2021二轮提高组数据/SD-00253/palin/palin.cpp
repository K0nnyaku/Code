#include <cstdio>
#include <algorithm>

using namespace std;

int n,n2;
int nums[1000011];

int inarr[1000011];
bool zan[1000011];
bool inied[500011];

bool dfs(int l,int r,int ini){
	if(ini == n2) return true;
	
	if((ini < n) ? (!inied[nums[l]]) : (inarr[n2 - 1 - ini] == nums[l])){
		inarr[ini] = nums[l];
		inied[inarr[ini]] = true;
		if(dfs(l + 1,r,ini + 1)){
			zan[ini] = false;
			inied[inarr[ini]] = false;
			return true;
		}
		inied[inarr[ini]] = false;
	}
	
	if((ini < n) ? (!inied[nums[r]]) : (inarr[n2 - 1 - ini] == nums[r])){
		inarr[ini] = nums[r];
		inied[inarr[ini]] = true;
		if(dfs(l, r - 1, ini + 1)){
			zan[ini] = true;
			inied[inarr[ini]] = false;
			return true;
		}
		inied[inarr[ini]] = false;
	}
	
	return false;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		n2 = 2*n;
		for(int i = 0;i < n2;++i){
			scanf("%s",nums + i);
		}
		if(!dfs(0,n2 - 1,0))
			puts("-1"); 
		else{
			for(int i = 0; i < n2;++i){
				putchar(zan[i] ? 'R' : 'L');
			}
			putchar('\n');
			}
	}
	
	fclose(stdout);
	fclose(stdin);
	
	return 0;
}
