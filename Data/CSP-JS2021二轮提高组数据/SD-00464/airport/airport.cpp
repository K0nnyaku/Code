#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct plane{
	int st,en;
	bool operator< (plane b)const{
		return this->st<b.st;
	}
}ch[100010],fo[100010];
struct ah{
	int az;
	bool operator< (ah b)const{
		return this->az>b.az;
	}
};
int n,m1,m2,ans,tot,maxn;
priority_queue<ah>q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&ch[i].st,&ch[i].en);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&fo[i].st,&fo[i].en);
	sort(ch+1,ch+m1+1);
	sort(fo+1,fo+m2+1);
	for(int i=0;i<=n;i++){
		while(!q.empty())
			q.pop();
		for(ans=0,tot=1;tot<=m1;){
			if(!q.empty()){
				if(ch[tot].st<q.top().az){
					if(q.size()<i){
						ans++;
						q.push({ch[tot].en});
					}
					tot++;
				}else{
					q.pop();
				}
			}else{
				if(q.size()<i){
					ans++;
					q.push({ch[tot].en});
				}
				tot++;
			}
		}
		while(!q.empty())
			q.pop();
		for(tot=1;tot<=m2;){
			if(!q.empty()){
				if(fo[tot].st<q.top().az){
					if(q.size()<n-i){
						ans++;
						q.push({fo[tot].en});
					}
					tot++;
				}else{
					q.pop();
				}
			}else{
				if(q.size()<n-i){
					ans++;
					q.push({fo[tot].en});
				}
				tot++;
			}
		}
		maxn=max(maxn,ans);
	}
	printf("%d\n",maxn);
	return 0;
}
/*
O(nmlogm)
堆和模拟
预计得分：40 
*/
