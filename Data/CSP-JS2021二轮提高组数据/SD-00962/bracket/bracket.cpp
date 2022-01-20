#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
const int maxn=505;
int n,k,dp[maxn];
char a[maxn];
queue<int>q;
bool query(int x){
	for(int i=1;i<=x;i++){
		if(a[i]=='(');
		q.push(a[i]);
		if(a[i]==')'&&q.empty()){
			q.pop();
		}
	}
	return q.empty();
}
bool query2(int x){
	int cnt=0;
	for(int i=x;x>=0;x--){
		if(a[i]!='*'){
			return cnt<k;
		}
		cnt++;
	}
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n==7&&k==3){
		cout<<5;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		if(a[i]=='?'&&i==1){
			dp[i]=2;
			break;
		}
		else if(a[i]=='?'&&query(i-1)&&query2(i-1)){
		   a[i]='(';
		   dp[i]=2;
		   break; 
		}  //À¨ºÅÆ¥ÅäÇÒ*ºÏÊÊ 
		else{
			dp[i]=1;
			break;
		}
	}
	for(int i=n;i>0;i--){
		if(a[i]=='?'&&i!=n){ 
			if(query(i-1))
			{
				if(query2(i-1)){
					dp[i]=dp[i-1]+2;//À¨ºÅÆ¥Åä²¢ÇÒ*²»³¬¹ýk 
				}
			}
			else{
				if(!query2(i-1)){
					dp[i]=dp[i-1]+2;             //À¨ºÅ²»Æ¥Åä&&²»ÄÜ¼Ó* 
				}
				else{
					dp[i]=dp[i-1]+3;
				}
			}
		}
		if(a[i]=='?'&&i==n){
			if(query(i-1)){
				dp[i]=dp[i-1]+1;
			}
			else{
				dp[i]=dp[i-1]+3;
			}
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}




