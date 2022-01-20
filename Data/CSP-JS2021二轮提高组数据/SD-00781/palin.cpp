#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10000000];
int b[1000][1000];
string c;
string d;
int aaa(){
	int n=10;
	int bj=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[i][j]=0;
		}
		for(int j=0;j<i;j++){
			for(int k=j;k<n;k++){
				for(int l=k;l<j+k;l++)b[i][l]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<b[i][j]<<" ";
		cout<<endl;
	}
}
int main(){
//	cin>>c>>d;
    freopen("palin.in",r,cstdio);
	freopen("palin.out",w,cstdio);
//	int t;
//	scanf("%d",&t);
//	int b;
//	int n;
//	for(int i=0;i<t;i++){
//		scanf("%d",&n);
//		n*=2;
//		for(int j=0;j<n;j++) scanf("%d",&a[j]);
//	}
//	for(int i=0;i<;i++)
aaa();
}
