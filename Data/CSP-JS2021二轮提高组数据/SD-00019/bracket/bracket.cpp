#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>

#define MAXN 500
#define MAXM 999999
#define ll long long

using namespace std;

int n,K,m;
char s[MAXN+10];
ll cnt[MAXN+10][MAXN+10][MAXN+10]; //n, num of * , '('-')'

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ll pp=1000000007;
	scanf("%d %d",&n,&K);
	scanf("%s",s);
	cnt[0][0][1]=1;
	for(int i=1;i<n;i++){
		if(s[i]=='*'){
			for(int j=0;j<K;j++){
				for(int k=0;k<n;k++){
					cnt[i][j+1][k]+=cnt[i-1][j][k];
					cnt[i][j+1][k]%=pp;
				}
			}
			continue;
		}
		if(s[i]=='('){
			for(int j=0;j<=K;j++){
				for(int k=0;k<n;k++){
					cnt[i][0][k+1]+=cnt[i-1][j][k];cnt[i][0][k+1]%=pp;
				}
			}
			continue;
		}
		if(s[i]==')'){
			for(int j=0;j<=K;j++){
				for(int k=1;k<n;k++){
					cnt[i][0][k-1]+=cnt[i-1][j][k];cnt[i][0][k-1]%=pp;
				}
			}
			continue;
		}
		for(int j=0;j<K;j++){
			for(int k=0;k<n;k++){
				cnt[i][j+1][k]+=cnt[i-1][j][k];cnt[i][j+1][k]%=pp;
			}
		}
	
		for(int j=0;j<=K;j++){
			for(int k=0;k<n;k++){
				cnt[i][0][k+1]+=cnt[i-1][j][k];cnt[i][0][k+1]%=pp;
			}
		}
		
		for(int j=0;j<=K;j++){
			for(int k=1;k<n;k++){
				cnt[i][0][k-1]+=cnt[i-1][j][k];cnt[i][0][k-1]%=pp;
			}
		}
//		for(int i=0;i<n;i++){
//			for(int j=0;j<=K;j++){
//				for(int k=0;k<n;k++){
//					cout<<cnt[i][j][k]<<' ';
//				}
//			}
//		}
//		cout<<endl;
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<=K;j++){
//			for(int k=0;k<n;k++){
//				cout<<i<<'i'<<' '<<j<<'j'<<' '<<k<<'k'<<' '<<cnt[i][j][k]<<endl;
//			}
//		}
//	}
//	cout<<endl;
	cout<<cnt[n-1][0][0]<<endl;;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

