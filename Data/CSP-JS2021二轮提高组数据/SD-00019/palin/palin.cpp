#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>

#define MAXN 500000
#define MAXM 500000
#define ll long long

using namespace std;

int T,n;
int a[MAXN+10],b[MAXN+10];
bool opl[MAXN+10];

void solve1(){
	ll maxn=1;
	maxn=1<<n;
//	ll aaaaa=1<<20;
//	cout<<aaaaa<<endl;
	for(int i=0;i<maxn;i++){
		int op,l,r,c,fl;
		op=i,l=0,r=n-1,c=n-1,fl=1;
//		cout<<i<<' ';
		for(int j=n-1;j>=0;j--){
			opl[j]=op&1;
			op=op>>1;
		}
//		for(int j=0;j<n;j++)cout<<opl[j]<<'!';
//		cout<<endl;
		for(int j=0;j<n;j++){
			if(!opl[j]){
				b[c]=a[l++];
			}
			else{
				b[c]=a[r--];
			}
			c--;
//			cout<<b[c]<<' ';
		}
		for(int j=0;j<n;j++){
			if(b[j]!=b[n-j-1]){
				fl=0;break;
			}
		}
//		fl=1;
		if(fl){
//			for(int j=0;j<n;j++){
//				cout<<b[j];
//			}
//			cout<<endl;
			for(int j=0;j<n;j++){
				if(!opl[j]){
					printf("L");
				}
				else{
					printf("R");
					
				}
			}
//			cout<<'?'<<endl;
		}//cout<<'?'<<endl;
		if(fl){
			cout<<endl;
			return;
		}
	}
	cout<<"-1"<<endl;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);//cout<<T<<endl;
	while(T--){
		scanf("%d",&n);
		n=n<<1;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);//cout<<a[i]<<' ';
		}
		if(n<=20){
			solve1();continue;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

