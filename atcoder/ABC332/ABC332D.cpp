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
const int maxn=10;
int a[maxn][maxn];
int b[maxn][maxn];
void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>b[i][j];
	}
	
	auto get = [&]()->int{
		int ans=-1;
		vector<int>t1(n);
		vector<int>t2(m);
		for(int i=1;i<=n;i++)t1[i-1]=i;
		for(int i=1;i<=m;i++)t2[i-1]=i;
		auto check = [&]()->bool{
			int ok=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(a[t1[i-1]][t2[j-1]]!=b[i][j])ok=0;
				}
			}
			return ok;
		};
		do{
			do{
				if(check()){
					int cnt=0;
					for(int i=0;i<n;i++){
						for(int j=i+1;j<n;j++){
							if(t1[i]>t1[j])cnt++;
						}
					}
					for(int i=0;i<m;i++){
						for(int j=i+1;j<m;j++){
							if(t2[i]>t2[j])cnt++;
						}
					}
					if(ans==-1)ans=cnt;
					else ans=min(ans,cnt);
				}
			}while(next_permutation(t2.begin(),t2.end()));
		}while(next_permutation(t1.begin(),t1.end()));
		return ans;
	};
	cout<<get()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}