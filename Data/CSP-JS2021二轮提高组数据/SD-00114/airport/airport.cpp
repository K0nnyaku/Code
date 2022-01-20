//__frj SD-00114
//题目名，注释。保存，freopen
//不要想着A题，打暴力就行了！
//TIME +7min
//21!9-324@emb
//期望100
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define ll long long
#define ull unsigned long long
using namespace std;
int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
struct Node{
	int l,r;
};
int n,m1,m2,tot=0;
Node a[200007],b[200007];
int c[400007];
priority_queue<pair<int,int> > q; 
int tree1[100007*4],tree2[100007*4];//树状数组 
int f1[200007],f2[200007];//第i辆飞机加进来前，机库容量 
int tong1[200007],tong2[200007];
int lowbit(int x){
	return x&(-x);
} 
int add1(int x,int y){
	while(x<=tot){
		tree1[x]+=y;
		x+=lowbit(x);
	}
}
int add2(int x,int y){
	while(x<=tot){
		tree2[x]+=y;
		x+=lowbit(x);	
	}
}
int query1(int x){
	int sum=0;
	while(x>0){
		sum+=tree1[x];
		x-=lowbit(x);
	}
	return sum;
}
int query2(int x){
	int sum=0;
	while(x>0){
		sum+=tree2[x];
		x-=lowbit(x);		
	} 
	return sum;
}
int vis[5007];
bool cmp(Node c,Node d){
	return c.l < d.l; 
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		int x=read(),y=read();
		c[++tot]=x;
		c[++tot]=y;
		a[i].l=x,a[i].r=y;
	}
	for(int i=1;i<=m2;i++){
		int x=read(),y=read();
		c[++tot]=x;
		c[++tot]=y;
		b[i].l=x,b[i].r=y;
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	sort(c+1,c+tot+1);
	unique(c+1,c+tot+1);
	for(int i=1;i<=m1;i++){
		a[i].l=lower_bound(c+1,c+tot+1,a[i].l)-c;
		a[i].r=lower_bound(c+1,c+tot+1,a[i].r)-c;
		
	}
	for(int i=1;i<=m2;i++){
		b[i].l=lower_bound(c+1,c+tot+1,b[i].l)-c;
		b[i].r=lower_bound(c+1,c+tot+1,b[i].r)-c;
	}
/*	for(int i=1;i<=m1;i++){
		f1[i]=query1(a[i].l);
		add1(a[i].l,1);add1(a[i].r+1,-1);
		cout<<f1[i]<<' ';
		
	}
	cout<<endl;
	for(int i=1;i<=m2;i++){
		f2[i]=query2(b[i].l);
		add2(b[i].l,1);add2(b[i].r+1,-1);
	}*/
	int maxx=0;int ans1=0,ans2=0;
	if(n<=100&&m1<=100&&m2<=100){
		for(int i=0;i<=n;i++){
		ans1=0,ans2=0;
		int t=n-i;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=m1;j++){
			if(vis[a[j].l]<i){
				ans1++;
				for(int k=a[j].l+1;k<a[j].r;k++){
				vis[k]++;
				}
			} 
			else{
				continue;
			}
		}
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=m2;j++){
			if(vis[b[j].l]<t){
				ans2++;
				for(int k=b[j].l;k<=b[j].r;k++){
				vis[k]++;
		     	}
			} 
			else{
				continue;
			}
		}
		maxx=max(ans1+ans2,maxx);
 		}
	cout<<maxx;
	} 
	else{
		for(int i=1;i<=m1;i++){
			q.push(make_pair(-a[i].r,i));
			int t=0;
			while(-q.top().first<a[i].l){
				t=q.top().second; 
				q.pop();
			}
			if(t==0){
				f1[i]=q.size(); 
			}
			else{
				f1[i]=f1[t];
			}
		}
		while(!q.empty()) q.pop();
		for(int i=1;i<=m2;i++){
			q.push(make_pair(-b[i].r,i));
			int t=0;
			while(-q.top().first<b[i].l){
				t=q.top().second; 
				q.pop();
			} 
			if(t==0){
				f2[i]=q.size(); 
			}
			else{
				f2[i]=f2[t];
			}
		}
		for(int i=1;i<=m1;i++){
			tong1[f1[i]]++;
		}
		for(int i=1;i<=n;i++){
			tong1[i]+=tong1[i-1];
		}
		for(int i=1;i<=m2;i++){
			tong2[f2[i]]++;
		}
		for(int i=1;i<=n;i++){
			tong2[i]+=tong2[i-1];
		}
		for(int i=0;i<=n;i++){
			maxx=max(tong1[i]+tong2[n-i],maxx);
		}
		cout<<maxx;
	}
		
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//要开ll吗？会MLE吗？sizeof
//I AK CSP-S！


