#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,a2[21];
	cin>>t;
	int z=1;
	while(z<=t){
		int n;
		cin>>n;a2[z++]=2*n;
		int a[2*n];
	
		for(int i=1;i<=2*n;i++)cin>>a[i];
	
	}
	int x=1;
	while(x<=t){
		int y=a2[x++];
	   bool a1[y];
	   char b1[y];
	   for(int i=1;i<=y;i++){
		if(a1[i])b1[i]='L';
		else if(!a1[i])b1[i]='R';
	}
	for(int i=1;i<=y;i++)cout<<b1[i];
	cout<<endl; 
	
	}

	return 0;
} 

