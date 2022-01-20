#include<bits/stdc++.h>
#define mo 10000007
using namespace std;
int n,k;
int cnt=0;
char ch[105];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ch[i];
	}
	for(int i=1;i<=n;i++){
		if(ch[i]=="?"){
			cnt++;
		}
	}
	cout<<cnt%mo<<endl;
	return 0;
}
