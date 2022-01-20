//T3±©Á¦
#include<iostream>
using namespace std;
int n;
string ans="999999999999999999999999999999999999999999999999999999999999999999999999999";
string ans1;
char x[111];
inline bool check(string b){
	for(int i=0;i<n;i++)if(b[i]!=b[2*n-i-1])return false;
	return true;
}
void dfs(int a,string s,string b,int ft,int fr){
	
	if(a == 2*n){
		if(check(b)){
			if(b<ans){
			ans=b;ans1=s;}
		}
		return;	  
	}
	if(a > n+1 && (b[a-1]!=b[2*n-a]))return;
	
	dfs(a+1,s+"L",b+char(x[ft+1]),ft+1,fr);
	dfs(a+1,s+"R",b+char(x[fr-1]),ft,fr-1);
} 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;cin>>T;
	while(T--){
	ans="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
	ans1="";
	
	cin>>n;
	for(int i=0;i<2*n;i++){
		cin>>x[i];
	} 
	dfs(0,"","",-1,2*n);
	if(ans1 != "")cout<<ans1<<endl;
	else cout<<-1;}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
