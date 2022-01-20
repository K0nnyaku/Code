#include<cstdio>
#include<queue>
using namespace std;
int n,m,T,k;
int len[504][504][4];// 0东 1南 2西 3北 
int dis[504][504];
bool color[505][505];
int mx[4]={0,0,1,-1},my[4]={1,-1,0,0};

struct node{
	int x,y,zon;
	bool operator <(const node x)const{
		return x.zon<zon;
	}
};
priority_queue<node>p;

int find(const int x,const int y){
	p.push((node){x,y,dis[x][y]});
	while(p.empty()){
		node temp=p.top();
		p.pop();
		int xx,yy;
		for(int i=0;i<4;++i){
			xx=temp.x+mx[i];
			yy=temp.y+my[i];
			if(!dis[xx][yy]){
				p.push((node){xx,yy,dis[xx][yy]});
			}
		}
	}
	return 1;
}

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout); 
	int temp=0; 
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n-1;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&temp);
			len[i][j][1]=len[i+1][j][3]=temp;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m-1;++j){
			scanf("%d",&temp);
			len[i][j][0]=len[i][j+1][2]=temp;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			dis[i][j]=len[i][j][0]+len[i][j][1]+len[i][j][2]+len[i][j][3]; 
		}
	}
	int xx,pp,tt;
	int tx,ty;
	while(T--){
		scanf("%d",&k);
		for(int i=1;i<=k;++i){
			scanf("%d%d%d",&xx,&pp,&tt);
			if(pp>2*m+n){
				tx=2*m+2*n-pp+1;
				ty=0;
				dis[tx][ty+1]+=dis[tx][ty]=len[tx][ty+1][2]=xx;
			}
			else if(pp>m+n){
				tx=n+1;
				ty=2*m+n-pp+1;
				dis[tx-1][ty]+=dis[tx][ty]=len[tx-1][ty][1]=xx;
			}
			else if(pp>m){
				tx=pp-m;
				ty=m+1;
				dis[tx][ty-1]+=dis[tx][ty]=len[tx][ty-1][0]=xx;
			}
			else{
				tx=0;
				ty=pp;
				dis[tx+1][ty]+=dis[tx][ty]=len[tx+1][ty][3]=xx;
			}
		}
	}
	return 0;
}
