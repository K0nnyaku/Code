#include <bits/stdc++.h>
using namespace std;
int t,n,a[1000005],num[500005][2],b[1000005],f[4],flag;
string doer;
int main(){
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		doer="";
		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
			if(num[a[i]][0]==0){
				num[a[i]][0]=i;
			}else{
				num[a[i]][1]=i;
			}
		}
		for(int i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			if(num[1][0]==1&&num[i][1]==2*n){
				continue;
			}
			b[n]=b[n+1]=i;
			f[0]=f[1]=num[i][0];
			f[2]=f[3]=num[i][1];
			for(int j=1;j<n;j++){
				if(a[f[2]-1]==a[f[3]+1]){
					b[n-j]=b[n+j+1]=a[f[2]-1];
					f[2]-=1;
					f[3]+=1;
				}else if(a[f[1]+1]==a[f[3]+1]){
					b[n-j]=b[n+j+1]=a[f[1]+1];
					f[1]+=1;
					f[3]+=1;
				}else if(a[f[0]-1]==a[f[2]-1]){
					b[n-j]=b[n+j+1]=a[f[0]-1];
					f[0]-=1;
					f[2]-=1;
				}else if(a[f[0]-1]==a[f[1]+1]){
					b[n-j]=b[n+j+1]=a[f[0]-1];
					f[0]-=1;
					f[1]+=1;
				}else{
					break;
				}
			}
			if(b[1]!=0){
//				cout<<i;
				flag=1;
				string doer2="";
				int l1=1,l2=2*n;
				for(int i=1;i<=2*n;i++){
					if(a[l1]==b[i]){
						doer2+="L";
						l1++;
					}else{
						doer2+="R";
						l2--;
					}
//					cout<<b[i]<<endl;
				}
				if(doer2<doer||doer==""){
					doer=doer2;
				}
			}
		}
		if(flag==0){
			cout<<"-1"<<endl;
		}else{
			cout<<doer<<endl;
		}
	}
	return 0;
} 
/*2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3*/
