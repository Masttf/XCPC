#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	int ok=1;
	int temp=m;
	int cnt=0;
	int temp2=n;
	for(int i=2;i*i<=temp;i++){
		if(temp%i==0){
			while(temp%i==0){
				temp/=i;
				if(i==2)cnt++;
				else{
					if(temp2%i==0)temp2/=i;
					else ok=0;
				}
			}
		}
	}
	if(temp!=1){
		if(temp==2)cnt++;
		if(temp!=2&&temp2%temp!=0)ok=0;
	}
	if(ok==0){
		cout<<-1<<'\n';
		return ;
	}else{
		temp=n;
		while(temp%2==0){
			temp/=2;
			cnt--;
		}
		if(cnt<=0){
			cout<<0<<'\n';
			return ;
		}
		int ans=0;
		n%=m;
		while(n){
			if(n>=m)n-=m;
			ans+=n;
			n*=2;
		}
		cout<<ans<<'\n';
	}
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
