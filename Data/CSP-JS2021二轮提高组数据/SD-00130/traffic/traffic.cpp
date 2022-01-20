#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1000000;
vector<int> t[N];
vector<int> c[N];
int n,m;
void dfs(int w,int fa){
	int pl=t[w].size();
	for(int i=0;i<pl;i++){
		int v=t[w][i];
		if(v==fa)continue;
		dfs(v,w);
	}
	return;
}
int main(){
	//I give up. 
	return 0;
} 
