#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
const int maxn=100005;
int n,m_nei,m_wai;
int a_1[maxn],b_1[maxn],a_2[maxn],b_2[maxn],l1,l2;
int fang1,fang2,ti;
int ans[maxn],sum=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m_nei,&m_wai);
	l1=n,l2=n;
	for(int i=1;i<=m_nei;i++){
		scanf("%d%d",&a_1[i],&b_1[i]);
	}
	for(int i=1;i<=m_wai;i++){
		scanf("%d%d",&a_2[i],&b_2[i]);
	}
	if(m_nei+m_wai==n){
		printf("%d",n);
		return 0;
	}
	fang1=0,fang2=n;
	sort(a_1,a_1+m_nei);
	sort(a_2,a_2+m_wai);
	for(int i=1;i<=n+1;i++){
		l1=fang1,l2=fang2;
		for(int j=1;i<=n;j++){
			if(a_1[j]<a_2[j]){
				if(l1==0) continue;
				else{
					l1--;
					ans[i]++;
					ti=a_1[j];
				}
			}
			else if(a_2[j]<a_1[j]){
				if(l2==0) continue;
				else{
					l2--;
					ans[i]++;
					ti=a_2[j];
				}
			}
			else if(l1==0&&l2==0) continue;
			if(ti==b_1[j]) l1++;
			else if(ti==b_2[j]) l2++;
		}
		fang1++,fang2--;
	}
	for(int i=1;i<=n;i++){
		sum=max(ans[i],sum);
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
