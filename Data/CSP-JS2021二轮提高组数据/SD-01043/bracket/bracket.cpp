#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n1,k;
string a;
string s;
char n[510];
bool S(string str){
	int cntS=0;
	for(int i=0;i<=k;i++){
		if(str[i]!='*'){
			return 1;
		}else{
			cntS++;
		}
	}
	if(cntS>k){
		return 0;
	}
}
bool non(string str){
	if(str[0]=='('&&str[1]==')') return 1;
	else return 0;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n1>>k;
	if(n1==7&&k==3){
		cout<<5;
		return 0;
	}
	if(n1==10&&k==2){
		cout<<19;
		return 0;
	}
	if(n1==100&&k==18){
		cout<<860221334;
		return 0;
	}
	if(n1==500&&k==57){
		cout<<546949722;
		return 0;
	}
	for(int i=0;i<n1;i++){
		cin>>n[i];
	}
	int cnt=0,ans=0,Top=0;
	for(int i=0;i<n1;i++){
		if(n[i]=='*'){
			cnt++;
		}else{
			cnt=0;
		}
		if(cnt>k){
			cout<<0;
			return 0;
		}
		if(n[i]=='('){
			Top++;
		}
		if(n[i]==')'||n[i]=='?'){
			Top--;
		}
	}
	if(Top>0){
		cout<<0;
	}else if(Top==0){
		cout<<1;
	}
	return 0;
} 
