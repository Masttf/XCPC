#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int k[maxn];
void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>k[i];
	sort(k+1,k+1+n);
	for(int i=1;i<=m;i++){
		double a,b,c;cin>>a>>b>>c;
		if(c<0)cout<<"NO\n";
		else{
			int it=lower_bound(k+1,k+1+n,b)-k;
			int f=0;
			for(int i=it,j=1;i<=n&&j<=75;i++,j++){
				if((b-k[i])*(b-k[i])-4*a*c<0){
					f=1;
					cout<<"YES\n"<<k[i]<<'\n';
					break;
				}
			}
			if(!f){
				for(int i=it-1,j=1;i>=1&&j<=75;i--,j++){
					if((b-k[i])*(b-k[i])-4*a*c<0){
						f=1;
						cout<<"YES\n"<<k[i]<<'\n';
						break;
					}
				}
			}
			if(!f)cout<<"NO\n";
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
