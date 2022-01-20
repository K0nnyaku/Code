#include<cstdio>
#include<set>
#include<algorithm>
int n,m1,m2,k1,k2,a[200010],b[200010],cnt,tot,head[100010][4],cnt_edge[4],q1[100010],q2[100010],ans;
struct node{
	int st,ed;
}f[100010],s[100010];
struct Edge{
	int to,nxt;
}edge[100010][4];
std::set<int>ss;
inline int read(){
	register char ch=getchar();int f=1,x=0;
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline bool cmp(int x,int y){return x<y;}
inline bool cmp_edge(node x,node y){return x.st<y.st;}
inline int max(int x,int y){return x>y?x:y;}
inline void add_edge(int u,int v,int t){
	edge[++cnt_edge[t]][t].nxt=head[u][t];
	head[u][t]=cnt_edge[t];
	edge[cnt_edge[t]][t].to=v;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//freopen("data.in","r",stdin);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;++i){
		f[i].st=read();f[i].ed=read();
		a[++cnt]=f[i].st;a[++cnt]=f[i].ed;
	}
	for(int i=1;i<=m2;++i){
		s[i].st=read();s[i].ed=read();
		b[++tot]=s[i].st;b[++tot]=s[i].ed;
	}
	std::sort(f+1,f+m1+1,cmp_edge);
	std::sort(s+1,s+m2+1,cmp_edge);
	std::sort(a+1,a+cnt+1,cmp);std::sort(b+1,b+tot+1,cmp);
	k1=std::unique(a+1,a+cnt+1)-a-1;k2=std::unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<=m1;++i){
		f[i].st=std::lower_bound(a+1,a+k1+1,f[i].st)-a;
		f[i].ed=std::lower_bound(a+1,a+k1+1,f[i].ed)-a;
		add_edge(f[i].ed,i,0);
		add_edge(f[i].st,i,1);
	}
	for(int i=1;i<=m2;++i){
		s[i].st=std::lower_bound(b+1,b+k2+1,s[i].st)-b;
		s[i].ed=std::lower_bound(b+1,b+k2+1,s[i].ed)-b;
		add_edge(s[i].st,i,2);
		add_edge(s[i].ed,i,3);
	}
	int p=0;
	for(int i=1;i<=k1;++i){
		for(int j=head[i][0];j;j=edge[j][0].nxt){
			int v=edge[j][0].to;
			ss.insert(q1[v]); 
		}
		for(int j=head[i][1];j;j=edge[j][1].nxt){
			int v=edge[j][1].to;
			if(!ss.empty()){ 
				q1[v]=*ss.lower_bound(1);ss.erase(q1[v]);
			}
			else q1[v]=++p;
		}
	}
	p=0;
	ss.clear();
	for(int i=1;i<=k2;++i){
		for(int j=head[i][3];j;j=edge[j][3].nxt){
			int v=edge[j][3].to;
			ss.insert(q2[v]);
		}
		for(int j=head[i][2];j;j=edge[j][2].nxt){
			int v=edge[j][2].to;
			if(!ss.empty()){q2[v]=*ss.lower_bound(1);ss.erase(q2[v]);}
			else q2[v]=++p;
		}
	}
	std::sort(q1+1,q1+m1+1,cmp);
	std::sort(q2+1,q2+m2+1,cmp);
	ans=std::upper_bound(q2+1,q2+m2+1,n)-q2-1;
	for(int i=1;i<n;++i){
		ans=max(ans,std::upper_bound(q1+1,q1+m1+1,i)-q1-1+std::upper_bound(q2+1,q2+m2+1,n-i)-q2-1);
	}
	ans=max(ans,std::upper_bound(q1+1,q1+m1+1,n)-q1-1);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
