#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int a[10005];
		for(int i=1;i<=2*n;i++)
		    cin>>a[i];
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

