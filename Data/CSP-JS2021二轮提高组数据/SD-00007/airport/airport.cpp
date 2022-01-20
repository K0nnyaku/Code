#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int MM=100005;
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x;
}

struct node{
	int num,v;
};
node a1[MM],a2[MM];
int b1[MM],b2[MM];//
bool cmp(const node & x,const node & y){
	return x.v<y.v;
}
bool p1[MM],p2[MM];
int ans1[MM],ans2[MM];//答案长度
int front1[MM],front2[MM];//qianqu 
int start1[MM],start2[MM];//起始点 
int tail1[MM],tail2[MM];//arrive排序 

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,i,j,k,m1,m2,cnt1=0,cnt2=0;
	cin>>n>>m1>>m2;
	for(i=1;i<=m1;i++){
		a1[i].num=i;;
		a1[i].v=read();b1[i]=read();

	}
	for(i=1;i<=m2;i++){
		a2[i].num=i;
		a2[i].v=read();b2[i]=read();

	}
	
	sort(a1+1,a1+m1+1,cmp);

	sort(a2+1,a2+m2+1,cmp);

	for(i=1;i<=m1;i++){
		tail1[i]=a1[i].v;
	}
	tail1[m1+1]=1e9;
	for(i=1;i<=m2;i++){
		tail2[i]=a2[i].v;
	}
	tail2[m2+1]=1e9;
	for(i=1;i<=m1;i++){
		
		int kkk=a1[i].num;
		if(p1[kkk]) continue;
		if(!p1[kkk]&&cnt1<=n){
			p1[kkk]=1;
			cnt1++;
			start1[cnt1]=kkk;
			ans1[kkk]=1;
			front1[kkk]=kkk;
			
			int x=upper_bound(tail1+1,tail1+m1+2,b1[kkk])-tail1;
			while(x<=m1&&p1[a1[x].num]){
				x++;
			}
			
			while(x<=m1){
				front1[a1[x].num]=front1[kkk];
				ans1[front1[kkk]]++;
				p1[a1[x].num]=1;
				kkk=a1[x].num;
				x=upper_bound(tail1+1,tail1+m1+2,b1[kkk])-tail1;
				while(p1[a1[x].num]){
					x++;
				}
				
			}
		}
		if(cnt1>=n) break;
	}
	//////////
	for(i=1;i<=m2;i++){
		
		int kkk=a2[i].num;
		if(p2[kkk]) continue;
		if(!p2[kkk]&&cnt2<=n){
			p2[kkk]=1;
			cnt2++;
			start2[cnt2]=kkk;
			ans2[kkk]=1;
			front2[kkk]=kkk;
			int x=upper_bound(tail2+1,tail2+m2+2,b2[kkk])-tail2;
			while(x<=m2&&p2[a2[x].num]){
				x++;
			}
			while(x<=m2){
				front2[a2[x].num]=front2[kkk];
				ans2[front2[kkk]]++;
				p2[a2[x].num]=1;
				kkk=a2[x].num;
				x=upper_bound(tail2+1,tail2+m2+2,b2[kkk])-tail2;
				while(p2[a2[x].num]){
					x++;
				}
			}
		}
		if(cnt2>=n) break;
	}
	for(i=1;i<=cnt1;i++){
		start1[i]=ans1[start1[i]]+start1[i-1];
	}
	for(i=1;i<=cnt2;i++){
		start2[i]=ans2[start2[i]]+start2[i-1];
	}
	int maxx=0;
	for(i=min(cnt1,n);i>=1;i--){
		maxx=max(maxx,start1[i]+start2[min(cnt2,n-i)]);
	}
	cout<<maxx;
	return 0;
} 
