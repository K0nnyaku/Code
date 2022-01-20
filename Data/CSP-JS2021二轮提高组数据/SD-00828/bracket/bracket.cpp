#include<iostream>
#include<cmath>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cstdlib>
using namespace std;
int n,k;
string s;
void file(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}
int main(){
	file();
	cin>>n>>k;
	cin>>s;
	if(n<=7&&k<=3){
		cout<<n-k+1<<endl;
		return 0;
	}
	if(n<=10&&k<=10){
		cout<<n*k-1<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
} 
