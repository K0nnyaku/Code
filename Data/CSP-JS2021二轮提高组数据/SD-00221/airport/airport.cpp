#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n,m1,m2;
int nei[5005][3],wai[5005][3];
int neiqiao[5005],waiqiao[5005];

int main(){
   	freopen("airport.in","r",stdin);
   	freopen("airport.out","w",stdout);
   	scanf("%d%d%d",&n,&m1,&m2);
   	for(int i=1;i<=m1;i++){
   		cin>>nei[i][0]>>nei[i][1]; 
   	}
    	for(int i=1;i<=m2;i++){
    		cin>>wai[i][0]>>wai[i][1];
    	}
   	
   	
   	
   	int cnt=-1;
   	
   	for(int i=0;i<=n;i++){ 
   		int q=n-i;
		   int ans1=i,ans2=q,ans=0;
		   
		   if(i!=0){
		   for(int k=1;k<=i;k++){
            	neiqiao[k]=nei[k][1];
            }
			}

			 if(q!=0){
		   for(int k=1;k<=q;k++){
            	waiqiao[k]=wai[k][1];
            }
			}
   	
   	     
   	
	   	for(int j=i+1;j<=m1;j++){ 
   			if(i==0){
			   ans1=0;
			   break;
   			}
            for(int kk=1;kk<=i;kk++){
            	if(nei[j][0]>neiqiao[kk]){
            		neiqiao[kk]=nei[j][1];
					ans1++;
            	}
            }
   		}
   		for(int j=q+1;j<=m2;j++){ 
   			if(q==0){
			   ans2=0;
			   break;
   			}

            for(int kk=1;kk<=q;kk++){
            	if(wai[j][0]>waiqiao[kk]){
            		waiqiao[kk]=wai[j][1];
					ans2++;
            	}
            }
   		}
   		
	   ans=ans1+ans2;
	   cnt=max(cnt,ans);
		 
		
   	}
   	cout<<cnt;
   	fclose(stdin);
   	fclose(stdout);
   	return 0;
} 
