#include<bits/stdc++.h>
using namespace std;
#define udm unordered_map
int _,n;
vector<int> a,s;
vector<char> option;
void dfs(int now=0,int l=0,int d=2*n-1){
	if(now==2*n){
		if(s[2*n-1]==s[0])
			throw 1;
		return ;
	}
	else if(now>n)
		if(s[now-1]!=s[2*n-now])
			return;
	if(l<2*n-1){
		s[now]=a[l];
		option[now]='L';
		dfs(now+1,l+1,d-1);
	}
	if(d>0){
		s[now]=a[l+d];
		option[now]='R';
		dfs(now+1,l,d-1);
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>_;
	while(_--){
		a.clear();
		s.clear();
		option.clear();
		cin>>n;
		a.resize(2*n);
		s.resize(2*n);
		option.resize(2*n);
		for(int i=0;i<2*n;i++)
			cin>>a[i];
		try{
			dfs();
		}
		catch(int result){
			for(int i=0;i<2*n-1;i++)
				cout<<option[i];
			cout<<'L'<<endl;
			continue;
		}
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
