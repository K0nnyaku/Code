#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2;
int ans=-1;
int ka=1,kb;
struct nod{
	int x,y;
}a[100010],b[100010];
struct node{
	int num,la;
}f[100010];
int read(){
	int s=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*w;
}
bool cmp(nod q,nod p){
	if(q.x!=p.x){
		return q.x<p.x;
	}else{
		return q.y<p.y;
	}
}
bool cm(node q,node p){
	return q.num>p.num;
}
void dfs(int na,int nb,int sum,int anss){
	if(sum==n){
		ans=max(ans,anss);
		return;
	}
	if(na==ka+1&&nb==kb+1){
		ans=max(ans,anss);
		return;
	} 
	if(na==ka+1&&nb!=kb+1){
		dfs(na,nb+1,sum+1,anss+f[nb].num);
		return;
	}
	if(nb==kb+1&&na!=ka+1){
		dfs(na+1,nb,sum+1,anss+f[na].num);
		return;
	}
	if(f[na].num>f[nb].num){
		dfs(na+1,nb,sum+1,anss+f[na].num);
	}else if(f[na].num<f[nb].num){
		dfs(na,nb+1,sum+1,anss+f[nb].num);
	}else{
		dfs(na+1,nb,sum+1,anss+f[na].num);
		dfs(na,nb+1,sum+1,anss+f[nb].num);
	}
	return;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		a[i].x=read(),a[i].y=read();
	}
	for(int i=1;i<=m2;i++){
		b[i].x=read(),b[i].y=read();
	} 
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=m1;i++){
		bool flag=0;
		int sum,mila=100000010;
		for(int j=1;j<=ka;j++){
			if(f[j].la<a[i].x&&f[j].la<mila){
				sum=j;
				mila=f[j].la;
				flag=1;
				break;
			}
		}
		if(flag){
			f[sum].num++;
			f[sum].la=a[i].y;
		}
		if(!flag){
			ka++;
			f[ka].num=1;
			f[ka].la=a[i].y;
		}
	}
	kb=ka+1;
	for(int i=1;i<=m2;i++){
		bool flag=0;
		int sum,mila=100000010;
		for(int j=ka+1;j<=kb;j++){
			if(f[j].la<b[i].x&&f[j].la<mila){
				sum=j;
				mila=f[j].la;
				flag=1;
				break;
			}
		}
		if(flag){
			f[sum].num++;
			f[sum].la=b[i].y;
		}
		if(!flag){
			kb++;
			f[kb].num=1;
			f[kb].la=b[i].y;
		}
	}
	int na=1,nb=ka+1;
	dfs(na,nb,0,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
