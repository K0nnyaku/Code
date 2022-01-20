#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define maxn 30005
using namespace std;
int t;
int n;
int arr[maxn];
bool vis[maxn];
int buc[maxn];
string mins(string a,string b){
	if(a<b)return a;
	else return b;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(buc[i]!=buc[2*n+1-i]){
			return false;
		}
	}
	return true;
}
string coms="Z";
int head,tail;
void dfs(int x,string a){
	if(x==2*n){
		if(check()){
			coms=min(coms,a);
		}
		return;
	}
	if(!vis[head]){
		vis[head]=1;
		buc[++buc[0]]=arr[head];
		head++;
		dfs(x+1,a+"L");
		head--;
		buc[0]--;
		vis[head]=0;
	}
	if(!vis[tail]){
		vis[tail]=1;
		buc[++buc[0]]=arr[tail];
		tail--;
		dfs(x+1,a+"R");
		tail++;
		buc[0]--;
		vis[tail]=0;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		cin>>n;
		memset(arr,0,sizeof(arr));
		coms="Z";
		for(int i=1;i<=2*n;i++)scanf("%d",arr+i);
		head=1;
		tail=2*n;
		dfs(0,"");
		if(coms=="Z")cout<<"-1"<<endl;
		else cout<<coms<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
