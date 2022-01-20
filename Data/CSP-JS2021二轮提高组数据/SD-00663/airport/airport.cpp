#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define LL long long
#define Re register
//ntCCF keng wo 1000 yuan!
const int N=10001;
using namespace std;
int n,m_1,m_2;
struct NoN{
	int zhi,id;
	bool operator < (const NoN &x) const{
		return zhi>x.zhi;
	}
};
priority_queue<NoN> q1;
struct NNN{
	int lai,zou;
}aa[200010];
NNN ab[200010];
inline int read(){
	Re int x=0,f=1;Re char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
inline bool cmp(NNN x,NNN y){
	return x.lai<y.lai;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
    n=read();m_1=read();m_2=read();
    for(int i=1;i<=m_1;++i){
    	aa[i].lai=read();
    	aa[i].zou=read();
    }
    for(int i=1;i<=m_2;++i){
    	ab[i].lai=read();
    	ab[i].zou=read();
    }
    sort(aa+1,aa+1+m_1,cmp);
    sort(ab+1,ab+1+m_2,cmp);
    Re int chu=0;
    Re int xun=100000000;
    if(n*(m_1+m_2)<xun) xun=n;
    for(int e=0;e<=xun;++e){
    	Re int na=e;
    	Re int ina=n-na;
    	Re int ans=0;
    	for(int i=1;i<=m_1;++i){
    		while(!q1.empty()){
    			Re NoN gxa=q1.top();
    			if(gxa.zhi<aa[i].lai){
    				q1.pop();
    				na++;
    			}
    			else break;
    		}
    		if(na){
    			na--;
    			ans++;
    			q1.push((NoN){aa[i].zou,i});
    		}
    	}
    	while(!q1.empty()) q1.pop();
    	for(int i=1;i<=m_2;++i){
    		while(!q1.empty()){
    			Re NoN gxa=q1.top();
    			if(gxa.zhi<ab[i].lai){
    				q1.pop();
    				ina++;
    			}
    			else break;
    		}
    		if(ina){
    			ina--;
    			ans++;
    			q1.push((NoN){ab[i].zou,i});
    		}
    	}
    	while(!q1.empty()) q1.pop();
    	chu=(chu>ans)?chu:ans;
	}
	printf("%d",chu);
	return 0;
}
