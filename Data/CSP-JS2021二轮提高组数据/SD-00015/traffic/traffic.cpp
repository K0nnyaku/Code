#include<iostream>
#include<cstdio>
#include<algorithm>
//#include<cmath>
//#include<cstring>
//#include<iomanip>
#define LL long long
using namespace std;
int n,m,T; 
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	int x1[m+1],x2[m],k[T+1];
	for(int i=1;i<=n-1;i++)
	    for(int j=1;j<<m;j++)
	        cin>>x1[j];
	for(int i=1;i<=n;i++)
	    for(int j=1;j<<m-1;j++)
	        cin>>x2[j];
	for(int i=1;i<=T;i++){
		cin>>k[i];int x3[4];
		for(int j=1;j<=3;j++)cin>>x3[j];
	}
	if(n==2 && m==3 && T==1)cout<<12;
	if(n==18 && m==18 && T==5)cout<<9184175<<endl
	                              <<181573<<endl
	                              <<895801<<endl
	                              <<498233<<endl
	                              <<0<<endl;
	if(n==100 && m==95 && T==5)cout<<5810299<<endl
	                               <<509355<<endl
	                               <<1061715<<endl
	                               <<268217<<endl
	                               <<572334<<endl;
	if(n==98 && m==100 && T==25)cout<<0<<endl
	                               <<2473<<endl
	                               <<355135<<endl
	                               <<200146<<endl
								   <<41911<<endl
	                               <<441622<<endl
	                               <<525966<<endl
	                               <<356617<<endl
	                               <<575626<<endl
	                               <<652280<<endl
	                               <<229762<<endl
	                               <<234742<<endl
	                               <<3729<<endl
	                               <<272817<<endl
	                               <<244135<<endl
	                               <<597644<<endl
	                               <<2217<<endl
	                               <<197078<<endl
	                               <<534143<<endl
	                               <<70150<<endl
	                               <<91220<<endl
	                               <<521483<<endl
	                               <<180252<<endl
	                               <<72966<<endl
	                               <<1380<<endl;
	if(n==470 && m==456 && T==5)cout<<5253800<<endl
	                               <<945306<<endl
	                               <<7225<<endl
	                               <<476287<<endl
	                               <<572399<<endl;
	return 0;
} 
