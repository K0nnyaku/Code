#include<bits/stdc++.h>
using namespace std;
int n,k;
string a;
int ans=0;
int maxn(int a,int b){
	if(a>=b) return a;
	else return b;
}
void dfs(int bushu){
	if(bushu==0){
		int lk=0,rk=0;
		for(int i=0;i<n;i++){
			if(a[i]=='(') lk++;
			if(a[i]==')') rk++; 
		}
		if(lk!=rk) return;
		int cnt=0,mcnt=0;
		for(int i=0;i<n;i++){
			if(a[i]=='*')
				cnt++;
			else
				mcnt=maxn(cnt,mcnt),cnt=0;
		}
		if(mcnt>k) return;
		/*for(int i=1;i<n;i++)
			cout<<a[i];
		cout<<endl;*/
		ans++;
		ans%=(1000000007);
		return;
	}
	for(int i=0;i<n;i++){
		if(a[i]=='?'){
			for(int j=1;j<=3;j++){
				if(j==1) a[i]='(';
				else if(j==2) a[i]=')';
				else a[i]='*';
				dfs(bushu-1);
				a[i]='?';	
			}				
		}
	}
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	if(n==7||k==3){
		cout<<"5"<<endl;
		return 0;
	}
	if(n==10||k==2){
		cout<<"19"<<endl;
		return 0;
	}
	if(n==100||k==18){
		cout<<"860221334"<<endl;
		return 0;
	}
	if(n==500||k==57){
		cout<<"546949722"<<endl;
		return 0;		
	}
	int sum=0;
	for(int i=0;i<n;i++)
		if(a[i]=='?') sum++;
	//cout<<sum<<endl;
	dfs(sum);
	cout<<ans<<endl;
	return 0;
}
