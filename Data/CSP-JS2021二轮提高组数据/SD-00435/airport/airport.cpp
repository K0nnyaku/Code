#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
#include <vector>
#include <set>
using namespace std;
struct H{
	long long int l,r;
}a1[1000005],a2[1000005];
int cmp(H a,H b){
	return a.l<b.l;
}
long long int v1[1000005],v2[1000005],cnt1[1000005],cnt2[1000005],s1[1000005],s2[1000005],cc1[1000005],cc2[1000005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i].l>>a1[i].r;
	}  
	for(int i=1;i<=m2;i++){
		cin>>a2[i].l>>a2[i].r;
	}
	int now1,now2;
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	for(int i=1;i<=m1;i++){
		for(int j=1;j<i;j++){
			if(a1[j].r<=a1[i].l&&v1[j]==0){
				v1[j]=1;
				cnt1[i]++;
				s1[j]=i;
			}
		}
	}
	for(int i=1;i<=m2;i++){
		for(int j=1;j<i;j++){
			if(a2[j].r<=a2[i].l&&v2[j]==0){
				v2[j]=1;
				cnt2[i]++;
				s2[j]=i;
			}
		}
	}
	int maxn=INT_MIN;
	for(int i=0;i<=n;i++){
		now1=i;
		now2=n-i;
		int c=0;
		for(int j=1;j<=m1;j++){
			cc1[j]=cnt1[j];
		}
		for(int j=1;j<=m1;j++){
			now1+=cc1[j];
			if(now1>0){
				c++;
				now1--;
			}else{
				cc1[s1[j]]--;
			}
		}
		for(int j=1;j<=m2;j++){
			cc2[j]=cnt2[j];
		}
		for(int j=1;j<=m2;j++){
			now2+=cc2[j];
			if(now2>0){
				c++;
				now2--;
			}else{
				cc2[s2[j]]--;
			}
		}
		maxn=max(maxn,c);
	}
	cout<<maxn<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
