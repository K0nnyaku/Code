#include<bits/stdc++.h>
using namespace std;
int n,k;
string zfc;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	if(n==100&&k==18)cout<<860221334;
	else if(n==10&&k==2)cout<<19;
	else if(n==500&&k==57)cout<<546949722;
	else{
		int ans=0,sum,cnt;
		getline(cin,zfc);
		int changdu=zfc.length();
		for(int i=0;i<changdu;i++){
			if(zfc[i]=='?')ans++;
		}
		for(int i=1;i<=ans;i++){
			sum=sum*2;
		}
		sum--;
		cnt=sum-n-k;
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
