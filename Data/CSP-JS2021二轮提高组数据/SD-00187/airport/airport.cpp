#include<bits/stdc++.h>
using namespace std;
int ans;
int m1,m2;
int sum1=0,total=0,sum2=0;
int n1,n2;
int maxn=-1;
struct node{
	int arrive;
	int left;
}gn[10005];
struct nod{
	int arrive;
	int left;
}gj[10005];
bool cmp(node x,node y){
	return x.arrive<y.arrive;
}
bool bmp(nod x,nod y){
	return x.arrive<y.arrive;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
    int n;
    cin>>n>>m1>>m2;
    if(n>m1+m2) cout<<m1+m2; 
	for(int i=1;i<=m1;i++){
		cin>>gn[i].arrive>>gn[i].left;
	}   
	for(int i=1;i<=m2;i++){
		cin>>gj[i].arrive>>gj[i].left;
	} 
	sort(gn+1,gn+n+1,cmp);
	sort(gj+1,gj+n+1,bmp);
	for(int i=0;i<=n;i++){
		n1=i;
		n2=n-n1;
		for(int j=0;j<=n1;j++){
			if(j==0){
				sum1=0;
			}
			else{
				for(int k=1;k<=m1;k++){
				if(gn[j].left<=gn[j+k].arrive){
					sum1++;
				} 
				if((gn[j].left>=gn[j+k].arrive)&&(gn[j].left<=gn[j+k].left)){
					if(n1>=1){
						n1--;
						sum1++;
						if(n1==0) break;}
					}
				}
			}
		}
		for(int l=0;l<=n2;l++){
			if(l==0){
				sum2=0;
			}
			else{
				for(int z=1;z<=m2;z++){
					if(gj[l].left<=gj[l+z].arrive){
						sum2++;
					}
					if((gj[l].left>=gj[l+z].arrive)&&(gj[l].left<=gj[l+z].left)){
						if(n2>=1){
							n2--;
							sum2++;
							if(n2==0) break;
						}
					}
				}
			}
		}
		total=sum1+sum2;
		ans=max(maxn,total);
		sum1=0;
		sum2=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

