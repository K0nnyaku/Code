#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=105;
int a[MAXN],b[MAXN],a2[MAXN],b2[MAXN],ans3[MAXN];
int n,m1,m2,ans1,ans2,sum;
void zhy(){
	for(int i=0;i<n+1;i++){//j是国内，z是国际 
		for(int j=0,z=n;j<n+1,z>-1;j++,z--){
		    for(int x=0;(x<m1)&&(j!=0);x++){//国内 
	    	    if(x<j)//先到先得的 
		          ans1++;
		        else{
		            for(int y=0;y<x-1;y++){
			            if(a[x]>b[y]){
			                ans1++;
			                b[y]+=100000000;
			                break;
			           } 
		    	    }	
		       } 		
           }
        for(int m=0;(m<m2)&&(z!=0);m++){//国际 
		    if(m<z)//先到先得的 
		       ans2++;
		    else{
		        for(int y=0;y<m-1;y++){
			        if(a2[m]>b2[y]){
			           ans2++;
			           b2[y]+=100000000;
			           break;
			        }
			    }	
		    } 		
        }
         sum=ans1+ans2;
			ans3[i]=sum;
		}
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
    cin>>n;
	cin>>m1>>m2;
//飞机数量小于桥数量 
	if(n>(m1+m2)){
		cout<<m1+m2;
	}
//飞机数量大于桥数量
    else{
    	for(int x=0;x<m1;x++)	
	    cin>>a[x]>>b[x];
	for(int m=0;m<m2;m++)	
	    cin>>a2[m]>>b2[m];
    zhy();
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i;j++)
        if(ans3[j]>ans3[j+1]){
        	int temp=ans3[j];
        	ans3[j]=ans3[j+1];
        	ans3[j+1]=temp;
		}
		cout<<ans3[n];
	}
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
