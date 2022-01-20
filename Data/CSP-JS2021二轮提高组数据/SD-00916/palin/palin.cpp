#include<bits/stdc++.h>
using namespace std;

vector<int> rea;
vector<int> ret;

int n;
int ans = 0;


int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	rea.push_back(0);
	vector<char> op;
	int n,tmp;
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 0;i < 2*n;i++){
			cin>>tmp;
			rea.push_back(tmp);
		}
		bool flag = true;
		for(int i = 1;i <= n;i++){
			if(rea[i] != rea[2*n+1-i]){
				flag = false;
				break;
			}
		}
		if(!flag)cout<<-1<<endl;
		else{
			while(n--){
				cout<<"LR";
			}
			cout<<endl;
		}
		
	}
	
	return 0;
}
