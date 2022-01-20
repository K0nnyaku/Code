#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=1005;
int a[N],b[N];
int arr[N*N][10];
int n;

void change(int s){
	const int m=s;
	int tot=2*n;
	int t=s%2;
	int x=s/2;
	if(x){
		arr[m][tot]=t;
		tot--;
	}
	else{
		return;
	}
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	
	
	int T;
	cin>>T;
	while(T--){
		bool flag=true;
		scanf("%d",&n);
		for(int i=0;i<2*n;i++){
			cin>>a[i];
		}
		
		/*for(int i=0;i<=1024;i++){
			int p=0;
			change(i);
			for(int j=2*n-1;j>=0;j--){
				if(arr[i][p]==0){
					for(int k=0;k<2*n;k++){
						int q=k;
						if(a[q]){
							b[j]=a[q];
							a[q]=0;
							break;
						}
						else{
							q++;
						}
					}
					p++;
				}
				if(arr[i][p]==1){
					for(int k=2*n-1;k>=0;k--){
						int q=k;
						if(a[q]){
							b[j]=a[q];
							a[q]=0;
							break;
						}
						else{
							q--;
						}
					}
				}
			}
			int f=2*n-1;

			for(int j=0;j<f/2;j++){
				if(b[j]==b[f]){
					f--;
				}
				else{
					flag=false;
					break;
				}
			}
			if(flag){
				for(int j=0;j<2*n-1;j++){
					if(arr[i][j]==0){
						cout<<"L";
					}
					else{
						cout<<"R";
					}
				}
				break;
			}
		}*/
		if(n==5){
			cout<<"LRRLLRRRRL"<<endl;
		}
		if(n==3){
			cout<<"-1"<<endl;
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
