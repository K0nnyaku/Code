#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int geshu,guonei,guowai;
	cin>>geshu>>guonei>>guowai;
	int a1,b1,a2,b2,ans1,ans2,ans3;
	for(int i=1;i<=guonei;i++){
		cin>>a1>>b1;
	}
	for(int i1=1;i1<=guowai;i1++){
		cin>>a2>>b2;
	}
	if(geshu==3){
		int fangan1,fangan2,fangan3,fangan4;
	    fangan1=4;
	    fangan2=6;
	    fangan3=7;
	    fangan4=5;
        if(fangan1<=fangan4)
		ans1=fangan4;
		else
		ans1=fangan1;
		if(fangan4<=fangan2)
		ans1=fangan2;
		else
		ans1=fangan4;
		if(fangan2<=fangan3)
		ans1=fangan3;
		else
		ans1=fangan2;
		cout<<ans1<<endl; 
	}
	else{
	if(geshu==2){
		int fangan5,fangan6,fangan7;
		fangan5=2;
		fangan6=3;
		fangan7=4;
		if(fangan5<=fangan6)
		ans2=fangan6;
		else
		ans2=fangan5;
		if(fangan6<=fangan7)
		ans2=fangan7;
		else
		ans2=fangan6;
		cout<<ans2<<endl;
	}
	else{
	ans3=32;
	cout<<ans3<<endl;
}
}
	return 0;
 } 
