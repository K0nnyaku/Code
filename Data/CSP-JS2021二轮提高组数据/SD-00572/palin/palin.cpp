#include <bits/stdc++.h>
using namespace std;
long long t,n,a[1000010],s[1000010],b[1000010],f[1000010];
long long dfs(long long li,long long ri){
	long long st=n*2+li-ri;
	if(li>ri){
		return 1;
	}
	if(li==ri){
		s[st]=1;
		return 1;
	}
	if(st<=n){
		if(f[a[li]]==0){
			f[a[li]]=1;
			s[st]=1;
			b[st]=a[li];
			if(dfs(li+1,ri)==1){
				return 1;
			}
			f[a[li]]=0;
		}
		if(f[a[ri]]==0){
			f[a[ri]]=1;
			s[st]=2;
			b[st]=a[ri];
			if(dfs(li,ri-1)==1){
				return 1;
			}
			f[a[ri]]=0;
		}
	}
	if(st>=n){
		if(a[li]==b[n*2-st+1]){
			s[st]=1;
			if(dfs(li+1,ri)==1){
				return 1;
			}
		}
		if(a[ri]==b[n*2-st+1]){
			s[st]=2;
			if(dfs(li,ri-1)==1){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			f[i]=0;
		}
		for(int i=1;i<=n*2;i++){
			cin>>a[i];
		}
		if(dfs(1,n*2)==0){
			cout<<"-1\n";
		}else{
			for(int i=1;i<=n*2;i++){
				cout<<(s[i]==1?"L":"R");
			}
			cout<<endl; 
		}
	}
	return 0;
}
