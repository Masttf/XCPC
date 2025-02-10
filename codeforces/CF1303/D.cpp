#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n,m;cin>>n>>m;
    vector<int>cnt(65);
    int sum=0;
    for(int i=1;i<=m;i++){
    	int x;cin>>x;
    	sum+=x;
    	cnt[__lg(x)]++;
    }
    if(sum<n){
    	cout<<-1<<'\n';
    	return ;
    }
    int ans=0;
    for(int i=0;i<=63;i++){
    	if(n>>i&1){
    		if(cnt[i])cnt[i]--;
    		else{
    			for(int j=i+1;j<=63;j++){
    				if(cnt[j]){
    					cnt[j]--;
    					for(int k=j-1;k>=i;k--){
    						ans++;
    						cnt[k]++;
    					}
    					break;
    				}
    			}
    		}
    	}
    	cnt[i+1]+=cnt[i]/2;
    }
    cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}