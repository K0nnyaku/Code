#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	int n,m1,m2,ans=0,t,zxc=0;
	cin>>n>>m1>>m2;
	 int e[n+2];//储存ans值 
	int m[m1],l[m2];
	for(int i=0;i<m1;i++)m[i]=0;
	for(int j=0;j<m2;j++)l[j]=0;
	int a[100000],b[100000],c[100000],d[100000];
	for(int i=1;i<=m1;i++){
		cin>>a[i]>>b[i];//国内区抵达时间 离开时间 
	}
	for(int i=1;i<=m2;i++){
		cin>>c[i]>>d[i];//国际区抵达时间 离开时间 
	}
	while(zxc<=24){
		for(int i=0;i<=n;i++){
			int j=n-i;//此时国内有i个廊桥，国际有j个廊桥.
			int r=i;
			int p[r],k[n-r];
			for(int w=0;w<r;w++)p[w]=0;
			for(int f=0;f<n-r;f++)k[f]=0;
			 for(int s=1;s<=m1;s++){
			 	if(zxc==a[s]){
				 m[s]=1;//第s架飞机到达
				 for(int o=0;o<i;o++){
				 	if(p[o]==0&&m[s]==1){
				 		p[o]=1;m[s]=2;ans++;//2为入廊桥. 
				 		break;
				 	}
				 }
			}
			if(zxc==b[s]&&m[s]==2){//第s架占用廊桥的飞机准备离开 
			       for(int o=0;o<j;o++){
			       	    if(p[o]==1){
			       	    	p[o]=0;
			       	    	break;
			       	    }
			       } 
			}
		}
		for(int t=0;t<=m2;t++){
			if(zxc==c[t]){
				 	l[t]=1;
				 	for(int o=0;o<j;o++){
				 	if(k[o]==0&&l[t]==1){
				 		k[o]=1;l[t]=2;ans++;//2为入廊桥. 
				 	}
				 }
			 }
			 if(zxc==d[t]&&l[t]==2){
			 l[t]=0;//第s架占用廊桥的飞机准备离开 
			       for(int o=0;o<j;o++){
			       	    if(k[o]==1){
			       	    	k[o]=0;
			       	    	break;
			       	    }
			       } 
			} 
		}
				 
			 for(int u=0;u<n+2;u++)e[u]=ans;ans=0;
		}
		
		
		zxc++;
	}
	sort(e,e+n+2,cmp);
	cout<<e[0]<<endl; 
	return 0;
}
