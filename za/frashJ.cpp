#include<bits/stdc++.h>
using namespace std;
int judge(int x){
	if(x>=3000)return 1;
	else if(x>=2600&&x<=2999)return 2;
	else if(x>=2400&&x<=2599)return 3;
	else if(x>=2300&&x<=2399)return 4;
	else if(x>=2100&&x<=2299)return 5;
	else if(x>=1900&&x<=2099)return 6;
	else if(x>=1600&&x<=1899)return 7;
	else if(x>=1400&&x<=1599)return 8;
	else if(x>=1200&&x<=1399)return 9;
	else return 10;
}
string name[]={"","Legendary grandmaster","International grandmaster","Grandmaster","International master"
	,"Master","Candidate master","Expert","Specialist","Pupil","Newbie"};
int main(){
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		int a;
		int flag=judge(k);
		for(int i=1;i<=n;i++){
			cin>>a;
			k+=a;
			int temp=judge(k);
			if(flag!=temp){
				cout<<name[flag]<<" -> "<<name[temp]<<'\n';
			}
			flag=temp;
		}
		cout<<name[flag]<<'\n';
	}
	return 0;
}
