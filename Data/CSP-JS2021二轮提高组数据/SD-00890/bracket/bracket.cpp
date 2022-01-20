#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,k,sum=0;
string s;
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		sum+=rand()&(1-1+k)+1;
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
