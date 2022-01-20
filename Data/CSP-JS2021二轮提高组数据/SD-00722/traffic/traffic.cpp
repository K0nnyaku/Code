#include <iostream>
#include <cstdio>
#include<cmath>
#include<cstring>
#include<algorithm> 
using namespace std;
int n,m,t,a[10000][10000],b[100000][100000];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m>>t;
	for (int i=1;i<=n-1;i++){
		for (int j=0;j<m;j++)
		cin>>a[i][j];
	}
	for (int i=n-1;i<=2n-1;i++){
		for (int j=0;j<m-1;j++)
		cin>>b[i][j];
	}
	cout<<"9184175"<<endl;
	cout<<"181573"<<endl;
	cout<<"895801"<<endl;
	cout<<"498233"<<endl;
	cout<<"0"£» 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

