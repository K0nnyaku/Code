#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<vector>
#define ll long long

using namespace std;
struct p{
	int first;
	int second;
};
int n,m1,m2;
p ib[100100];
p ob[100100];
bool cmp(p a1,p a2){return a1.first<a2.first;};
int main() {
	int ma;
	freopen("airport.in","r",stdin);	 
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)cin>>ib[i].first>>ib[i].second;
	for(int i=1;i<=m2;i++)cin>>ob[i].first>>ob[i].second;
	sort(ib+1,ib+m1,cmp);
	sort(ob+1,ob+m2,cmp);
	int fob,rob,rib;//r=remain,i=using
	vector<int> iob,iib;
	int o1,o2,t,flag;
	for(int fib=0;fib<=n;fib++){
	fob=n-fib,rob=fob,rib=fib;
	iob.clear(),iib.clear();
	o1=0,o2=0,t=0;
	for(int i=1;i<=m1;i++){
		flag=0;
		if (rib>0){
			t=ib[i].first;
			rib--;
			o1++;
			iib.push_back(ib[i].second);
			flag=1;
		};
		if (rib==0 and flag==0 and iib.size()!=0){
			t=ib[i].first;
			for(int ii=0;ii<=iib.size()-1;ii++){
				if (iib[ii]<t){
					iib.erase(iib.begin()+ii);
					rib++;
				};
			if (rib>0){
			t=ib[i].first;
			rib--;
			o1++;
			iib.push_back(ib[i].second);
			};	
			};
		};
	};
	for(int i=1;i<=m2;i++){
		flag=0;
		if (rob>0){
			t=ob[i].first;
			rob--;
			o2++;
			iob.push_back(ob[i].second);
			flag=1;
		};
		if (rob==0 and flag==0 and iob.size()!=0){
			t=ob[i].first;
			for(int ii=0;ii<=iob.size()-1;ii++){
				if (iob[ii]<t){
					iob.erase(iob.begin()+ii);
					rob++;
				};
			if (rob>0){
			t=ob[i].first;
			rob--;
			o2++;
			iob.push_back(ob[i].second);
			};	
			};
		};
	};
	//cout<<o1<<"       "<<o2<<endl;
	if(o1+o2>ma)ma=o1+o2;
	
	};
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

