#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector> 
using namespace std;
typedef pair<int,int> PII;
const int N=1e5;
int n,m1,m2;
int s[N];
int ans,maxn;
vector<PII>q1,q2;
void check(int num1,int num2){
	int res=0;
	memset(s,0,sizeof s);
	for(int i=0;i<m1;i++){
		PII t=q1[i];
		int l=t.first,r=t.second;
		for(int j=1;j<=num1;j++){
			if(s[j]<=l){
				res++;
				s[j]=r;
				break;
			}
		}
	}
	memset(s,0,sizeof s);
	for(int i=0;i<m2;i++){
		PII t=q2[i];
		int l=t.first,r=t.second;
		for(int j=1;j<=num2;j++){
			if(s[j]<=l){
				res++;
				s[j]=r;
				break;
			}
		}
	}
	ans=max(ans,res);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		q1.push_back(make_pair(l,r));
	}
	for(int i=1;i<=m2;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		q2.push_back(make_pair(l,r));
	}
	for(int i=0;i<=n;i++)check(i,n-i);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
