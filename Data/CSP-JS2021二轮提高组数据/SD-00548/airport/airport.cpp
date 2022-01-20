#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define maxn (100005)
using namespace std;
int n,m1,m2;
int ans;
struct nodes{
	int start;
	int ends;
	int v;
}nin[maxn],nout[maxn];
bool cmp(nodes a,nodes b){
	return a.start<b.start;
} 
bool cmp1(nodes a,nodes b){
	return a.ends<b.ends;
}
bool vis1[maxn];
int buc1[maxn];
bool vis2[maxn];
int buc2[maxn];
void test(){
	sort(nin+1,nin+1+m1,cmp);
	sort(nout+1,nout+1+m2,cmp);
	int po=1;
	for(int i=1;i<=m1;i++){
		if(!vis1[i]){
			po=i;
			buc1[++buc1[0]]=1;
			vis1[i]=1;
			for(int j=i+1;j<=m1;j++){
				if(!vis1[j]&&nin[po].ends<=nin[j].start){
					po=j;
					buc1[buc1[0]]++;
					vis1[j]=1;
				}
			}
		}
	}
	
	int po1=1;
	for(int i=1;i<=m2;i++){
		if(!vis2[i]){
			po1=i;
			buc2[++buc2[0]]=1;
			vis2[i]=1;
			for(int j=i+1;j<=m2;j++){
				if(!vis2[j]&&nout[po1].ends<=nout[j].start){
					po1=j;
					buc2[buc2[0]]++;
					vis2[j]=1;
				}
			}
		}
	}
	int anss=0;
	for(int i=0;i<=n;i++){
		anss=0;
		for(int j=1;j<=i;j++)anss+=buc1[j];
		for(int j=1;j<=(n-i);j++)anss+=buc2[j];
		ans=max(anss,ans);
	}
	cout<<ans;
}


int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int t1,t2;
	for(int i=1;i<=m1;i++){
		scanf("%d",&t1);
		scanf("%d",&t2);
		nin[i].start=t1;
		nin[i].ends=t2;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d",&t1);
		scanf("%d",&t2);
		nout[i].start=t1;
		nout[i].ends=t2;
	}
	test();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
