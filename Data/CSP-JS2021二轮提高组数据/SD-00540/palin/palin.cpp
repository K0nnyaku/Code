#include<iostream>
#include<cstdio>
#include<cstring>
#define N 2010
using namespace std;
struct node{
	int l,r;
}nei[N];
int pos[N],di[N],op[N],ans[N];
int n,a[N],T;
void up(){
	int kk=1;
	for(int i=1;i<=n;i++){
		if(ans[i]==0){
			kk=1;
			break;
		}
		if(ans[i]<op[i]){
			kk=0;
			break;
		}
		if(ans[i]>op[i]){
			kk=1;
			break;
		}
	}
	if(kk=1){
		for(int i=1;i<=n;i++)
		 ans[i]=op[i];
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(ans,0,sizeof(ans));
		memset(pos,0,sizeof(pos));
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			if(!pos[a[i]]) pos[a[i]]=i;
			else di[i]=pos[a[i]],di[pos[a[i]]]=i;
		}
		int cnt=0;
		for(int l=1;l<=n;l++){
			int r=l+n-1,flag=1;
			for(int j=l;j<=r;j++){
				if(di[j]>=l&&di[j]<=r){
					flag=0;
					break;
				}
			}
			if(flag==1){
				nei[++cnt].l=l;
				nei[cnt].r=r;
			}
		}
		int valn[N],wein[N],valw[N],weiw[N];
		for(int k=1;k<=cnt;k++){
		   int cnm=0;
		   for(int i=nei[k].l;i<=nei[k].r;i++)
	           valn[++cnm]=a[i],wein[a[i]]=cnm;
	        cnm=0;
	       for(int i=1;i<nei[k].l;i++)
	        valw[++cnm]=a[i],weiw[a[i]]=cnm;
	       for(int i=nei[k].r+1;i<=2*n;i++)
	        valw[++cnm]=a[i],weiw[a[i]]=cnm;
	       int hn,tn,hw=1,tw=n,fuck=1;
		   for(int i=1;i<=n;i++){//l
			if(i==1){
				op[i]=1;
				hn=tn=wein[valw[hw]];
				hw++;
				continue;
			}
			int x=valn[hn-1],y=valn[tn+1];
			if(valw[hw]==x){
				op[i]=1;
				hw++;
				hn--;
			}
			else if(valw[hw]==y){
				op[i]=1;
				hw++;
				tn++;
			}
			else if(valw[tw]==x){
				op[i]=2;
				tw--;
				hn--;
			}
			else if(valw[tw]==y){
				op[i]=2;
				tw--;
				tn++;
			}
			else{
				fuck=0;
				break;
			} 
 		   }
 		   if(fuck==1) up();
 		   hw=1,tw=n,fuck=1;
 		   for(int i=1;i<=n;i++){//l
			if(i==1){
				op[i]=2;
				hn=tn=wein[valw[tw]];
				tw--;
				continue;
			}
			int x=valn[hn-1],y=valn[tn+1];
			if(valw[hw]==x){
				op[i]=1;
				hw++;
				hn--;
			}
			else if(valw[hw]==y){
				op[i]=1;
				hw++;
				tn++;
			}
			else if(valw[tw]==x){
				op[i]=2;
				tw--;
				hn--;
			}
			else if(valw[tw]==y){
				op[i]=2;
				tw--;
				tn++;
			}
			else{
				fuck=0;
				break;
			} 
 		   }
 		   if(fuck==1) up();
		}
		for(int i=1;i<=n;i++){
			if(ans[i]==0) printf("-1");
			else if(ans[i]==1) printf("L");
			else printf("R");
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
