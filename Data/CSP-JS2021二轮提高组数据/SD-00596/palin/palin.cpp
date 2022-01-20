#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int l1[1000000];
//bool l2[1000000];
int lnow[1000000];
int flag = 0;
char pl[1000000];


bool check(){//รปฮสฬโ 
	for(int i = 1;i<=m;i++){
		if(lnow[i] != lnow[(2*m)-i+1])return false;
		
	}
	return true;
	
		
}

 

void hui(int x,int head,int tail){
	if(flag == 1)return;
	if(x == ((2*m)+1)){
		if(check()){
			flag = 1;
			for(int q = 1;q<=(2*m);q++){
			printf("%c",pl[q]);
			}
		}
		return ;
	}
	for(int i = 1;i<=2;i++){
			if(i == 1){
			//	l2[x] = true;
				
				lnow[x] = l1[head];
				pl[x] = 'L';
				
				
				hui(x+1,++head,tail);
			//	l2[x] = false;
			}
			if(i == 2){
			//	l2[x] = true;
				lnow[x] = l1[tail];
				pl[x] = 'R';
				hui(x+1,head,--tail);
			//	l2[x] = false;
			}
		
	}
}


int main(){
	cin>>n;
	for(int z = 1;z<=n;z++){
		scanf("%d",&m);
		for(int v = 1;v<=(2*m);v++){
			scanf("%d",&l1[v]);
			
		}
		hui(1,1,(2*m));
			if(flag == 0)printf("-1");
			flag = 0;
			memset(lnow,0,sizeof(lnow));
	}
	
} 
