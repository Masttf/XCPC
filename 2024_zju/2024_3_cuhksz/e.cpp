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
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	int ok=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			cnt++;
		}else{
			cnt--;
			if(cnt<0)ok=0;
		}
	}
	if(!cnt&&ok){
		cout<<"Yes\n";
		cout<<1<<'\n';
		for(int i=1;i<=n;i++){
			if(s[i]=='0')cout<<'(';
			else cout<<')';
		}
		cout<<'\n';
		return ;
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1')cnt++;
	}
	if(s[1]=='0'&&s[n]=='0'&&cnt%2==0){
		vector<char>ans1(n+1),ans2(n+1);
		int cnt1=0,cnt2=0;
		int num=(n-cnt)/2;
		cnt=0;
		int nn=0;
		ok=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cnt++;
				if(cnt<=num){
					cnt1++;
					cnt2++;
					ans1[i]='(';
					ans2[i]='(';
				}else{
					cnt1--;
					cnt2--;
					if(cnt1<0)ok=0;
					if(cnt2<0)ok=0;
					ans1[i]=')';
					ans2[i]=')';
				}
				
			}else{
				nn++;
				if(nn%2==1){
					cnt1--;
					if(cnt1<0)ok=0;
					cnt2++;
					ans1[i]=')';
					ans2[i]='(';
				}else{
					cnt1++;
					cnt2--;
					if(cnt2<0)ok=0;
					ans1[i]='(';
					ans2[i]=')';
				}
			}
		}
		//assert(ok&&!cnt1&&!cnt2);
		cout<<"Yes\n";
		cout<<2<<'\n';
		for(int i=1;i<=n;i++)cout<<ans1[i];
		cout<<'\n';
		for(int i=1;i<=n;i++)cout<<ans2[i];
		cout<<'\n';
		return ;
	}
	if(s[1]=='0'&&s[n]=='1'){
		for(int i=n/2+1;i<=n;i++){
			s[i]='1'+'0'-s[i];
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1')cnt++;
		}
		if(s[1]=='0'&&s[n]=='0'&&cnt%2==0){
			// if(n%4!=0){
			// 	assert(sz%2==1);
			// }
			// assert(n%4==0||sz%2==1);
			cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0')cnt++;
			}
			vector<char>ans1(n+1),ans2(n+1);
			int cnt1=0,cnt2=0;
			int num=cnt/2;
			cnt=0;
			int nn=0;
			ok=1;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'){
					cnt++;
					if(cnt<=num){
						cnt1++;
						cnt2++;
						ans1[i]='(';
						ans2[i]='(';
					}else{
						cnt1--;
						cnt2--;
						if(cnt1<0)ok=0;
						if(cnt2<0)ok=0;
						ans1[i]=')';
						ans2[i]=')';
					}
					
				}else{
					nn++;
					if(nn%2==1){
						cnt1--;
						if(cnt1<0)ok=0;
						cnt2++;
						ans1[i]=')';
						ans2[i]='(';
					}else{
						cnt1++;
						cnt2--;
						if(cnt2<0)ok=0;
						ans1[i]='(';
						ans2[i]=')';
					}
				}
			}
			assert(ok&&!cnt1&&!cnt2);
			cout<<"Yes\n";
			cout<<3<<'\n';
			for(int i=1;i<=n;i++){
				if(i<=n/2)cout<<'(';
				else cout<<')';
			}
			cout<<'\n';
			for(int i=1;i<=n;i++)cout<<ans1[i];
			cout<<'\n';
			for(int i=1;i<=n;i++)cout<<ans2[i];
			cout<<'\n';
			return ;
		}
	}
	cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}