#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define ll long long
const int maxn=1e6+1;
using namespace std;
int n;
int m,mm;
int ans=0;
int num1=1,num2=1,num3,num4,sum;
struct node{
	ll begin;
	ll end;
}a[100001],b[100001];
bool cmp(node a,node b){
	return a.begin<b.begin;
}
int main(){
	freopen("airport","r",stdin);
	freopen("airport","w",stdout);
	cin>>n>>m>>mm;
	for(int i=1;i<=m;i++)
	    cin>>a[i].begin>>a[i].end;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=mm;i++)
	    cin>>b[i].begin>>b[i].end;
	sort(a+1,a+n+1,cmp);
	int sum=1;
	int y=a[sum].end;
	int yy=b[sum].end;
	while(n--){
		for(int i=2;i<=m;i++){
			if(a[i].begin<y) continue;
			if(a[i].begin>y){
				y=a[i].end;
				a[i].begin=0;
				a[i].end=0;
				num1++;
			} 
		}
		for(int j=2;j<=mm;j++){
			if(b[j].begin<yy) continue;
			if(b[j].begin>yy){
				yy=b[j].end;
				b[j].begin=0;
				b[j].end=0;
				num2++;
			}
		}
		if(num1>num2) {
		    if(num1>num3) ans+=num1;
		    else if(num1<num3) {
		    	ans+=num3;
		    	num3=1;
			}
			num2=num3;
		}
		else if(num1<num2){
			if(num2>num4) ans+=num2;
			else if(num1<num4){
				ans+=num4;
				num4=1;
			} 
			num1=num4;
		}
		else 
			ans+=num1;
		num1=1;
		num2=1;
		y=a[sum++].end;
		yy=b[sum++].end;
	}
	cout<<ans<<endl;
	return 0;
}
