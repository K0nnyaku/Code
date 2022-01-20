#include<bits/stdc++.h>
using namespace std;
char type[3]={'(',')','*'};
int num;
int cnt;
stack<char> s;
int ans;
int vis[1000006];
void dfs(string k,int pos){
	if(pos==k.length()){
		for(int i=0;i<s.size();i++){
			int o=s.top();
			s.pop();
			
		}
		ans++;
	}
	if(k[pos]!='?'){
		dfs(k,pos+1);
		return;
	}
	if(k[pos]=='(' and !vis[pos]) s.push('('),vis[pos]=1;
	if(k[pos]==')' and !vis[pos]) s.push(')'),vis[pos]=1;
	if(k[pos]=='*' and !vis[pos]){
		cnt++;
		if(cnt>=num){
			cnt--;
			return;
		}
	}
	if(k[pos]=='?' and !vis[pos]){
		for(int j=0;j<3;j++){
			k[pos]=type[j];
			vis[pos]=1;
			dfs(k,pos+1);
			vis[pos]=0;
		}
	}
	
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.in","w",stdout);
	string k;
	int l;
	cin>>l;
	cin>>num;
	cin>>k;
	dfs(k,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

*/

