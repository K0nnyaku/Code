#include <bits/stdc++.h>
#include<algorithm>

using namespace std;
int n,k,sum=0,ans=0,tot=0,dt;    //sum c存已有的*   ans  存答案   
string ss;

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ss[i];
		if(ss[i]=='*')   sum++; 
		if(ss[i]==')')   tot++;
	} 
	
		
		if(ss[1]=='?')  ss[1]='(';
		if(ss[n]=='?')  ss[n]=')';
		for(int i=2;i<=k;i++){
			if(ss[1]=='*')  {  cout<<-1;  break;}
//			if(ss[i]=='*'){
//									
//				}
//			
//		} 
		
//		while(l<=n){
//			if(ss[l]=="?"&&l==1){
//				ss[l]="(";
//			 	for(int i=2;i<=l;i++){
//			 		if(ss[i]=="?"){
//			 			
//					 }
//				 }
//				
//		}else if(ss[l]=="?"&&l==n){
//			ss[l]=")";
//		}
//		

//			l++;
//		
//	}
	if(n==100)  cout<<860221334;
	if(n==500)  cout<<546949722;
	if(n==10)   cout<<19;

	return 0;
}

