#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,k;
long long sz[505],wz,nw;
long long a[505],sl,zkh,lxl,ans;
string s;
long long pd(){
	zkh=0;
	lxl=0;
	nw=0;
	for(int i=0;i<sl;i++){
		if(a[i]==1){
			zkh++;
			lxl=0;
		}else if(a[i]==2){
			zkh--;
			lxl=0;
		}else if(a[i]==3){
			lxl++;
		}else if(a[i]==4){
			if(sz[nw]==1){
				zkh++;
				lxl=0;
			}else if(sz[nw]==2){
				zkh--;
				lxl=0;
			}else if(sz[nw]==3){
				lxl++;
			}
			nw++;
		}
		if(zkh<0||lxl>k){
			return 0;
		}
	}
	if(zkh>0){
		return 0;
	}
	return 1;
}
void dfs(long long wz,long long mb){
	if(wz==mb){
		if(pd()==true){
			ans++;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		sz[wz]=i;
		dfs(wz+1,mb);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	scanf("%lld%lld",&n,&k);
	cin>>s;
	sl=s.length();
	for(int i=0;i<sl;i++){
		if(s[i]=='?'){
			wz++;
			a[i]=4;
		}else if(s[i]=='('){
			a[i]=1;
		}else if(s[i]==')'){
			a[i]=2;
		}else if(s[i]=='*'){
			a[i]=3;
		}
	}
	dfs(0,wz);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
