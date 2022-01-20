#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define MM 10005
using namespace std;
typedef long long ll;
const ll mod =1e9+7;
char a[1005];
int len,n,k;
int check(int x){
	int ans=0,p=0;
	if(x>=len){
		int l=0,mu;
		for(int i=0;i<len;i++){
			if(a[i]=='*'){
				if(!l) return 0;
				mu++;
				if(mu>k) return 0;
			}
			if(a[i]=='('){
				mu=0;
				l++;
			}
			if(a[i]==')'){
				if(!l) return 0;
				l--;
				mu=0;
			}
		}
		if(!l)
			return 1;
		return 0;
	}
	for(int i=x;i<len;i++){
		if(a[i]=='?'){
			p=1;
			a[i]='(';
			ans+=check(i+1);

			a[i]=')';
			ans+=check(i+1);

			a[i]='*';
			ans+=check(i+1);
			p=1;
			a[i]='?';
			break;
		}
	}
	if(!p){
		return check(len+1);
	}
	return ans;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	len=strlen(a);
	cout<<check(0);
	return 0;
}
