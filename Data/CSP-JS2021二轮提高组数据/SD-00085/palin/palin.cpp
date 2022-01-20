#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int _;
	cin>>_;
	while(_--){
		vector<int> v;
		vector<int> b;
		int n;
		int head=0;
		int tail=2*n-1;
		cin>>n;
		for(int i=1;i<=2*n;i++){
			int p;
			cin>>p;
			v.push_back(p);
		}
		b.push_back(v[head++]);
		for(int i=0;i<2*n;i++){
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
