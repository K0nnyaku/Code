#include<bits/stdc++.h>
using namespace std;
std::list<bool> oprl;
unsigned int num[500010];
bool vis[500010];
unsigned int ord[500010];
unsigned int n;
bool dfs(unsigned int now, unsigned int l, unsigned int r){
	if(now==n)return true;
	if(now<n/2){
		if(!vis[num[l]]){
			//cerr<<"L ";
			oprl.push_back(true);
			ord[now]=num[l];
			vis[num[l]]=true;
			//cerr<<num[l]<<endl;
			if(dfs(now+1, l+1, r))return true;
			vis[num[l]]=false;
			oprl.pop_back();
			//cerr<<"x ";
		}
		if(!vis[num[r]]){
			//cerr<<"R ";
			oprl.push_back(false);
			ord[now]=num[r];
			vis[num[r]]=true;
			//cerr<<num[r]<<endl;
			if(dfs(now+1, l, r-1))return true;
			vis[num[r]]=false;
			oprl.pop_back();
			//cerr<<"x ";
		}
	}
	else{
		if(num[l]==ord[n-1-now]){
			oprl.push_back(true);
			if(dfs(now+1, l+1, r))return true;
			oprl.pop_back();
		}
		if(num[r]==ord[n-1-now]){
			oprl.push_back(false);
			if(dfs(now+1, l, r-1))return true;
			oprl.pop_back();
		}
	}
	return false;
}

unsigned int t;

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	//cin>>t;
	scanf("%u", &t);
	while(t--){
		//cin>>n;
		scanf("%u", &n);
		n*=2;
		memset(num, 0, sizeof(unsigned int)*n);
		memset(vis, 0, sizeof(bool)*n);
		memset(ord, 0, sizeof(unsigned int)*n);
		oprl.clear();
		for(unsigned int i=0; i<n; i++)scanf("%u", num+i);//cin>>num[i];
		if(dfs(0, 0, n-1)){
			while(!oprl.empty()){
				//cout<<
				printf(oprl.front()?"L":"R");
				oprl.pop_front();
			}
			//cout<<endl;
			printf("\n");
		}
		else{
			//cout<<"-1"<<endl;
			printf("-1\n");
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

