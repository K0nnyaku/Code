#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define N 100010
using namespace std;
struct air{
	int a,b;
	bool operator < (const air k) const {
		return a<k.a;
	}
};
struct point{
	int ap;
	int pl;
	int st;
	int num;
	bool operator < (const point a) const{
		return pl<a.pl;
	}
};
int n,m1,m2;
air a1[N];
air a2[N];
int ans;
vector<point>nums;
int go1[N];
int go2[N];
int num1[N];
int num2[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	if(m1+m2<=n){
		cout<<m1+m2;
		return 0;
	}
	for(int i=1;i<=m1;i++){
		cin>>a1[i].a>>a1[i].b;
	}
	for(int i=1;i<=m2;i++){
		cin>>a2[i].a>>a2[i].b;
	}
	if(n<=5000&&m1+m2<=5000){
		for(int i=1;i<=m1;i++){
			point t;
			t.num=i;
			t.ap=1;
			t.pl=a1[i].a;
			t.st=1;
			nums.push_back(t);
			t.pl=a1[i].b;
			t.st=-1;
			nums.push_back(t);
		}
		for(int i=1;i<=m2;i++){
			point t;
			t.num=i;
			t.ap=0;
			t.pl=a2[i].a;
			t.st=1;
			nums.push_back(t);
			t.pl=a2[i].b;
			t.st=-1;
			nums.push_back(t);
		}
		sort(nums.begin(),nums.end());
		for(int i=0;i<=n;i++){
			int ll=i;
			int rr=n-i;
			int an=0;
			memset(go1,0,sizeof(go1));
			memset(go2,0,sizeof(go2));
			for(int j=0;j<nums.size();j++){
				point t=nums[j];
				if(t.ap==0){
					if(t.st==1||go1[t.num]==1){
						ll-=t.st;
						if(ll==-1){
							ll=0;
							continue;
						}
						if(go1[t.num]==0){
							an++;
						}
						go1[t.num]=1;
					}
				}else{
					if(t.st==1||go2[t.num]==1){
						rr-=t.st;
						if(rr==-1){
							rr=0;
							continue;
						}
						if(go2[t.num]==0){
							an++;
						}
						go2[t.num]=1;
					}
				}
			}
			ans=max(ans,an);
		}
	}else{
		priority_queue<int,vector<int>,greater<int> >qu1;
		for(int i=1;i<=n;i++){
			qu1.push(i);
		}
		for(int i=1;i<=m1;i++){
			point t;
			t.num=i;
			t.ap=1;
			t.pl=a1[i].a;
			t.st=1;
			nums.push_back(t);
			t.pl=a1[i].b;
			t.st=-1;
			nums.push_back(t);
		}
		sort(nums.begin(),nums.end());
		for(int j=0;j<nums.size();j++){
			point t=nums[j];
			if(t.st==1&&!qu1.empty()){
				go1[t.num]=qu1.top();
				num1[qu1.top()]++;
				qu1.pop();
			}else if(t.st==-1&&go1[t.num]){
				qu1.push(go1[t.num]);
			}
		}
		priority_queue<int,vector<int>,greater<int> >qu2;
		for(int i=1;i<=n;i++){
			qu2.push(i);
		}
		nums.clear();
		for(int i=1;i<=m2;i++){
			point t;
			t.num=i;
			t.ap=0;
			t.pl=a2[i].a;
			t.st=1;
			nums.push_back(t);
			t.pl=a2[i].b;
			t.st=-1;
			nums.push_back(t);
		}
		sort(nums.begin(),nums.end());
		for(int j=0;j<nums.size();j++){
			point t=nums[j];
			if(t.st==1&&!qu2.empty()){
				go2[t.num]=qu2.top();
				num2[qu2.top()]++;
				qu2.pop();
			}else if(t.st==-1&&go2[t.num]){
				qu2.push(go2[t.num]);
			}
		}
		int an;
		for(int i=1;i<=n;i++){
			ans+=num2[i];
		}
		an=ans;
		for(int i=1;i<=n;i++){
			an-=num2[n-i+1];
			an+=num1[i];
			ans=max(ans,an);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
