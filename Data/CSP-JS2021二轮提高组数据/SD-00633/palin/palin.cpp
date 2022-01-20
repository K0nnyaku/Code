#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
#define ll long long
int sa,ea;
string c;
char z;
int n;
bool huiwen(string s){
	for(int i=0;i<n;i++){
		if(s[i]!=s[2*n-1-i]){
			return false;
		}
	}
	return 1;
}
void xxs(string &a,string &b,string &c,int ea,int sa){
	if(b.length()==2*n&&huiwen(b)){
	    cout<<c;
	}else{
		xxs(a,b+=a[ea],c+='L',ea-1,sa);	
		xxs(a,b+=a[sa],c+='R',ea,sa+1);
	}
}
int main(){
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	cin>>n;
	int sa=0;
	for(int i=0;i<n;i++){
		int x;
		string a,b="";
		cin>>x;
		for(int j=0;j<2*x;j++){
			cin>>z;
			a+=z;
		}
		ea=a.size()-1;
		xxs(a,b,c,ea,sa);
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
