#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#define long long ll
#define unsigned long long usll
using namespace std;
int a[1000010];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cout<<"L";
		}
		for(int i=1;i<=n;i++){
			cout<<"R";
		}
		cout<<endl; 
	}

	fclose(stdin);
	fclose(stdout);
}
