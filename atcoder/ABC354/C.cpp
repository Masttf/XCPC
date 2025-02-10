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
struct node{
	int x,y,id;
	bool operator <(const node&yy)const{
		if(x!=yy.x)return x>yy.x;
		else return y<yy.y;
	}
};
constexpr int Max=1e18;
void solve(){
    int n;cin>>n;
    vector<node>a(n);
    for(int i=0;i<n;i++){
    	int x,y;cin>>x>>y;
    	a[i]={x,y,i};
    }
    sort(a.begin(),a.end());
    vector<int>res;
    int mi=Max;
    for(auto [x,y,id]:a){
    	//dbg(x,y,id);
    	if(y>=mi)continue;
    	else{
    		res.push_back(id+1);
    		mi=y;
    	}
    }
    cout<<res.size()<<'\n';
    sort(res.begin(),res.end());
    for(auto x:res)cout<<x<<' ';
    cout<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}