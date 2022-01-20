#include<iostream>
#include<cstdio>
using namespace std;
int n;
string a;
string ans;
bool dfs(string se,string to){
	if(se.empty()){
		return true;
	}
	if(se.size()<=n){
		if(to[se.size()-1]==se[0]){
			ans+='L';
			if(dfs(se.substr(1,se.size()-1),to+se[0])){
				return true;
			}
			string::iterator it=ans.end();
			it--;
			ans.erase(it);
		}else if(to[se.size()-1]==se[se.size()-1]){
			ans+='R';
			if(dfs(se.substr(0,se.size()-1),to+se[se.size()-1])){
				return true;
			}
			string::iterator it=ans.end();
			it--;
			ans.erase(it);
		}
		return false;
	}else{
		ans.push_back('L');
		if(dfs(se.substr(1,se.size()-1),to+se[0])){
			return true;
		}
		string::iterator it=ans.end();
		it--;
		ans.erase(it);
		ans.push_back('R');
		if(dfs(se.substr(0,se.size()-1),to+se[se.size()-1])){
			return true;
		}
		it=ans.end();
		it--;
		ans.erase(it);
		return false;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		a.clear();
		for(int i=1;i<=2*n;i++){
			int tmp;
			cin>>tmp;
			a+=(char)(tmp+'0');
		}
		if(dfs(a,"")){
			cout<<ans<<endl;
		}else{
			cout<<-1<<endl;
		}
		ans.clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
