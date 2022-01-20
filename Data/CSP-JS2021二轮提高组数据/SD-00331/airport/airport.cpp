#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long lld;
typedef unsigned long long ull;
const int N=1e5+5;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>'0'&&ch<'9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x>9) write(x/10);
	putchar('0'^(x%10));
}

ull x1[N],x2[N],y1[N],y2[N];
bool vis[N]; 
ull time1,time2;
lld num1,num2;
lld ans1,ans2;
int n,x,y;
ull ans=0;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),x=read(),y=read();
	
	
	for(int iii=1;iii<=x;iii++){
		x1[iii]=read();
		y1[iii]=read();
		for(int i=1;i<=n;i++){		
			num1=i;
			if(vis[i]==1){
				for(int k=i;k<=y;k++){
				if(time1>y1[iii]&&time1<x1[iii+k]){
					ans1++;
					num1--;
					time1-=y1[iii];
					vis[i]=0;
				}
			}
				if(time1<y1[iii]&&num2>0){
					ans2++;
					num2--;
				}
				if(num1<0){
					break;
				}
		}
			if(vis[i]==0){
				vis[i]=1;
				ans1++;
				time1+=y1[iii];
				num1--;
			}
			if(num1<0){
					break;
				}
			for(int j=n;j>=i;j--){
				num2=j;
				if(vis[j]==1){
					for(int k=x;k>=j;k--){
					if(time1>y1[iii]&&time1<x1[iii+k]){
						ans1++;
						num1--;
						time1-=y1[iii];
						vis[j]=0;
					}
				}
					if(time1<y1[iii]&&num2>0){
						ans2++;
						num2--;
					}
					if(num2<0){
						break;
					}
			}
				if(vis[j]==0){
					vis[j]=1;
					ans1++;
					time1+=y1[iii];
				}
				if(num2<0){
					break;
				}
			}
		}
	}
	for(int iii=1;iii<=y;iii++){
		x2[iii]=read();
		y2[iii]=read();
		for(int i=1;i<=n;i++){		
			num1=i;
			if(vis[i]==1){
				for(int k=i;k<=y;k++){
					if(time2>y2[iii]&&time2<x2[iii+k]){
					ans2++;
					num2--;
					time2-=y2[iii];
					vis[i]=0;
					}
				}
					if(time2<y2[iii]&&num1>0){
						ans1++;
						num1--;
					}
					if(num1<0){
						break;
					}
				
			}
			if(vis[i]==0){
				vis[i]=1;
				ans2++;
				time2+=y2[iii];
			}
			if(num1<0){
					break;
				}
			for(int j=n;j>=i;j--){
				num2=j;
				if(vis[j]==1){
					for(int k=y;k>=j;k--){
							if(time2>y2[iii]&&time2<x2[iii+k]){
						ans2++;
						num2--;
						time2-=y2[iii];
						vis[j]=0;
					}
				}
					if(time2<y2[iii]&&num1>0){
						ans1++;
						num1--;
					}
					if(num2<0){
						break;
					}
			}
				if(vis[j]==0){
					vis[j]=1;
					ans2++;
					time2+=y2[iii];
				}
				if(num2<0){
					break;
				}
			}
		}
	}
	ans=min(ans1,ans2)/2;
	write(ans);
	return 0;
}
