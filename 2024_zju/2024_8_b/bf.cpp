#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	auto get = [&](int x)->int{
		//dbg(x);
		int res=0;
		int l=x,r=x;
		int val=a[x];
		while(l!=1||r!=n){
			//dbg(l,r,res);
			if(l==1){
				if(val>=a[r+1])res++;
				else{
					val=a[r+1];
					res+=k+1;
				}
				r++;
			}else if(r==n){
				if(val>=a[l-1])res++;
				else{
					val=a[l-1];
					res+=k+1;
				}
				l--;
			}else{
				if(a[l-1]<=a[r+1]){
					if(val>=a[l-1])res++;
					else{
						val=a[l-1];
						res+=k+1;
					}
					l--;
				}else{
					if(val>=a[r+1])res++;
					else{
						val=a[r+1];
						res+=k+1;
					}
					r++;
				}
			}
		}
		return res;
	};
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int x;cin>>x;
			swap(a[x],a[x+1]);
		}else{
			int l,r;cin>>l>>r;
			int ans=0;
			//dbg(i,l,r);
			for(int j=l;j<=r;j++)ans+=get(j);
			cout<<ans<<'\n';
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