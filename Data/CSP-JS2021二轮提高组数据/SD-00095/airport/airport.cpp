#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std; 
	int maxa1=0,maxa2=0;//�ֱ��ʾ���ڹ�����󵽴�ʱ�� 
	int n,pl1,pl2;//�ֱ��ʾ�����������ڷɻ��������ʷɻ���
	    
	int a1[100000000]={},a2[100000000]={};//��Tʱ���й��ڹ��ʷɻ��� 
	
	
	int as1[5000],as2[5000];//���ڹ��ʷɻ�����ʱ�� 
	int ak1[5000],ak2[5000];//���ڹ��ʷɻ�����ʱ�� 
	
	
	int aa1[5000],aa2[5000];//������Ĺ��ڹ��ʷɻ�����ʱ��
	int aw1[5000],aw2[5000];//������Ĺ��ڹ��ʷɻ�����ʱ�� 
          
    int ans=0;//�������Ĵ���
	 
int main(){
	  freopen("airport.in","r",stdin);
	  freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&pl1,&pl2);
	//�����Էɻ����г������� 
	  for(int i=1;i<=pl1;i++){//�����������ڷɻ�����ʱ�̼����߱��ѭ�� 
	  	  scanf("%d%d",&as1[i],&ak1[i]);
	  	      if(as1[i]>maxa1){
	  	      	 maxa1=as1[i];
				}
	  	   a1[as1[i]]=ak1[i];//���ɻ������ʱ�̱�ǣ����ÿռ任ʱ�� 
	  }
	  for(int i=1;i<=pl2;i++){//�����������ʷɻ�����ʱ�̼����߱��ѭ�� 
	  	  scanf("%d%d",&as2[i],&ak2[i]);
	  	     if(as2[i]>maxa2){
	  	     	maxa2=as2[i];
			   }
		   a2[as2[i]]=ak2[i]; //���ɻ������ʱ�̱�ǣ����ÿռ任ʱ��
	  } 
	  
	  //��������ź���ķɻ�˳�� 
	  for(int i=1;i<=maxa1;i++){
	  	int sss=1;
	  	  if(a1[i]!=0){
	  	  	   aa1[sss]=i;
	  	  	   aw1[sss]=a1[i];
			}
		sss++;
	  }
	  for(int i=1;i<=maxa2;i++){
	  	int sss=1;
	  	  if(a2[i]!=0){
	  	  	   aa2[sss]=i;
	  	  	   aw2[sss]=a2[i];
			}
		sss++;
	  }
	  
	  
	  for(int i=0;i<=n;i++){//��������N�����з��䷽ʽ��ѭ�� 
	    int out1[100000000]={},out2[10000000]={};//����Tʱ�̼��������Ϸɻ����ߣ����ʼ��ܷ���
	    int size1=i,size2=n-i;//�ֱ��ʾ���ڹ��ʷֵ���������
	    int po1=0,po2=0;
		int w1[5000],w2[5000],ww1=2,ww2=1; 
		
		
		
	      for(int j=1;j<=pl1;j++){//��ʾ���ڷɻ�ͣ���������� 
				  if(size1>=1){
					size1--;
					po1++;
					out1[aw1[j]]++;
					w1[ww1]=aw1[j];//��¼�ɻ���� 
					ww1++;
				  }else {
				  	bool d[100000000]={};
				  	 for(int k=1;k<=ww1;k++){
				  	 	  if(aa1[j]>=w1[k]&&d[w1[k]]==0){
				  	 	  	  size1+=out1[w1[k]];
				  	 	  	  d[w1[k]]=1;
						  }
					   }
					if(size1>=1){
					size1--;
					po1++;
					out1[aw1[j]]++;
					w1[ww1]=aw1[j];//��¼�ɻ���� 
					ww1++;
				  }
				  }       
			   	
		  }
		  	
		  	
		  
		  for(int j=1;j<=pl2;j++){//��ʾ���ڷɻ�ͣ���������� 
				  if(size2>=1){
					size2--;
					po2++;
					out2[aw2[j]]++;
					w2[ww2]=aw2[j];//��¼�ɻ���� 
					ww2++;
				  }else {
				  	bool d[100000000]={};
				  	 for(int k=1;k<=ww2;k++){
				  	 	  if(aa2[j]>=w2[k]&&d[w2[k]]==0){
				  	 	  	  size2+=out2[w2[k]];
				  	 	  	  d[w2[k]]=1;
						  }
					   }
					if(size2>=1){
					size2--;
					po2++;
					out2[aw2[j]]++;
					w2[ww2]=aw2[j];//��¼�ɻ���� 
					ww2++;
				  }
				  }       
			   	
		  }	
		     if((po1+po2)>ans){
		     	ans=(po1+po2);
			 }
		  
	  }
	    printf("%d",ans);
	    fclose(stdin);
	    fclose(stdout);
  	return 0;
}
