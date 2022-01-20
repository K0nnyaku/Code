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
int a[1005];
int p[1005],l,r;
int b[1005];
int n;
bool check(int x){
	if(x>2*n){
		for(int i=l,j=r;i<=j;i++,j--){
			if(b[i]!=b[j]) return false;
		}
		return true;
	}
	int p1=0,p2=0;
	p[x]=1;
	l--;
	b[l]=a[x];
	p1=check(x+1);
	if(p1) return true;
	l++;
	r++;
	p[x]=2;
	b[r]=a[x];
	return check(x+1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int i,j,k,t;
	cin>>t;
	for(int x=1;x<=t;x++){
		cin>>n;
		for(i=1;i<=n*2;i++){
			cin>>a[i];
		}
		l=501;r=500;
		if(check(1)){
			for(i=1;i<=n*2;i++){
				if(p[i]&1) putchar('L');
				else putchar('R');
			}
			putchar('\n');
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
