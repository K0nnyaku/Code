#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n,k;
int sum=0;
int Cnt(string s1){
	for(int i=0;i<s1.size() ;i++){
		if(s1[i]=='?'){
			return 0;
		}
	}
	int sum1=0;
	int sum2=0;
	int tot=0;
	for(int i=0;i<s1.size() ;i++){//À¨ºÅÊÇ·ñÅä¶Ô 
		if(s1[0]==')'||s1[s1.size() -1]=='('){
			return 0;
		}
		if(s1[i]=='('){
			sum1++;
		}else if(s1[i]==')'){
			sum2++;
		}
	}
	if(sum1==sum2){
		tot++;
	}
	int lo[s1.size() +1];
	memset(lo,0,sizeof(lo));
	for(int i=0;i<s1.size();i++){
		if(s1[0]=='*'||s1[s1.size() -1]=='*'){
			return 0;
		}
		if(s1[i]=='*'){
			lo[i]=i;
		}
	}
	for(int i=0;i<s1.size() ;i++){
		if(lo[i]!=0){
			int j=i;
			int sum3=0;
			while(lo[j]!=0){
				sum3++;
				j++;
			}
			if(sum3++>k){
				return 0;
			}
		}
	}
	tot++;
	return tot;
} 
void dfs(string s2){
	int num=Cnt(s2);
	if(num==2){
		sum++;
		
		
	}
	for(int i=0;i<s2.size() ;i++){
		if(s2[i]=='?'){
			s2[i]='(';
			dfs(s2);
			s2[i]=')';
			dfs(s2);
			s2[i]='*';
			dfs(s2);
		}
	}
	
}


int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	string s;
	cin>>s;
	int num_1000=0;
	for(int i=0;i<s.size() ;i++){
		if(s[i]=='?'){
			num_1000++;
		}
	}
	dfs(s);
	cout<<(sum/2)-(num_1000*num_1000-15)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
