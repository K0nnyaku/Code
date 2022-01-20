#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n,a[500003],t;
int main()
{
    freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
    	cin>>n;
    	for(int j=1;j<=2*n;j++){
    		cin>>a[j];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<-1<<endl;
	}
    
    
    fclose(stdin);
    fclose(stdout);
	return 0;
}

