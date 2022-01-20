#include<iostream>
using namespace std;
int a;
int main(){
	int t,n;
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		for(int j=0;j<n*2;j++)
			cin >> a;
		for(int j=0;j<n;j++) cout << 'L';
		cout << endl;
	}
	return 0;
}
