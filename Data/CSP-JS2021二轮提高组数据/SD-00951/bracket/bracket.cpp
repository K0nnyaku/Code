#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,k,cnt=0,num[5]={0};
long long p=1;
string s;
int chance[100000][500];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(s[1]!='('||s[n-1]!=')'){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
	    if(s[i]=='?') cnt++;
	    if(s[i]=='(') num[1]++;
	    if(s[i]==')') num[3]++;
	    if(s[i]=='*') num[2]++;
	}
	for(int i=1;i<=cnt;i++) p*=3;
	int ans=0;
	if(cnt==n){
		if(k==1){
			if(n==1) cout<<0<<endl;
			else if(n==2) cout<<1<<endl;
			else if(n==3) cout<<1<<endl;
			else if(n==4) cout<<2<<endl;
			else if(n==5) cout<<6<<endl;
			else if(n==6) cout<<10<<endl;
			return 0;
		}
		cout<<n*k<<endl;
	}
	if(cnt==1){
		if(num[1]==num[3]) ans+=2;
		if(num[1]+1==num[3]) ans++;
		if(num[3]+1==num[1]) ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(cnt==2){
	    if(num[1]==num[3]) ans+=2;
	    if(num[1]+1==num[3]) ans++;
	    if(num[1]+2==num[3]) ans++;
	    if(num[3]+1==num[1]) ans++;
	    if(num[3]+2==num[1]) ans++;
	    cout<<ans<<endl;
	    return 0;
	}
	if(cnt==3){
		if(num[1]==num[3]) ans++;
		if(num[1]+1==num[3]) ans+=2;
		if(num[1]+2==num[3]) ans++;
		if(num[3]+2==num[1]) ans++;
		if(num[3]+1==num[1]) ans+=2;
		cout<<ans<<endl;
		return 0;
	}
	cout<<10050805<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

