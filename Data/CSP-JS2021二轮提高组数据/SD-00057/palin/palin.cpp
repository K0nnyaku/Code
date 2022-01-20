#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,t;
int a[2];
int b[2n]={0};
cin>>t>>endl>>n>>endl;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	fclose(stdin);
	fclose(stdout)
	for(int i=0;i<=n;i++){
		if(b[i]=0){
			b[i]=a[i];
			b[2n-i]=a[i];
			a[i]=0;
		}
	
	}
	if(b[i]=b[2n-i]){
		cout<<b[2n]
	}esle{
		cout<<-1;
	}
	return 0;
}

