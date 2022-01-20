#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>

using namespace std;
const int N=100010;

int main(){
	freopen("palin.in ","r",stdin);
	freopen("palin.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int h[N];
		int n;cin>>n;int l=2*n;
		for(int i=0;i<l;i++) cin>>h[i];
		for(int i=0;i<n;i++){
			int k=l-i-1;
			if(h[i]!=h[k]) {
				cout<<-1;break;
			}
		
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

