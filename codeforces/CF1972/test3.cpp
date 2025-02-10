#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    vector<int>tr(n+1);
    auto add = [&](int x,int val)->void{
    	while(x<=n){
    		tr[x]+=val;
    		x+=lowbit(x);
    	}
    };
    auto ask = [&](int x)->int{
    	int res=0;
    	while(x){
    		res+=tr[x];
    		x-=lowbit(x);
    	}
    	return res;
    };
    for(int i=1;i<=k;i++){
    	tr.assign(n+1,0);
    	for(int j=1;j<=n;j++)add(j,a[j]);
    	a=tr;
    	cout<<i<<endl;
    	for(int j=1;j<=n;j++){
    		cout<<a[j]<<" \n"[j==n];
    	}
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}