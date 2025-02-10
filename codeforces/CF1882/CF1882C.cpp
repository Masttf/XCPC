#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=n;i>=1;i--){
		if(a[i]>0){
			if(i%2==1)ans+=a[i];
			else{
				if(a[i-1]>=0){
					ans+=a[i];
				}else{
					int temp=0;
					int t=i;
					for(;i>=1;i--){
						if(a[i]>0)temp+=a[i];
						if(a[i]>0&&i%2==1){
							ans+=temp;
							break;
						}
					}
					if(!i){
						int d=0;
						int ok=0;
						for(int j=1;j<=t;j++){
							if(j%2==0&&a[j]>=0){
								d=a[j];
								if(j>3)ok=1;
								break;
							}
						}
						if(ok)ans+=temp;
						else ans+=max({0LL,temp-d,a[1]+temp});	
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
