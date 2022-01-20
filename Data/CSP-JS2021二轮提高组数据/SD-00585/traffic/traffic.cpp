#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int quan1,hao1,se1,quan2,hao2,se2;
int qujian(int hao123){
	if(hao123<=m)return 1;
	if(hao123<=m+n)return 2;
	if(hao123<=2*m+n)return 3;
	return 4;
}
int edge[505][505][2];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&edge[i][j][0]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			scanf("%d",&edge[i][j][1]);
		}
	}
	while(t--){
		int ans=2147474747;
		int k;
		scanf("%d",&k);
		int a,b,c;
		for(int i=0;i<k;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(i==0){
				a=quan1;
				b=hao1;
				c=se1;
			}else{
				a=quan2;
				b=hao2;
				c=se2;
			}
		}
		if(se1==se2||k==1){
			cout<<0<<endl;
			continue;
		}
		cout<<min(quan1,quan2)<<endl;}
//		int qj1=qujian(hao1),qj2=qujian(hao2);
//		if(hao1-hao2==1||hao1-hao2==-1){
//			
//			if(qj1!=qj2){
//				cout<<min(quan1,quan2);
//				continue;
//			}
//		}if(qj1==qj2){
//			if(qj1==1){
//				int nowans=0;
//				for(int i=hao1;i<=hao2;i++){
//					nowans+=edge[i][1][0];
//				//	if(i!=1)nowans+=edge[]
//				}
//			}
//		}
//	}
	//This .cpp file is blessed by the one and only true god,Huajige.
	//This .cpp file is blessed by cincoutcerrclog,the godly-ben of godly-bens.
	//This .cpp file is blessed by wangzhi05,the godly-ben of sleeping.
	//This .cpp file is blessed by etsger,the godly-ben of fantastic hands.
	//This .cpp file is blessed by LTY,the godly-ben of gays.
	//This .cpp file is blessed by mensanjin,the godly-ben of cuteness.
	//This .cpp file is blessed by shaibai,the godly-ben of bad hands.
	//This .cpp file is blessed by SPJ,the godly-ben of soft eggs.
	//This .cpp file is blessed by sendiago,the godly-ben of diyaing.
	//With their blessings,I shall get the first prise of CSP-S 2021.
	//written by syko_canir84,the godly-ben of true hands.
	return 0;
}

