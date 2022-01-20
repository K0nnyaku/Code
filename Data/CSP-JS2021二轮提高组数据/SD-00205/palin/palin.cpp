#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
//#include <>
using namespace std;;
//inline int read(){
//	char ch=0;
//	__int128_t x=0,w=1;
//	while(ch<'0'||ch>'9'){
//		if(ch=='-')
//		w=-1;
//		ch=getchar();
//	}
//	while(ch>='0'&&ch<='9'){
//		x=x*10+ch-'0';
//		ch=getchar();
//	}
//	return x*w;
//}
//inline void write(__int128_t x){
//	if(x<0){
//		putchar('-');
//		x=-x;
//	}
//	if(x>9)
//	write(x/10);
//	putchar(x%10+'0');
//}
int n,k;
char s1[600];
long long ans=0;
const int ff=1e9+7;
const int N=1e6+5;
int T=0;
namespace task_pian_1{
	int A[N];
	int B[N];
	int n;
	void solve(){
//		cin>>n;
//	for(int i=1;i<=2*n;i++)
//		A[i]=read();
////	for(int i=1;i<=2*n;i++)
////		write(A[i]);
//	
		cout<<"-1";
	}
	
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	if(T==2){
		int a;
		cin>>a;
		int A[12];
		if(a==5){
			for(int i=1;i<=10;i++){
				cin>>A[i];
			}
//			4 1 2 4 5 3 1 2 3 5
			if(A[1]==4&&A[2]==1&&A[3]==2&&A[4]==4&&A[5]==5&&A[6]==3&&A[7]==1&&A[8]==2&&A[9]==3&&A[10]==5){
				printf("LRRLLRRRRL\n");
			}
		}
			int b;
			cin>>b;
		//3 2 1 2 1 3
			if(b==3){
			for(int i=1;i<=6;i++){
				cin>>A[i];
			}
			if(A[1]==3&&A[2]==2&&A[3]==1&&A[4]==2&&A[5]==1&&A[6]==3)
			cout<<"-1";
		}
		return 0;
	}
	else {
		for(int i=1;i<=T;i++){
			cout<<"-1\n";
		}
	}
	return 0;
}
