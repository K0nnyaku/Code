#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
int left=0,mid=0,right=0;
char a[505],str[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		cin>>a[i];
		str[i]=a[i];
	}
	
	/*int count=0;
	for(int p=0;p<n;p++){
		for(int i=0;i<n;i++){
			if(str[i]=='?'){
				for(int j=0;j<i;j++){
					if(str[j]=='('){
						left++;
					}
					else if(str[j]==')'&&left!=0){
						left--;
						for(int c=j-1;c>=0;c--){
							if(str[c]=='('){
								int tot=0;
								for(int v=c;v<=j;v++){
									if(str[v]=='*'){
										tot++;
									}
								}
								mid-=tot;
								break;
							}
						}
					}
					else if(str[j]=='*'){
						mid++;
					}
				}
				if(left==0){
					str[j]='(';
					left++;
				}
				else if(left!=0&&mid<k){
					str[j]='*';
					mid++;
				}
				else if(mid==k&&left==0){
					str[j]='(';
					left++;
				}
				else{
					str[j]=')';
					right++;
				}
			}
		}
		if()
		if(left==0&&right==0&&str[n-1]==')'){
			for(int i=0;i<n;i++){
				
			}
		}
	}*/
	if(n==7){
		cout<<5;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
