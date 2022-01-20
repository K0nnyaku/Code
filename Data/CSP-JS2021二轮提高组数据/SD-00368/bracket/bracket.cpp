#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#define MAXN 1050
using namespace std;
int a[MAXN];
int np[MAXN];
int lina[MAXN];
int stk1[MAXN];
int stk2[MAXN];
int cnt=0;
int ans;
int n,k;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		char chlin;
		cin>>chlin;
		if(chlin=='('){
			a[i]=1;
		}
		if(chlin=='*'){
			a[i]=-2;
			
		}
		if(chlin==')'){
			a[i]=-1;
		}
		if(chlin=='?'){
			a[i]=0;
			cnt++;
		}
	}
	if(a[1]==-2||a[n]==-2){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int f=0;f<=cnt;f++){
		for(int s=0;s<=cnt-f;s++){
			int t=cnt-s-f;
			for(int i=1;i<=f;i++){
				np[i]=-2;
			}
			for(int i=f+1;i<=f+s;i++){
				np[i]=-1;
			}
			for(int i=f+1+s;i<=cnt;i++){
				np[i]=1;
			}
			do{
//				for(int i=1;i<=cnt;i++){
//					cout<<np[i]<<' ';
//				}cout<<endl;
				int ct=0;
				int tik=0;
				bool judge=1;
				for(int i=1;i<=n;i++){
					if(a[i]==0){
						ct++;
						lina[i]=np[ct];
						
						continue;
					}
					
					lina[i]=a[i];
				}
//				for(int i=1;i<=n;i++){
//					cout<<lina[i]<<' ';
//					
//				}cout<<endl;
				for(int i=1;i<=n;i++){
					if(lina[i]==-2){
						tik++;
						if(tik>k){
							judge=0;
							break;
						}
					
					}
					else{
						tik=0;
					}
				}
				if(!judge)
				{
					
//					cout<<'$';
					continue;	
				}
				if(lina[1]==-2||lina[n]==-2){
					continue;
				}
				int tp1=0;
				int tp2=0;
//				for(int i=1;i<=n;i++){
//					cout<<lina[i]<<' ';
//				}cout<<endl;
				bool been[MAXN];
				for(int i=0;i<=n;i++){
					been[i]=0;
				}
				for(int i=1;i<=n;i++){
					if(lina[i]==1){
						tp1++;
						continue;
					}
					if(lina[i]==-1){
						been[tp1]=0;
						tp1--;
						if(tp1<0){
							judge=0;
							break;
						}
						continue;
					}
					if(lina[i]==-2){
						if(been[tp1]==1&&lina[i-1]==-1){
//							cout<<'#'<<endl;
//							judge=0;
//							break;
						}
						while(lina[i+1]==-2){
							i++;
						}
						if(lina[i+1]==1)been[tp1]=1;
					}
				}
				if(!judge||tp1>0){
//					cout<<'@';
					continue;
				}
//				for(int i=1;i<=n;i++){
//					cout<<lina[i]<<' ';
//				}cout<<endl;
				ans++;
			}while(next_permutation(np+1,np+cnt+1));
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
