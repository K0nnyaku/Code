#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct Plane{
	int co;
	int le;
};
struct Gn{
	int beg;
	int end;
};
struct Gw{
	int beg;
	int end;
};
bool cmp(Plane a,Plane b){
	return a.co <b.co ;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long n,m1,m2;
	cin>>n>>m1>>m2;
	Plane p1[m1];//p1Ϊ���� 
	Plane p2[m2];//p2Ϊ���� 
	for(int i=0;i<m1;i++){//������� 
		cin>>p1[i].co >>p1[i].le ;
	
	}	
	for(int i=0;i<m2;i++){//������� 
		cin>>p2[i].co>>p2[i].le ;
		
	}
	int cnt[n+5];
	memset(cnt,0,sizeof(cnt));
	sort(p1,p1+m1,cmp);//���ڵ���ʱ���С���� 
	sort(p2,p2+m2,cmp);//���ʵ���ʱ���С���� 
	for(int i=0;i<=n;i++){//�����������ķɻ��ܺ�  
		Gn gn[i+1];
		Gw gw[n-i-1];
		int gn_cnt =i;//��¼���ڳ��Ͽ������� 
		int gw_cnt =n-i;//��¼���ʳ��Ͽ������� 
		int le_min1=1000000;
		int le_min2=1000000;
		int num1=0;
		int num2=0;
		for (int j=0;j<gn_cnt ;j++){
			gn[j].beg =p1[j].co ;
			gn[j].end =p1[j].le ;
			if(gn[j].end <=le_min1){
				le_min1=gn[j].end ;
				num1=j;
			}
			cnt[i]++;
		}
		int temp=0;
		while(temp==0){
			for(int j=gn_cnt;j<m1;j++){//�ڵ�һ�ܷɻ��ߺ����絽���һ�� 
				if(p1[j].co >le_min1){
					cnt[i]++;
					gn[num1].beg =p1[j].co ;
					gn[num1].end =p1[j].le ;
					le_min1=10000000;
					temp=1;	
					break;
				}
			}
			if(temp==0){//���û�оͽ���ѭ�� 
				break;
			}
			if(temp==1){
				temp=0;
			}
			for(int j=0;j<gn_cnt;j++){//�����������뿪�� 
				if(gn[j].end <=le_min1){
					le_min1=gn[j].end ;
					num1=j;
				}
			}
			
		}
	
		
		for (int j=0;j<gw_cnt ;j++){
			gw[j].beg =p2[j].co ;
			gw[j].end =p2[j].le ;
			if(gw[j].end <=le_min2){
				le_min2=gw[j].end ;
				num2=j;
			}
			cnt[i]++;
		}
		int temp1=0;
		while(temp1==0){
			for(int j=gw_cnt;j<m2;j++){//�ڵ�һ�ܷɻ��ߺ����絽���һ�� 
				if(p2[j].co >le_min2){
					cnt[i]++;
					gw[num1].beg =p2[j].co ;
					gw[num1].end =p2[j].le ;
					le_min2=10000000;
					temp1=1;	
					break;
				}
			}
			if(temp1==0){//���û�оͽ���ѭ�� 
				break;
			}
			if(temp1==1){
				temp=0;
			}
			for(int j=0;j<gw_cnt;j++){//�����������뿪�� 
				if(gw[j].end <=le_min2){
					le_min2=gw[j].end ;
					num2=j;
				}
			}
			
		}
			}
	int tot=0;
	for(int i=0;i<=n;i++){
		if(tot<=cnt[i]){
			tot=cnt[i];
		}
	}
	cout<<tot<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
