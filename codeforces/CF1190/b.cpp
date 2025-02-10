#include<bits/stdc++.h>
#define int int long long
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
	int n;cin>>n;
	vector<int>a(n+1);
	map<int,int>m;
	for(int i=1;i<=n;i++)cin>>a[i],m[a[i]]++;
	sort(a.begin()+1,a.end());
	int ok=0;
	int cnt=0;
	int f=0;
	for(int i=1;i<=n;i++){7
		int j=i;
		while(j<=n&&a[j]==a[i])j++;
		if(j-i>=3)ok=1;
		if(j-i==2)cnt++;
		if(j-i==2&&a[i]==0)ok=1;
		if(j-i==2&&m.count(a[i]-1))f=1;
		i=j-1;
	}
	if(cnt>=2||ok){
		cout<<"cslnb\n";
		return ;
	}
	if(cnt==1&&f){
		cout<<"cslnb\n";
		return ;
	}
	int sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	sum-=(n-1)*n/2;
	if(sum%2==0) cout<<"cslnb\n";
	else cout<<"sjfnb\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}