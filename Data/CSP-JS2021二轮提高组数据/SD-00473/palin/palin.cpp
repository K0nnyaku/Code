#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<bits/stdc++.h> 
using namespace std;
int t,n,a[111111],sum[11111],flag,b[11111],sa,sb,summ[11111],m,mm,ywx;
string c;
string cc;

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cin>>m>>mm;
			if(m!=mm){
				cout<<-1<<endl;
			}
			else {
				cout<<"LL"<<endl;
			}
		}
		if(n==2){
			for(int i=1;i<=4;i++){
				cin>>a[i];
				sum[a[i]]++;
			}
			for(int i=1;i<=4;i++){
				if(sum[i]%2!=0){
					cout<<-1<<endl;
					ywx=1;
					break;
			    }
			}
			if(ywx==0){
			    if(a[1]==a[4]&&a[2]==a[3]){
			    	cout<<"LLLL";
					cout<<endl;
			    	ywx=0;
			    }
			    else{
			    	cout<<"LRLR"<<endl;
			    	ywx=0;
				}
			}
			
		}
		if(n==3){
			for(int i=1;i<=6;i++){
				cin>>a[i];
				sum[a[i]]++;
			}
			for(int i=1;i<=6;i++){
				if(sum[i]%2!=0){
					cout<<-1<<endl;
					ywx=1;
					break;
			    }
			}
			if(ywx==0){
				for(int i=1;i<=3;i++){
				    if(a[i]!=a[n-i+1]){
					    ywx=1;
					    break;
				    }
			    }
			    if(ywx==0){
			    	cout<<"LLLLLL";
					cout<<endl;
			    	ywx=0;
			    }
				else{
					if(a[1]==a[6]){
						cout<<-1<<endl;
					}
					if(a[1]==a[4]&&a[2]==a[6]){
						cout<<-1<<endl;
					}
					else{
						if(a[1]==a[4]){
							cout<<"LLLRRR"<<endl;
						}
				    }
				}
			}
		}
		if(n>3){
			for(int i=1;i<=n*2;i++){
				cin>>a[i];
			}
			
			for(int i=1;i<=n*2;i++){
				if(sum[i]%2!=0){
					cout<<-1<<endl;
					ywx=1;
					break;
			    }
			}
			for(int i=1;i<=n*2;i++){
				if(a[i]!=a[i+n*2+1]){
					flag=1;
				}
			}
			if(flag==0){
				for(int i=1;i<=n;i++){
					cout<<"L";
				}
				for(int i=1;i<=n;i++){
					cout<<"R";
				}
				cout<<endl;
				flag=0;
			}
			if(ywx==0){
				for(int i=1;i<=n/2;i++){
				    if(a[i]!=a[2*n-i+1]){
					    ywx=1;
					    break;
				    }
			    }
			    if(ywx==0){
			    	
			    	for(int i=1;i<=n*2;i++){
			    		cout<<'L';
					}
					cout<<endl;
			    	ywx=0;
				}
				else{
					if(a[1]==a[n]){
						cout<<-1<<endl;
						ywx=0;
					}
					if(ywx==1){
						for(int i=1;i<=n*2;i++){
				        if(i%2==0){
					       cout<<'R';
				        } 
				        else{
					         cout<<'L';
				        }
			        }
			        cout<<endl;
					}
					
					
				}
				
				
		    }
		}
		
		
		
		
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
 } 
 /*2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3*/
