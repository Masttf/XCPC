#include<bits/stdc++.h>
//#define int long long
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
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<vector<int>>res(n+1);
	int mx=1e7;
	vector<int>ct(mx+1);
	for(int i=1;i<=n;i++){
		int temp=a[i];
		for(int j=2;j*j<=temp;j++){
			if(temp%j==0){	
				int cnt=0;
				while(temp%j==0){
					temp/=j;
					cnt++;
				}
				if(cnt%2==1){
					res[i].push_back(j);
					ct[j]++;
				}
			}
		}
		if(temp!=1){
			res[i].push_back(temp);
			ct[temp]++;
		}
	}
	int block=sqrt(8*n);
	//dbg(block);
	vector<int>pos(mx+1);
	vector pre(2*block+1,vector<int>(n+1));
	int tot=1;
	for(int i=1;i<=mx;i++){
		if(ct[i]*2>block)pos[i]=tot++;
	}
	if(tot>2*block){
		while(1);
	}
	//assert(tot<=5*block);
	vector<int>val(n+1);
	for(int i=1;i<=n;i++){
		val[i]=val[i-1];
		for(int j=1;j<=2*block;j++)pre[j][i]=pre[j][i-1];
		for(auto x:res[i]){
			if(ct[x]*2<=block)val[i]++;
			else{
				if(pos[x]>5*block){
					while(1);
				}
				pre[pos[x]][i]++;
			}
		}
	}
	int last=0;
	auto solve1 = [&](int l,int r)->void{
		int ans=0;
		unordered_map<int,int>m;
		for(int i=l;i<=r;i++){
			for(auto x:res[i]){
				m[x]++;
			}
		}
		for(auto [x,y]:m){
			ans+=min(y,r-l+1-y);
		}
		last=ans;
	};
	auto solve2 = [&](int l,int r)->void{
		int ans=val[r]-val[l-1];
		for(int i=1;i<=2*block;i++){
			int num=pre[i][r]-pre[i][l-1];
			ans+=min(num,r-l+1-num);
		}
		last=ans;
	};
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		l^=last,r^=last;
		if(r-l+1<=block)solve1(l,r);
		else solve2(l,r);
		cout<<last<<'\n';
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