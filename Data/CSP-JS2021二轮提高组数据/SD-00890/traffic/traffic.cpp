#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,k,sum=0;
int s;
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>k>>sum;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cin>>s;
		}
	}
	for(int i=1;i<=n;i++){
		sum+=rand()&(1-n*k)+1;
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
