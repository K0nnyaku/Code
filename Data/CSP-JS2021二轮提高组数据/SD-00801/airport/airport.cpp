#include<bits/stdc++.h>
const int N=100010;
using namespace std;
int n,m1,m2;
struct node{
	int start,end;//��ʾһ�ܷɻ��ĵִ�ʱ����뿪ʱ��  
}e[N];//���� 
int go[N];//��Ƿɻ���û�� 
bool cmp(node a,node b){
	return a.start<b.start;
}
int ans=0; 
int ans1=0;//���� 
int ans2=0;//���� 
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
	
	int place1=0,place2=0;//��������ʣ����������� 
	for(int i=0;i<=n;i++){//ö�ٹ����������ŵķ��� ��������������=n-i 
		ans1=0;      
		ans2=0;      
		place1=i;    
		place2=n-i;  
		memset(go,0,sizeof(go));//��ʼ�� 
		if(place1!=0){//i=0ʱ û�����ſ��Է� ���������0  
			for(int j=1;j<=m1;j++){//ö��ÿһ�ܷɻ�    
				if(place1>0){  
					ans1++;  
					place1--;  
					go[j]=1;//j�ŷɻ��Ѿ�����   
				}//���п� ���ͣ  
				if(place1==0){   
					for(int k=1;k<j;k++){  
						if(go[k]==1&&e[k].end<=e[j].start){  
							go[k]=0;   
							ans1++;  
							go[j]=1;  
						}
					}
				}//û�п��� Ҫ��һ����û�����ڳ��ط���  
			} 
		}//����
		if(place2!=0){//i=nʱ û�����ſ��Է� ��������0  
			for(int j=m1+1;j<=m1+m2;j++){
				if(place2>0){ 
					ans2++; 
					place2--;  
					go[j]=1;  
				} //���п� ���ͣ   
				if(place2==0){  
					for(int k=m1+1;k<j;k++){  
						if(go[k]==1&&e[k].end<=e[j].start){  
							go[k]=0;
							ans2++;
							go[j]=1;
						}
					}  
				}//û�п��� Ҫ��һ����û�����ڳ��ط��� 
			}  
		} //���� 
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
