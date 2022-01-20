#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("airport.in","r",stdin);
	//freopen("airport.out","w",stdout);
	
	long long n;
	long long m,s;
	cin>>n>>m>>s;
	int neijs=0,waijs=0;
	int zong;
	int neihui[0],jihui;
	int num;
	for(int l=0;l<n;l++)
	{
		jihui=n-neihui[l];
		for(int i=1;i<=m;i++){
		int nei[i];//国内飞机pailie数量 
		
		
		if(nei[i]<neihui[l]){
					neijs=neijs+1;
					neihui[l]=neihui[l]-1;
			}	
	for(int x=0;x<5;x++)
		{
		int neitingsj[x],neilisj[x];
		int neitingsjx[x];
		cin>>neitingsj[x]>>neilisj[x];
			neitingsjx[x]=neitingsj[x]+1;
			if(neitingsjx[x]>neilisj[x]&&nei>neihui)
		{
			neijs=neijs+1;
		}
		 }
		
	}//国内数 
	for(int i=1;i<=s;i++)
	{
		int wai[i];//国际飞机数量 
			
			if(wai[i]<jihui){
					waijs=waijs+1;
					jihui=jihui-1;
			}
	
				for(int x=0;x<s;x++)
		{
			int waitingsj[x],wailisj[x];
			int waitingsjx[x];
			cin>>waitingsj[x]>>wailisj[x];
			waitingsjx[x]=waitingsj[x]+1;
			if(waitingsjx[x]>wailisj[x]&&wai[i]>jihui)
		{
			waijs=waijs+1;
		
		}
		}
		
			
		
		//int wailisjx;
		//	cin>>wailisjx;
		
			zong=neijs+waijs;
			if(num==0){
			num=zong;
		}
		if(zong>num)
		{
			num=zong;
		}
			
	}//国际飞机数量 

	
	}
	for(int i=0;i<n;i++){
	if(num>zong){
		cout<<num;
	}
	else{
		cout<<zong;
	}
}
	return 0;		
}
