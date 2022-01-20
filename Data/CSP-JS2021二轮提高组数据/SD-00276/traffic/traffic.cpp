#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
struct EST{
	int bian,shang;
	int ce;
	int nxt;
};
EST BSC[5959810];
int BSC_head[554514];
int BSC_num = 0;
void bsc_init(){
	memset(BSC_head,-1,sizeof BSC_head);
	BSC_num = 0;
}
void add_BSC(int bian,int shang,int ce){
	BSC[BSC_num] = {bian,shang,ce,BSC_head[bian]};
	BSC_head[bian] = BSC_num++;
}
int n,m,T;
int ids[5545][5959];
int ps = 0;
void query(int w,int id,int color){

}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			ids[i][j] = i * n + j;
	int k;
	for(int i = 1; i <= n-1; i++){
		for(int j = 1; j <= m; j++){
			cin>>k;
			add_BSC(ids[i][j],ids[i+1][j],k);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m-1; j++){
			cin>>k;
			add_BSC(ids[i][j],ids[i][j+1],k);
		}
	}
	int sum;
	int w,id,color;
	srand(time(0));
	int wsum = 0;
	ps = n*m; 
	for(int i = 1;i<=T;i++){
		cin>>sum;
		while(sum--){
			cin>>w>>id>>color;
			int pointid = -1;
			if(id >= 1 &&id <= m){
				pointid = ids[1][id];
			}else if(id >m && id <= m+n){
				pointid = ids[id - m][m];
			}else if(id > m+n &&id<= m*2+n){
				pointid = ids[n][id - m - n];
			}else if(id > m*2+n && id <= m*2+n*2){
				pointid = ids[id-m*2-n][1];
			}
			add_BSC(++ps,pointid,w);
			query(w,id,color);
			wsum+=w;
		}
	    int g = rand();
	    cout<<g % wsum + 1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
