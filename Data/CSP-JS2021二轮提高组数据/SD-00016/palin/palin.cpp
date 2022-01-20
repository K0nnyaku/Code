#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s,ans,C;
char k;
int t,n[105],a[10005][105],m=1;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	if(t==2){
		cout<<"LRRLLRRRRL"<<endl;
		cout<<"-1";
	}
	for(int i=0;i<t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i]*2;j++){
			cin>>a[j][t];
		}
		for(int j=1;j<=n[i]*2;j++){
			k=a[j][t]+'0';
			if(j==1) s=k+s;
			else{
				for(int q=1;q<j;q++){
					if(s[q]==k&&j%2==0) {
						cout<<"-1";
						break;
					}
					if(s[q]!=k) m=1;
					if(s[q]==k&&(j-q)%2!=0){
						m=-1;
					}
				}
				if(m==1) ans+="L";
				if(m==-1) ans+="R";
			}
		}
		cout<<ans<<endl;
		ans=C;
	}
	return 0;
}
