#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int read(){
	char ch=getchar();
	if(ch!='-'&&(ch>'9'||ch<'0')){
		ch=getchar();
	}
	int ans=0,t=1;
	if(ch=='-'){
		t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*t;
}
int p,n,m;
int ansa[N]={0},ansb[N]={0};
struct Node{
	int s,f;
};
Node a[N],b[N];
bool cmp(Node x,Node y){
	return x.s<y.s;
}
bool cmp2(int x,int y){
	return a[x].f<a[y].f;
}
bool cmp3(int x,int y){
	return b[x].f<b[y].f;
}
void inti(){
	for(int i=1;i<=p;i++){
		ansa[i]=0;
		ansb[i]=0;
	}
}
namespace task1{
	int ans;
	void solve(){
		for(int i=1;i<=p;i++){
			int pss[N];//所在机场的飞机的编号 
			int num=0;//现在机场飞机的数量 
			int head=1;
			int tail=0;
			for(int j=1;j<=n;j++){
				if(num<i){
					tail++;
					pss[tail]=j;
					num++;
				}
				else{
					for(int k=head;k<=tail;k++){
						if((a[k].f<=a[j].s)){
							head++;
							tail++;
							pss[tail]=j;
							num++;
							break;
						}
					}
				}
				sort(pss+head+1,pss+tail+1,cmp2);
			}
			ansa[i]=num;
		}
		for(int i=1;i<=p;i++){
			int pss[N];//所在机场的飞机的编号 
			int num=0;//现在机场飞机的数量 
			int head=1;
			int tail=0;
			for(int j=1;j<=m;j++){
				if(num<i){
					tail++;
					pss[tail]=j;
					num++;
				}
				else{
					for(int k=head;k<=tail;k++){
						if((b[k].f<=b[j].s)){
							head++;
							tail++;
							pss[tail]=j;
							num++;
							break;
						}
					}
				}
				sort(pss+head+1,pss+tail+1,cmp3);
			}
			ansb[i]=num;
		}
		for(int i=0;i<=p;i++){
			ans=max(ans,ansa[i]+ansb[p-i]);
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	p=read(),n=read(),m=read();
	inti();
	for(int i=1;i<=n;i++){
		a[i].s=read(),a[i].f=read();
	}
	for(int i=1;i<=m;i++){
		b[i].s=read(),b[i].f=read();
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,cmp); 
	if(n<=1000)task1::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

