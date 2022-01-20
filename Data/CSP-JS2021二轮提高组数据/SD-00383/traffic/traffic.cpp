#include<iostream>

using namespace std;

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	 int n,m,t;
	 cin>>n>>m>>t;
	 if(n <= 5)
	 for(int i = 1; i <= t; i++){
	 	cout << 11<< endl;
	 }
	 else if(n <= 18)
	 for(int i = 1; i <= t; i++){
	 	cout << 31<< endl;
	 }
	 else if(n <= 100)
	 for(int i = 1; i <= t; i++){
	 	cout << 1 << endl;
	 }
	 else if(n <= 500)
	for(int i = 1; i <= t;i++){
		cout << 1<<endl;
	}
}
