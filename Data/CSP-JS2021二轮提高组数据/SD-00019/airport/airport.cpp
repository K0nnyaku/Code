#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>

#define MAXN 100000
#define MAXM 100000
#define ll long long

using namespace std;

int n,m1,m2;

struct airp{
	int num,tim,cnt;
};

airp q1[MAXN+10],q2[MAXN+10];
ll sum1[MAXN+10],sum2[MAXN+10];

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	int cn1=0,cn2=0;               
	for(int a,b,i=0;i<m1;i++){
		scanf("%d %d",&a,&b);
		for(int j=1;j<=m1;j++){
			if(q1[j].tim<a){                                        
				q1[j].tim=b;q1[j].cnt++; 
				break;
			}
		}	
	}
	for(int a,b,i=0;i<m2;i++){
		scanf("%d %d",&a,&b);
		for(int j=1;j<=m2;j++){
			if(q2[j].tim<a){ 
				q2[j].tim=b;q2[j].cnt++;   
				break;                   
			}
		}
	}
	for(int i=1;i<=m1;i++){
		sum1[i]=sum1[i-1]+q1[i].cnt;
	}
	for(int i=1;i<=m2;i++){
		sum2[i]=sum2[i-1]+q2[i].cnt;
	}
	int maxn=0;    
	for(int i=0;i<=n;i++){
		int j=n-i;   
		if(maxn<sum1[i]+sum2[j]){
			maxn=sum1[i]+sum2[j];	  
		}	
	}
	printf("%d",maxn); 
	fclose(stdin);       
	fclose(stdout);
	return 0;
	
}

