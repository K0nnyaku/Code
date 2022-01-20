#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 1000005
#define M 10*N
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int num[5000005],wrong;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		int u;
		cin>>u;
		int n=u*2;
		for(int i=1;i<=n;i++){
			cin>>num[i];	
		}
		for(int i=1;i<=u;i++){
			if(num[i]!=num[n-i+1]) {
			cout<<-1<<endl;
			wrong=-1;
			break;
			}
		}
		if(wrong==-1) {
			wrong=0;
			continue;
		}
		else{
			for(int i=1;i<=u-1;i++){
				cout<<"LR";
			}
			cout<<"LL\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

