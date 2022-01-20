#include<bits/stdc++.h>
using namespace std;
const int maxn=114514;
struct node{
	int tim_in,tim_out;
};
node gn[maxn],gw[maxn];
int n,m_g,m_w,ans=-1;
bool cmp(node a,node b){
	return a.tim_in<b.tim_in;
} 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m_g,&m_w);
	for(int i=1;i<=m_g;++i) scanf("%d%d",&gn[i].tim_in,&gn[i].tim_out);
	for(int i=1;i<=m_w;++i) scanf("%d%d",&gw[i].tim_in,&gw[i].tim_out);
	sort(gn+1,gn+1+m_g,cmp);sort(gw+1,gw+1+m_w,cmp);
	for(int i=0;i<=n;++i){// i->g_n
		priority_queue< int , vector<int> , greater<int> > GN;
		priority_queue< int , vector<int> , greater<int> > GW;
		int g_n_tot=0,g_w_tot=0;
		if(i){
			for(int j=1;j<=m_g;++j){
				if(GN.size()<i){ // memory is OK
					GN.push(gn[j].tim_out);
					g_n_tot++;
				} else { // memory is not OK,but the top can go off
					int tmp=GN.top();
					if(tmp<gn[j].tim_in){
						GN.pop();
						GN.push(gn[j].tim_out);
						g_n_tot++;
					}
				}
			}
		}
		if(n-i){
			for(int j=1;j<=m_w;++j){
				if(GW.size()<n-i){
					GW.push(gw[j].tim_out);
					g_w_tot++;
				} else {
					int tmp=GW.top();
					if(tmp<gw[j].tim_in){
						GW.pop();
						GW.push(gw[j].tim_out);
						g_w_tot++;
					}
				}
			}			
		}
		ans=max(ans,g_n_tot+g_w_tot);
	}
	printf("%d\n",ans);
	return 0;
}
