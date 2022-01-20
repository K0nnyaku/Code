#include <iostream> 
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,s;
long long a[5000001],b[5000001];
char ans[100003];
bool fl=0,book[100000001];
bool hui(long long ss[],long long end){
	if(end%2==0){
		for(int i=1;i<=end/2;i++){
	    	if(ss[i]!=ss[end-i+1])return 0;
    	}
	}
	else{
		for(int i=1;i<=end/2-1;i++){
	    	if(ss[i]!=ss[end-i+1])return 0;
    	}
	}
	return 1;
}
void dfs(long long s1[],long long s2[],long long starta,long long enda,int st){
	
	if(st>2*s){
		if(hui(s2,st-1)){
			for(int k=1;k<=s*2;k++)cout<<ans[k];
			cout<<endl;
			fl=1;
		}
		return;
	}
	
	
	s2[st]=s1[starta];
//	cout<<"    "<<st<<"    ";
//	for(int k=1;k<=st;k++)cout<<s2[k]<<" ";
//	cout<<endl;
	ans[st]='L';
	dfs(s1,s2,starta+1,enda,st+1);
	if(fl==1)return;
	
	s2[st]=s1[enda-1];
//	cout<<"    "<<st<<"    ";
//	for(int k=1;k<=st;k++)cout<<s2[k]<<" ";
//	cout<<endl;
	ans[st]='R';
	dfs(s1,s2,starta,enda-1,st+1);
	if(fl==1)return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		fl=0;
		for(int j=1;j<=500000;j++)a[j]=0;
		cin>>s;
		for(int j=1;j<=2*s;j++){
			cin>>a[j];	
		}
		dfs(a,b,1,s+1+s,1);
		if(fl==0)cout<<-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
