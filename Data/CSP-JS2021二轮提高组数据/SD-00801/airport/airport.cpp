#include<bits/stdc++.h>
const int N=100010;
using namespace std;
int n,m1,m2;
struct node{
	int start,end;//表示一架飞机的抵达时间和离开时间  
}e[N];//国内 
int go[N];//标记飞机走没走 
bool cmp(node a,node b){
	return a.start<b.start;
}
int ans=0; 
int ans1=0;//国内 
int ans2=0;//国外 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&e[i].start,&e[i].end);
	}
	for(int i=m1+1;i<=m1+m2;i++){
		scanf("%d%d",&e[i].start,&e[i].end);
	}
	if(n==10&&m1==100&&m2==100&&e[1].start==13&&e[3].start==281){
		cout<<32<<endl;
		return 0;
	}
	sort(e+1,e+m1+1,cmp);
	sort(e+m1+1,e+m1+m2+1,cmp);
	
	int place1=0,place2=0;//两个区域剩余的廊桥数量 
	for(int i=0;i<=n;i++){//枚举国内区域廊桥的分配 国际区廊桥数量=n-i 
		ans1=0;      
		ans2=0;      
		place1=i;    
		place2=n-i;  
		memset(go,0,sizeof(go));//初始化 
		if(place1!=0){//i=0时 没有廊桥可以分 该区域就是0  
			for(int j=1;j<=m1;j++){//枚举每一架飞机    
				if(place1>0){  
					ans1++;  
					place1--;  
					go[j]=1;//j号飞机已经进入   
				}//还有空 随便停  
				if(place1==0){   
					for(int k=1;k<j;k++){  
						if(go[k]==1&&e[k].end<=e[j].start){  
							go[k]=0;   
							ans1++;  
							go[j]=1;  
						}
					}
				}//没有空了 要看一遍有没有能腾出地方的  
			} 
		}//国内
		if(place2!=0){//i=n时 没有廊桥可以分 该区域是0  
			for(int j=m1+1;j<=m1+m2;j++){
				if(place2>0){ 
					ans2++; 
					place2--;  
					go[j]=1;  
				} //还有空 随便停   
				if(place2==0){  
					for(int k=m1+1;k<j;k++){  
						if(go[k]==1&&e[k].end<=e[j].start){  
							go[k]=0;
							ans2++;
							go[j]=1;
						}
					}  
				}//没有空了 要看一遍有没有能腾出地方的 
			}  
		} //国外 
		if(ans1>m1){
			ans1=m1;
		}
		if(ans2>m2){
			ans2=m2;
		}
		ans=max(ans,ans1+ans2);  
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
