#include<iostream> //40pts
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m1,m2,x,maxn=-1;
int num1[N],num2[N],bk[N],dk[N];
struct xxs{
	int l,r;
}d1[N],d2[N];
bool cmp(xxs a,xxs b){
	return a.l<b.l;
}
void cl1(){
	int x;
	for(int k=1;k<=n;k++){
		x=0;
		for(int i=1;i<=m1;i++){
			if(bk[i]==0&&x<=d1[i].l){
				num1[k]++;
				x=d1[i].r;
				bk[i]=1;
			}
		}
		num1[k]+=num1[k-1];
		if(num1[k]==m1){
			x=k;
			break;
		}
	}
	for(int k=x+1;k<=n;k++)
		num1[k]=num1[x];
}
void cl2(){
	int x;
	for(int k=1;k<=n;k++){
		x=0;
		for(int i=1;i<=m2;i++){
			if(dk[i]==0&&x<=d2[i].l){
				num2[k]++;
				x=d2[i].r;
				dk[i]=1;
			}
		}
		num2[k]+=num2[k-1];
		if(num2[k]==m2){
			x=k;
			break;
		}
	}
	for(int k=x+1;k<=n;k++)
		num2[k]=num2[x];
}
int main(){
//	freopen("tst.txt","r",stdin);
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	if(n>=m1+m2){
		cout<<m1+m2<<endl;
		return 0;
	}
	for(int i=1;i<=m1;i++)
		cin>>d1[i].l>>d1[i].r;
	for(int i=1;i<=m2;i++)
		cin>>d2[i].l>>d2[i].r;
	sort(d1+1,d1+m1+1,cmp);
	sort(d2+1,d2+m2+1,cmp);
	cl1();
	cl2();
	for(int i=0;i<=n;i++)
		maxn=max(maxn,num1[i]+num2[n-i]);
	cout<<maxn<<endl;
	return 0;
} 
/*
5 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

*/
