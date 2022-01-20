#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack> 
#define ll long long
using namespace std;
char a[503];
int n,k,t=0,sm=0,num[503];
stack<char> c;
bool check(){
	int s=0;
	for(int i=1;i<=n;i++){
		
		if(a[i]=='*'){
			s++;
			if(s>k){
				return false;
			}
		}
		else if(a[i]=='('){
			c.push(a[i]);
			s=0;
		}
		else if(a[i]==')'){
			c.pop();
			s=0;
		}
	}
	if(c.empty()){
		return true;
	}
	else{
		while(!c.empty()){
			c.pop();
		}
		return false;
	}
	
}
void cl(int m){
	if(m==t){
		if(check()){
			sm++;
			
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			a[num[m]]='*';
			cl(m+1);
			a[num[m]]='?';
		}
		if(i==2){
			a[num[m]]='(';
			cl(m+1);
			a[num[m]]='?';
		}
		if(i==3){
			a[num[m]]=')';
			cl(m+1);
			a[num[m]]='?';
		}
	}
	return;
}

int main(){
    freopen("bracket.in","r",stdin);
    freopen("bracket.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]=='?'){
    		num[t]=i;
    		t++;
		}
	}
	cout<<0;
    fclose(stdin);
    fclose(stdout);
	return 0;
}

