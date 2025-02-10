#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)

void err() {
	cout<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ...args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,q;cin>>n>>q;
	vector<pair<int,int>>res;
	int x=1,y=0;
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			char dir;cin>>dir;
			if(dir=='U'){
				y++;
			}else if(dir=='D'){
				y--;
			}else if(dir=='L'){
				x--;
			}else x++;
			res.push_back({x,y});
			//dbg(x,y);
		}else{
			int len=res.size();
			int x;cin>>x;
			if(x>len)cout<<x-len<<' '<<0<<'\n';
			else{
				//dbg(len-x);
				cout<<res[len-x].first<<' '<<res[len-x].second<<'\n';
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}