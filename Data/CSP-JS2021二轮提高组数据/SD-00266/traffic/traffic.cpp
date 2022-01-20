#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m,T;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	for(int i=1,x;i<n;i++)
		for(int j=0;j<m;j++)cin>>x;
	for(int i=0,x;i<n;i++)
		for(int j=1;j<m;j++)cin>>x;
	for(int i=0;i<T;i++){
		int cnt0=0,cnt1=0,k;
		cin>>k;
		for(int i=0,a,b,c;i<k;i++){
			cin>>a>>b>>c;
			if(c==0)cnt0+=a;
			if(c==1)cnt1+=a;
		}cout<<min(cnt0,cnt1)<<endl;
	}return 0;
}
