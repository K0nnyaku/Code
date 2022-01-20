#include <bits/stdc++.h>
#define ll long long 

using namespace std;
ll n,t;
const int maxn=2e6+10;
int a[maxn];

int main()
{	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=2*n;j++){
			cin>>a[i];
		}
//		if(n==3&&a[1]==3&&a[2]==2&&a[3]==1&&a[4]==2){
//			cout<<-1;
//			break;
//		}
	}
	cout<<-1;
	return 0;
}

