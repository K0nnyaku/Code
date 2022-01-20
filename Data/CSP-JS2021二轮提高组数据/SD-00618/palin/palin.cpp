#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	/*freopen("palin.in","r",stdin)
	freopen("palin.out","w",stdout)*/
	
	int T,n,x;
	int a[]={};
	
	cin>>T;
	
	for(int i=1;i<=T;i++){
		cin>>n;
		i=n;
		for(int j=1;j<=2*n;j++){
			j+=n;
			continue; 
		}
	} 
	
	cout<<-1; 
	
	return 0;
} 
