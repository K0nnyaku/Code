#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int a[N];

bool check(int n) {
	for(int i=n,j=n+1;i>=1;i--,j++) {
	if(a[i]!=a[j]) return false; 
}    return true;
}

int main() {
	freopen("palin.in","r",stdin); 
	freopen("palin.out","w",stdout); 
	int T;
	cin>>T;
	while(T--) {
		int n;cin>>n;
		for(int i=1;i<=n*2;i++) cin>>a[i];
		if(check(n)) {
			for(int i=1;i<=2*n;i++) cout<<"L";
			cout<<endl;
		}
	    else {
	    	cout<<-1<<endl;
	    	continue;
		}
	}
	return 0;
}
