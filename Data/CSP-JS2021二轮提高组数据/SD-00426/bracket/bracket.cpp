#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#define ll long long
using namespace std;
const int N=100000;
char arr[1000000],sta[1000000];
bool sas[1000000];
ll k,n,ans=0,head=0,isc[1000000],cnt=0;
bool pan(){
	for(int i = 0;i<=head;i++) sas[i]=0;
	head=0;
	if(arr[n]=='*') {
		return 0;
	}
	for(int i = 1;i<=n;i++){
		if(head<0) {
			return 0;
		}
		
		if(arr[i]=='('){
			sta[++head]='(';
			cnt++;
		}
		if(arr[i]==')'){
			if(sta[head]=='('){
				sas[head]=0;
				head--;
			} 
			else{
				sta[++head]=')';
			
			}
			cnt++;
		}
		if(arr[i]=='*'){
			isc[cnt]++;
			if(isc[cnt]>k){
			 return 0;
		}
			if(arr[i+1]=='*'){
				continue;
			} 
			
			if(sas[head]==1){
				if(arr[i+1]==')'){

				return 0;	
				}
			} else{
				sas[head]=1;
			}
		}
	}
	if(head!=0){
    return 0;
	} 
	return 1;
}
void dfs(int q){
	if(q==n+1){
//	for(int i = 1;i<=n;i++){
//			cout<<arr[i];
//			}
//			cout<<" ";
//			pan();
//			cout<<endl;
		if(pan()){
			ans=(ans+1)%1000000007;
			
		} 
		return;
	}
	if(arr[q]=='?'){
		for(int j = 1;j<=3;j++){
			if(j==1){
				arr[q]=')';
				dfs(q+1);
				arr[q]='?';
			}
			if(j==2){
				arr[q]='(';
				dfs(q+1);
				arr[q]='?';
			}
			if(j==3){
				arr[q]='*';
				dfs(q+1);
				arr[q]='?';
			}
		}
	} else{
		dfs(q+1);
	} 
	
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
