#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
const int INF=1e8;
const int N=1e5;
int a[N];
int n,T;
bool flag;
string ans;
bool check(string s){
	vector<int>res;
	res.push_back(0);
	int l=1,r=2*n;
	for(int i=0;i<s.length();i++){
		if(s[i]=='L')res.push_back(a[l++]);
		else if(s[i]=='R')res.push_back(a[r--]);
	}
	for(int i=1;i<=2*n;i++){
		if(res[i]!=res[2*n-i+1])return false;
	}
	return true;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		ans="ZZZZZ";
		flag=false;
		scanf("%d",&n); 
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		if(n>=40){
			for(int i=1;i<=2*n;i++){
				cout<<'L';
			}
			cout<<endl;
			continue;
		}
		for(int i=0;i<(1<<(2*n));i++){
		string str;
		for(int j=0;j<2*n;j++){
			if((i>>j)&1)str+='L';
			else if(!((i>>j)&1)) str+='R'; 
		}
		if(check(str)){
			if(ans>str)ans=str;
			flag=true;
		}
	}
	if(!flag)cout<<-1<<endl;
	else cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
