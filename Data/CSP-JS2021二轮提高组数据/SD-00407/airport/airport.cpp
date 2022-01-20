#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#define max_n 100005
using namespace std;
struct node{
	int s,t;
}nd1[max_n],nd2[max_n];
int k1[max_n*2],k2[max_n*2];
int tag1[max_n*2],tag2[max_n*2];
int n,m1,m2,n1,n2,cnt1,cnt2,tot1,tot2;
int rec1,rec2,num1,num2,temp,ans;
inline int read(){
	int flag=1,ans=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')flag=-flag;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=(ans<<1)+(ans<<3)+ch-'0';
		ch=getchar();
	}
	return flag*ans;
}
inline bool cmp(node x,node y){
	return x.s<y.s;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		nd1[++cnt1].s=read(),nd1[cnt1].t=read();
		k1[++tot1]=nd1[cnt1].s;
		k1[++tot1]=nd1[cnt1].t;
	}
	sort(nd1+1,nd1+cnt1+1,cmp);
	sort(k1+1,k1+tot1+1);
	for(int i=1;i<=m2;i++){
		nd2[++cnt2].s=read(),nd2[cnt2].t=read();
		k2[++tot2]=nd2[cnt2].s;
		k2[++tot2]=nd2[cnt2].t;
	}
	sort(nd2+1,nd2+cnt2+1,cmp);
	sort(k2+1,k2+tot2+1);
	for(int i=0;i<=n;i++){
		temp=0;
		n1=i,n2=n-i;
		num1=num2=0;
		rec1=rec2=0;
		memset(tag1,0,sizeof(tag1));
		memset(tag2,0,sizeof(tag2));
		for(int j=1;j<=tot1;j++){
			num1+=tag1[j];
//			printf("j=%d rec1+1=%d num1=%d\n",j,rec1+1,num1);
			if(k1[j]==nd1[rec1+1].s){
				rec1++;
				if(num1>=n1)continue;
				num1++;temp++;
//				printf("rec %d %d\n",rec1,lower_bound(k1+1,k1+tot1+1,nd1[rec1].t)-k1);
				tag1[lower_bound(k1+1,k1+tot1+1,nd1[rec1].t)-k1]--;
			}
		}
//		printf("1 %d %d\n",n1,temp);
		for(int j=1;j<=tot2;j++){
			num2+=tag2[j];
			if(k2[j]==nd2[rec2+1].s){
				rec2++;
				if(num2>=n2)continue;
				num2++;temp++;
				tag2[lower_bound(k2+1,k2+tot2+1,nd2[rec2].t)-k2]--;
			}
		}
//		printf("2 %d %d\n",n2,temp);
		ans=max(ans,temp);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

