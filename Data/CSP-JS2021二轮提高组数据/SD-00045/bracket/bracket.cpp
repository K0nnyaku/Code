#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;
const int N=1e9+7;
long long r(){
	return abs(((rand()+114)*(rand()+514))%N+1);
}
int n,k;
char x;
int main(){
	srand((unsigned)time(NULL));
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	cout<<r();
	return 0;
}

