#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
int n,t;
struct node{
	vector<int> s,ans,biao;
	int eh,et;
}q[10000010];
int e[1000010];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=n*2;i++){
		q[i].s.clear();
	}
	for(int o=1;o<=1;o++){
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
			scanf("%d",&e[i]);
		int vis[500010];
		int head=0,tail=2;
		
		q[1].ans.push_back(1);
		for(int i=1;i<=n;i++)
			q[1].biao.push_back(0);
		q[1].eh=1,q[1].et=2*n;
		q[1].s.push_back(e[1]);
		q[1].biao[e[1]-1]=1;
		q[2].ans.push_back(2);
		for(int i=1;i<=n;i++)
			q[2].biao.push_back(0);
		q[2].eh=1,q[2].et=2*n;
		q[2].s.push_back(e[n*2]);
		q[2].biao[e[n*2]-1]=1;
		while(head<tail){
			
			head++;
			int len=q[head].s.size();
			//cout<<len<<endl;
			if(len<n){
				int x=e[q[head].eh+1];
				if(q[head].biao[x]==0){
					tail++;
					for(int i=0;i<q[head].ans.size();i++)
						q[tail].ans.push_back(q[head].ans[i]);
					q[tail].ans.push_back(1);
					for(int i=0;i<q[head].s.size();i++)
						q[tail].s.push_back(q[head].s[i]);
					q[tail].s.push_back(x);
					for(int i=0;i<q[head].biao.size();i++)
						q[tail].biao.push_back(q[head].biao[i]);
					q[tail].biao[x]=1;
					q[tail].eh=q[tail].eh+1;
					q[tail].et=q[tail].et;
				}
				int y=e[q[head].et-1];
				if(q[head].biao[y]==0){
					tail++;
					for(int i=0;i<q[head].ans.size();i++)
						q[tail].ans.push_back(q[head].ans[i]);
					q[tail].ans.push_back(0);
					for(int i=0;i<q[head].s.size();i++)
						q[tail].s.push_back(q[head].s[i]);
					q[tail].s.push_back(y);
					for(int i=0;i<q[head].biao.size();i++)
						q[tail].biao.push_back(q[head].biao[i]);
					q[tail].biao[x]=1;
					q[tail].eh=q[tail].eh;
					q[tail].et=q[tail].et-1;
				}
			}
			if(len==n){
				for(int i=0;i<sizeof(q[head].s);i++)
					cout<<q[head].s[i]<<" ";
				cout<<endl;
			}
			
		}
	}
	return 0;
}
