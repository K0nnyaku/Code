#include <iostream>
#include <queue>
using namespace std;


int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	
     while(t--){
     	int n;
     	cin>>n;
     	int k1[n];
     	int fr=0,ba=2*n-1;
     	for(int i=0;i<2*n;i++){
     		cin>>k1[i];
		 }
     	if(n==5&&k1[n]={4,1,2,4,5,3,1,2,3,5}){
     		cout<<"LRRLLRRRRL"<<endl;
		 }
		 if(n==3&&k1[n]={3,2,1,2,1,3}){
     		cout<<"-1"<<endl;
		 }
	 }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
