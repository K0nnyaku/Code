#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m1,m2;
struct line{
	int num;
	int end;
}na[100001],in[100001]={0};;

struct node{
	int b;
	int e;
}an[100001],ai[100001];
int cmp(node u,node v){
	return u.b<v.b;
}
int nl[100000001]={0};
int main(){
//	freopen("airport.in","w",stdout);
//	freopen("airport.in","r",stdin);
//	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>an[i].b>>an[i].e;
	}
	for(int i=0;i<m2;i++){
		cin>>ai[i].b>>ai[i].e;
	}
	sort(an,an+m1,cmp);
	sort(ai,ai+m2,cmp);
	int k=0;
	int f=false;
	for(int i=0;i<m1;i++){
		f=false;
		for(int j=1;j<=k;j++){
			if(an[i].b>na[j].end){
				na[j].num++;
				na[j].end=an[i].e;
				f=true;
				break;
			}
		}
		if(!f){
			na[++k].num++;
			na[k].end=an[i].e;
		}
	}
	k=0;
	for(int i=0;i<m2;i++){
		f=false;
		for(int j=1;j<=k;j++){
			if(ai[i].b>in[j].end){
				in[j].num++;
				in[j].end=ai[i].e;
				f=true;
				break;
			}
		}
		if(!f){
			in[++k].num++;
			in[k].end=ai[i].e;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		int number=0;
		for(int j=1;j<=i;j++){
			number+=na[j].num;
		}
		for(int j=1;j<=n-i;j++){
			number+=in[j].num;
		}
		ans=max(ans,number);
	}
	cout<<ans;
	return 0;
}
