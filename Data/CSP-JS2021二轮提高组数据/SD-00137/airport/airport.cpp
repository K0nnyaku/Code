#include<iostream>
#include<bits/stdc++.h>
#include<queue>
int ans;
int nxt[100005];//下标是排完序的飞机编号 指向接着就走的飞机 
int head,tail;
using namespace std;
struct air{
	int a,b;
};
bool cmp(air x,air y){
	return x.a<y.a;
}

air gn[100005],gw[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
int n,m1,m2;
cin>>n>>m1>>m2;
for(int i=1;i<=m1;i++){
	cin>>gn[i].a >>gn[i].b;
}
for(int i=1;i<=m2;i++){
	cin>>gw[i].a >>gw[i].b;
}
sort(gn+1,gn+m1+1,cmp);
sort(gw+1,gw+m2+1,cmp);
/*for(int i=1;i<=m1;i++){
	cout<<gn[i].a;
}*/

for(int i=0;i<=n;i++){//i国内廊桥j国外廊桥 
	int j=(n-i);
	int s1=0;
	int s2=0;
	//国内停的数量 国际停的数量 
	if(i>0){
		
		for(int g=1;g<=m1;g++){
			//q1.push_back(gn[g]);
			
		if(g==2){
			int s=0;
			if(gn[2].a<gn[1].b && m1==1){
				s=1;
			}
			else if(gn[1].b<gn[2].b && s!=1 ){
				nxt[1]=2;
				head=1;
				tail=2;
			}
			else if(gn[1].b>gn[2].b && s!=1){
				nxt[2]=1;
				head=2;
				tail=1;
			}
		}
		else if(g>2){
			
			int y=head;
			int hd;    //上一个飞机的编号 
			int flg=0;
			int q=0;
			if(gn[g].a<gn[head].b && g>i){
				q=1;
			}
			else if(q!=1){
			
			do{
				if(gn[g].b<gn[head].b){
					
					nxt[g]=head;
					head=g;
					flg=1;
					break;
				}
				else if(gn[g].b<gn[y].b){
					nxt[hd]=g;
					nxt[g]=y;
					flg=1;
					break;	
				}
				hd=y;
				y=nxt[y];
				
			}while(y!=tail);
			if(flg==0){
				nxt[tail]=g;
				tail=g;
			}
		}
		} //lianbiao
		if(g<=i){
			s1++;	
		}
		else if(g>i){
			if(gn[g].a>gn[head].b){
				s1++;
				head=nxt[head];
			}
		}
		
		}
	}
		nxt[100005]={0};//下标是排完序的飞机编号 指向接着就走的飞机 
		head=0;
		tail=0;
		if(j>0){
		
		for(int g=1;g<=m2;g++){
			//q1.push_back(gn[g]);
		if(g==2){
			int w=0;
			if(gw[2].a<gw[1].b && m2==1){
				w=1;
				
			}
			else if(gw[1].b<gw[2].b && w!=1){
				nxt[1]=2;
				head=1;
				tail=2;
			}
			else if(gw[1].b>gw[2].b && w!=1){
				nxt[2]=1;
				head=2;
				tail=1;
			}
		}
		else if(g>2){
			int y=head;
			int hd;//上一个飞机的编号 
			int flg=0;
			int e=0;
				if(gw[g].a<gw[head].b && g>i){
				e=1;
			}
			else if(e!=1){
			do {
				if(gw[g].b<gw[head].b){
					
					nxt[g]=head;head=g;
					flg=1;
					break;
				}
				else if(gw[g].b<gw[y].b){
					nxt[hd]=g;
					nxt[g]=y;
					flg=1;
					break;	
				}
				hd=y;
				y=nxt[y];
				
			}while(y!=tail);
			if(flg==0){
				nxt[tail]=g;
				tail=g;
			}
		} }
		if(g<=j){
			s2++;	
		}
		else if(g>j){
			if(gw[g].a>gw[head].b){
				s2++;
				head=nxt[head];
			}
		}
		
		}
	}
	if((s1+s2)>ans){
		ans=(s1+s2);
	}
}
cout<<ans<<endl;
 return 0;
} 
