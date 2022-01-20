#include<bits/stdc++.h>
#define LL long long
#define rep(i,l,r) for(int i = l;i<=r;++i)
#define reg register
#define IT iterator
#define pb(x) push_back(x)
using namespace std;
const int N = 1e5+10,p = 1;
const bool is_file = 0;
const string Name = "";


int a[N];
bool st[N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;cin>>t;
	while(t--){
		memset(st,0,sizeof st);
		int n;cin>>n;n*=2;
		rep(i,1,n){
			cin>>a[i];
			if(!st[a[i]]){
				cout<<'R';
				st[a[i]]=true;
			}else{
				cout<<'L';
			}
		}
		cout<<endl;
		
	}


	return 0;
}

