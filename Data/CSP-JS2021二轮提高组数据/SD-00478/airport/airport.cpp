#include<bits/stdc++.h>
using namespace std;
struct plane{
	bool f1;
	bool f2;
};
long long ans;
long long n,m1,m2;
long long a[100005];
long long b[100005];
plane timetable[40000001][2];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	long long la=1;
	for(int i=1;i<=m1;i++){
		long long arr;
		long long le;
		cin>>arr;
		cin>>le;
		if(le>la){
			la=le;
		}
		timetable[arr][0].f1=1;
		timetable[le][1].f1=1;
		timetable[arr][0].f2=1;
		timetable[le][1].f2=0;
	}
	for(int i=1;i<=m2;i++){
		int arr;
		int le;
		cin>>arr;
		cin>>le;
		if(le>la){
			la=le;
		}
		timetable[arr][0].f1=0;
		timetable[le][1].f1=0;
		timetable[arr][0].f2=1;
		timetable[le][1].f2=0;
	}
	for(int i=0;i<=n;i++){
		long long s1=i,s2=n-i;
		long long sum=0;
		for(int j=1;j<=la;j++){
			if(timetable[j][0].f1&&s1>0&&timetable[j][0].f2){
				s1--;
				sum++;
			}else if(timetable[j][1].f1&&!timetable[j][1].f2){
				s1++;
				if(s1>i){
					s1=i;
				}
			}else if(!timetable[j][0].f1&&s2>0&&timetable[j][0].f2){
				s2--;
				sum++;
			}else if(!timetable[j][1].f1&&!timetable[j][1].f2){
				s2++;
				if(s2>n-i){
					s2=n-i;
				}
			}
		}
		if(sum>ans){
			ans=sum;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
