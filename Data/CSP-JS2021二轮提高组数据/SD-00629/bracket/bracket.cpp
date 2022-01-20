#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n,m1,m2;
int ans=-2e9;
struct node{
	int start,end;
}a[100005],b[100005];
int cnt;
priority_queue<int> q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cout<<n*m-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
