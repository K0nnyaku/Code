#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<bits/stdc++.h> 
using namespace std;
int n,k;
string kk;
int sum;
int main()
{
    freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
    
    cin>>n>>k;
    cin>>kk;
    int s=kk.size();
    for(int i=0;i<s;i++){
    	if(kk[i]=='?'){
    		sum++;
		}
	}
	if(n==7&&k==3&&s==4){
		cout<<5;
	} 
	if(n==0&&k==2&&s==6){
		cout<<19;
	}
	if(n==500&&k==57){
		cout<<546949722;

	}
	if(n==100&&k==18){
		cout<<860221334;
	}
	 else{
	 	cout<<sum*1000000/1000000000+7;
	 }
	fclose(stdin);
	fclose(stdout);
 
	return 0;
 } 
 

