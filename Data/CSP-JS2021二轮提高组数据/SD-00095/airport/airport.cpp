#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std; 
	int maxa1=0,maxa2=0;//分别表示国内国际最大到达时间 
	int n,pl1,pl2;//分别表示廊桥数、国内飞机数、国际飞机数
	    
	int a1[100000000]={},a2[100000000]={};//第T时刻有国内国际飞机来 
	
	
	int as1[5000],as2[5000];//国内国际飞机到达时间 
	int ak1[5000],ak2[5000];//国内国际飞机飞走时间 
	
	
	int aa1[5000],aa2[5000];//修正后的国内国际飞机到达时间
	int aw1[5000],aw2[5000];//修正后的国内国际飞机飞走时间 
          
    int ans=0;//最后输出的答案数
	 
int main(){
	  freopen("airport.in","r",stdin);
	  freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&pl1,&pl2);
	//用来对飞机进行初步处理 
	  for(int i=1;i<=pl1;i++){//用来遍历国内飞机到点时刻及飞走表的循环 
	  	  scanf("%d%d",&as1[i],&ak1[i]);
	  	      if(as1[i]>maxa1){
	  	      	 maxa1=as1[i];
				}
	  	   a1[as1[i]]=ak1[i];//将飞机到达的时刻标记，并用空间换时间 
	  }
	  for(int i=1;i<=pl2;i++){//用来遍历国际飞机到点时刻及飞走表的循环 
	  	  scanf("%d%d",&as2[i],&ak2[i]);
	  	     if(as2[i]>maxa2){
	  	     	maxa2=as2[i];
			   }
		   a2[as2[i]]=ak2[i]; //将飞机到达的时刻标记，并用空间换时间
	  } 
	  
	  //用来获得排好序的飞机顺序 
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
	  
	  
	  for(int i=0;i<=n;i++){//用来遍历N的所有分配方式的循环 
	    int out1[100000000]={},out2[10000000]={};//国内T时刻几架廊桥上飞机飞走，国际几架飞走
	    int size1=i,size2=n-i;//分别表示国内国际分到的廊桥数
	    int po1=0,po2=0;
		int w1[5000],w2[5000],ww1=2,ww2=1; 
		
		
		
	      for(int j=1;j<=pl1;j++){//表示国内飞机停靠廊桥数量 
				  if(size1>=1){
					size1--;
					po1++;
					out1[aw1[j]]++;
					w1[ww1]=aw1[j];//记录飞机起飞 
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
					w1[ww1]=aw1[j];//记录飞机起飞 
					ww1++;
				  }
				  }       
			   	
		  }
		  	
		  	
		  
		  for(int j=1;j<=pl2;j++){//表示国内飞机停靠廊桥数量 
				  if(size2>=1){
					size2--;
					po2++;
					out2[aw2[j]]++;
					w2[ww2]=aw2[j];//记录飞机起飞 
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
					w2[ww2]=aw2[j];//记录飞机起飞 
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
