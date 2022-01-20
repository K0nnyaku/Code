#include<bits/stdc++.h>
using namespace std;
int t,n,lef,rig,cnt,num;
int b[1000010],a[1000010],way[1000010];
int judge(int p){
	for(int x=1;x<=p;x++)
	if(b[x]!=b[2*p+1-x])
	return 0;
	return 1;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=2*n;j++)
		cin>>a[j];
		num=0;
		cnt=0;
		lef=0;
		rig=2*n+1;
		if(n==1){
			cout<<"LL"<<endl;
		}
		if(n==2){
			for(int i1=0;i1<=1;i1++){
				if(i1==0)
				b[1]=a[++lef];
				else
				b[1]=a[--rig];
				for(int i2=0;i2<=1;i2++){
					if(i2==0)
					b[2]=a[++lef];
					else
					b[2]=a[--rig];
					for(int i3=0;i3<=1;i3++){
						if(i3==0)
						b[3]=a[++lef];
						else
						b[3]=a[--rig];
						for(int i4=0;i4<=1;i4++){
							if(i4==0)
								b[4]=a[++lef];
							else
							b[4]=a[--rig];
							if(judge(n)==1){
								cnt=1;
								num=4;
								way[1]=i1;
								way[2]=i2;
								way[3]=i3;
								way[4]=i4;
								break;
							}
						}
						if(i3==0)
						lef--;
						else
						rig++;
						if(cnt==1)
						break;
					}
					if(i2==0)
					lef--;
					else
					rig++;
					if(cnt==1)
					break;
				}
				if(i1==0)
				lef--;
				else
				rig++;
				if(cnt==1)
				break;
			}
		}
		if(n==3){
			for(int i1=0;i1<=1;i1++){
				if(i1==0)
				b[1]=a[++lef];
				else
				b[1]=a[--rig];
				for(int i2=0;i2<=1;i2++){
					if(i2==0)
					b[2]=a[++lef];
					else
					b[2]=a[--rig];
					for(int i3=0;i3<=1;i3++){
						if(i3==0)
						b[3]=a[++lef];
						else
						b[3]=a[--rig];
						for(int i4=0;i4<=1;i4++){
							if(i4==0)
							b[4]=a[++lef];
							else
							b[4]=a[--rig];
							for(int i5=0;i5<=1;i5++){
								if(i5==0)
								b[5]=a[++lef];
								else
								b[5]=a[--rig];
								for(int i6=0;i6<=1;i6++){
									if(i6==0)
									b[6]=a[++lef];
									else
									b[6]=a[--rig];
									if(judge(n)==1){
										cnt=1;
										num=6;
										way[1]=i1;
										way[2]=i2;
										way[3]=i3;
										way[4]=i4;
										way[5]=i5;
										way[6]=i6;
										break;
									}
								}
								if(i5==0)
								lef--;
								else
								rig++;
								if(cnt==1)
								break;
							}
							if(i4==0)
							lef--;
							else
							rig++;
							if(cnt==1)
							break;
						}
						if(i3==0)
						lef--;
						else
						rig++;
						if(cnt==1)
						break;
					}
					if(i2==0)
					lef--;
					else
					rig++;
					if(cnt==1)
					break;
				}
				if(i1==0)
				lef--;
				else
				rig++;
				if(cnt==1)
				break;
			}
		}
		if(cnt==1){
			for(int i=1;i<=num;i++){
				if(way[i]==0)
				cout<<"L";
				else
				cout<<"R";
			}
			cout<<endl;
		}
		else
		cout<<-1<<endl;
	}
	return 0;
} 
