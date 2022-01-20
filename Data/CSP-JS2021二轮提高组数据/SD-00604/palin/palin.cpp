#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<2*n;i++){
			cin>>a[i];
		}
		int flag=1;
		for(int i=0;i<n;i++){
			if(a[i]!=a[2*n-i-1]){
				flag=0;
				cout<<"-1";
				break;
			}
		}
		if(flag){
			for(int i=0;i<2*n;i++){
				cout<<"L";
			}
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
