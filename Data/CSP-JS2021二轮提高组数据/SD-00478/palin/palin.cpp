#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long a[1000005];
long long at,ab,bb;
long long b[1000005];
char ans1[1000005];
char ans2[1000005];
long long sum;
bool check(){
	for(int i=1;i<=n;i++){
		if(b[i]!=b[2*n+1-i]){
			return false;
		}
	}
	if(sum==0){
		for(int i=1;i<=2*n;i++){
			ans1[i]=ans2[i];
		}
		return true;
	}
	bool f;
	for(int k=1;k<=2*n;k++){
		f=1;
		for(int i=1;i<k;i++){
			if(ans2[i]!=ans1[i]||ans2[k]>=ans1[k]){
				f=0;
				break;
			}	
		}
	}
	if(f){
		for(int i=1;i<=2*n;i++){
			ans1[i]=ans2[i];
		}
		return true;
	}else{
		return false;
	}
}
void dfs(int s){
	if(s==2*n){
		if(check()){
			sum++;
		}
		return;
	}
	for(int i=0;i<2;i++){
		if(i==0){
			b[bb]=a[at];
			at++;
			bb++;
			ans2[s]='L';
			dfs(s+1);
			bb--;
			at--; 
		}else{
			b[bb]=a[ab];
			ab--;
			bb++;
			ans2[s]='R';
			dfs(s+1);
			bb--;
			ab++;
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int x=0;x<t;x++){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		at=1;
		ab=2*n;
		bb=1;
		dfs(1);
	}
	if(sum==0){
		cout<<"-1"<<endl;
	}else{
		for(int i=1;i<=2*n;i++){
			cout<<ans1[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
