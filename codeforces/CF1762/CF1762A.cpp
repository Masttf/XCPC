#include<bits/stdc++.h>
using namespace std;
int res[55];
void slove(){
	memset(res,0,sizeof(res));
	int n;cin>>n;
	int cnt=0;
	int mi=9999999;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		if(res[i]%2!=0)cnt++;
	}
	if(cnt%2==0)cout<<0<<'\n';
	else{
		for(int i=1;i<=n;i++){
			if(res[i]%2!=0){
				int c=0;
				while(res[i]%2!=0){
					res[i]/=2;
					c++;
				}
				mi=min(mi,c);
			}
			else if(res[i]%2==0){
				int c=0;
				while(res[i]%2==0){
					res[i]/=2;
					c++;
				}
				mi=min(mi,c);
			}
		}
		cout<<mi<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		slove();
	}
	return 0;
}
