#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<algorithm> 
using namespace std;
int n,mlang1,mlang2;
int const N=1e5+5;
struct node{
	int stm;
	int etm;
};
priority_queue<int,vector<int>,greater<int> >en;
node a[N],b[N];
int end_t[N];
//queue<node>aa,bb;
bool cmp(node x,node y){
	return x.stm<y.stm;
}
int f1(int lang){
	while(!en.empty())en.pop();
	en.push(0);
	int n11=0;
	if(lang ==0){
		n11=0;
	}
	else {
		for(int i=0;i<mlang1;i++){
			if(en.size()<lang||a[i].stm>en.top()){
				n11++;
				en.push(a[i].etm);
			}
			while(en.size()>lang){
				en.pop();
			}
		}
	}
	return n11;
}
int f2(int lang){
	while(!en.empty())en.pop();
	en.push(0);
	int n22=0;
	if(lang ==0){
		n22=0;
	}
	else {
		for(int i=0;i<mlang2;i++){
			if(en.size()<lang||b[i].stm>en.top()){
				n22++;
//				cout<<"="<<b[i].stm<<endl;
				en.push(b[i].etm);
			}
			while(en.size()>lang){
			//	cout<<en.top()<<endl;
				en.pop();
			}
		}
	}
	return n22;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>mlang1>>mlang2; 
	for(int i=0;i<mlang1;i++){
		scanf("%d%d",&a[i].stm,&a[i].etm);
	}
	sort(a,a+mlang1,cmp);
	for(int i=0;i<mlang2;i++){
		scanf("%d%d",&b[i].stm,&b[i].etm);
	}
	sort(b,b+mlang2,cmp);
	int ll=0,rr=n;
	int mid,sum;
	for(int i=0;i<=n;i++){
		if(f1(i)+f2(n-i)>sum){
			sum=f1(i)+f2(n-i);
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
