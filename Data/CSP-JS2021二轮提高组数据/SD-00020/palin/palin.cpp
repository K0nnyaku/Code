#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=1;i<=n+n;i++)
			cin>>a[i];
		if(n<=10) {
			bool flag=0;
			for(int i=0;i<(1<<(n+n));i++) {
				int cnt=0;
				int nowl=0,nowr=n+n+1;
				for(int j=(1<<(n+n-1));j>0;j/=2) {
					if(i&j)
						b[++cnt]=a[--nowr];
					else
						b[++cnt]=a[++nowl];
				}
				bool ok=1;
				for(int j=1;j<=n;j++)
					if(b[j]!=b[n+n-j+1]) {
						ok=0;
						break;
					}
				if(ok) {
					for(int j=(1<<(n+n-1));j>0;j/=2)
						cout<<((i&j)?"R":"L");
					cout<<endl;
					flag=1;
					break;
				}
			}
			if(!flag)
				cout<<-1<<endl;
		}
		else {
			bool flag=1;
			for(int i=1;i<=n;i++)
				if(a[i]!=a[n+n-i+1]) {
					cout<<-1<<endl;
					flag=0;
					break;
				}
			if(flag) {
				for(int i=1;i<=n+n;i++)
					cout<<"L";
				cout<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
