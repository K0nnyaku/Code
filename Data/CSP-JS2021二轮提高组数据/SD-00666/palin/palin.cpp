#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
long long T,n,m,a[10010],b[10010];
bool v[10010];
string mix="";
bool pd(){
	for(long long i=1;i<=n;i++){
//		cout<<i<<" "<<2*n-(i-1)<<endl;
		if(b[i]!=b[2*n-(i-1)]){
			return false;
		}
	}
	return true;
}
//1 2n 2 2n-1 3 2n-2
void dfs(long long id,string s){
	if(id==2*n+1){
		if(pd()){
			mix=min(mix,s);
		}
//		cout<<s<<endl;
		return;
	}
	if(id>2*n){
		return;
	}
	if(s>mix){
		return;
	}
	for(long long i=1;i<=2*n;i++){
		if(!v[i]){
			v[i]=1;
			b[id]=a[i];
			dfs(id+1,s+'L');
			v[i]=0;
			break;
		}
	}
	for(long long i=2*n;i>=1;i--){
		if(!v[i]){
			v[i]=1;
			b[id]=a[i];
			dfs(id+1,s+'R');
			v[i]=0;
			break;
		}
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(a,0,sizeof(a));
		scanf("%lld",&n);
		mix="l";
		for(long long i=1;i<=2*n;i++){
			scanf("%lld",&a[i]);
		}
		dfs(1,"");
		if(mix=="l"){
			cout<<"-1"<<endl;
		}else{
			cout<<mix<<endl;
		}
//		pd();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
