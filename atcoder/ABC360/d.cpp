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
	int val,f;
	bool operator < (const node&y)const{
		return val<y.val;
	}
};
void solve(){
    int n,t;cin>>n>>t;
    vector<int>a(n+1);
    string s;cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    vector<node>res(n+1);
    for(int i=1;i<=n;i++){
    	if(s[i]=='0'){
    		res[i]={a[i],-1};
    	}else{
    		res[i]={a[i],1};
    	}
    }
    sort(res.begin()+1,res.end());
    vector<int>b;
    for(int i=1;i<=n;i++){
    	if(res[i].f==-1){
    		int d=res[i].val-2*t;
    		int p=b.end()-lower_bound(b.begin(),b.end(),d);
    		ans+=p;
    	}else{
    		b.push_back(res[i].val);
    	}
    }
    cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}