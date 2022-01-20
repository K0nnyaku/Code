#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
struct ed{
	int d,l;
	char x;
}fei[100009];
bool cmp(ed x, ed y){
	if(x.d==y.d)return x.l<y.l;
	return x.d<y.d;
}
int n,m1,m2;
ed ch[100009];
ed chn[100009],chw[100009];
int ans,ans2,ans3;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&fei[i].d,&fei[i].l);
		fei[i].x='N';
	}
 	for(int i=1+m1;i<=m2+m1;i++){
		scanf("%d%d",&fei[i].d,&fei[i].l);
		fei[i].x='W';
	}
	sort(fei+1,fei+1+m1+m2,cmp);
	if(m1+m2<=5000){
		for(int i=1;i<=m1+m2;i++){
			for(int j=1;j<=n;j++){
				if(chn[j].d==0&&fei[i].x=='N'){
					chn[j]=fei[i];
					ans2++;
					break;
				}
				else {
					if(fei[i].x=='N'&&chn[j].l<=fei[i].d){
						chn[j]=fei[i];
						ans2++;
						break;
					}
				}
			}
		}
		for(int i=1;i<=m2+m1;i++){
			for(int j=1;j<=n;j++){
				if(chw[j].d==0&&fei[i].x=='W'){
					chw[j]=fei[i];
					ans3++;
					break;
				}
				else {
					if(fei[i].x=='W'&&chw[j].l<=fei[i].d){
						chw[j]=fei[i];
						ans3++;
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=m1+m2;i++){
		for(int j=1;j<=n;j++){
			if(ch[j].d==0){
				ch[j]=fei[i];
				ans++;
				break;
			}
			else {
				if(ch[j].x==fei[i].x&&ch[j].l<=fei[i].d){
					ch[j]=fei[i];
					ans++;
					break;
				}
			}
		}
	}
	cout<<max(ans2,max(ans,ans3));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

