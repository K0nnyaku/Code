#include<bits/stdc++.h>
using namespace std;
int a[505];
int n,k;
int ans;
const long long INT=1000000007;
int gan(char x){
	if(x=='('){
		return 1;
	}else if(x==')'){
		return 2;
	}else if(x=='*'){
		return 3;
	}else{
		return 4;
	}
}
bool check(int s){
	int sum=0;
	for(int i=1;i<=s;i++){
		if(a[i]==3){
			sum++; 
		}
	}
	if(sum==n){
		return true;
	}else{
		return false;
	}
}
void dfs(int s){
	if(s==n){
		if(check(s)){
			ans++;
			ans%=INT;	
		}
		return;
	}
	if(a[s]!=4){
		dfs(s+1);
	}else{
		for(int i=1;i<=3;i++){
			a[s]=i;
			dfs(s+1);
			a[s]=4;
		}
	}
} 
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	string x;
	cin>>x;
	for(int i=1;i<=n;i++){
		a[i]=gan(x[i-1]);
	}
	dfs(1);
	cout<<ans%INT<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??
*/
