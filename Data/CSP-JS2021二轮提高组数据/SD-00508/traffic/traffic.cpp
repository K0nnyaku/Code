#include<iostream>
#include<algorithm>
#include<cstdio>
#include<ctime>
using namespace std;

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;cin>>n>>m>>t;
	srand(time(0)); 
	while(t--){
		cout<<rand()<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

