#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define maxn 10000
using namespace std;
int n,k;
string ori;
vector<char> coms;
int ans;
bool check(){
	if(coms.size()==0)return false;
	bool start=false;
	for(int i=0;i<coms.size();i++){
		if(coms[i]!='*')start=false;
		if(!start&&coms[i]=='*'){
			start=true;
			bool flag=false;
			for(int i=1;i<=k;i++)if(coms[i]!='*'){flag=true;break;}
			if(!flag)return false;
		}
		
	}
}
void dfs(int x,int kn){
	if(x>=n){
		
		if(check()){
			ans++;
			for(int i=0;i<coms.size();i++)cout<<coms[i];
			cout<<endl;
		}
		return;
	}
	if(ori[x]!='?'){
		coms.push_back(ori[x]);
		dfs(x+1,kn);
		coms.pop_back();
	}
	else{
		if(kn<k){
			coms.push_back('*');
			dfs(x+1,kn+1);
			coms.pop_back();
		}
		coms.push_back('(');
		dfs(x+1,kn);
		coms.pop_back();
		coms.push_back(')');
		dfs(x+1,kn);
		coms.pop_back();
	}
}
int main(){
	//freopen("bracket1.in","r",stdin);
	//freopen("","w",stdout);
	/*cin>>n>>k;
	cin>>ori;
	int nums=0;
	
	dfs(0,0);
	cout<<ans;*/
	k=2;
	coms.push_back('*');
	//coms.push_back('*');
	cout<<check();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
