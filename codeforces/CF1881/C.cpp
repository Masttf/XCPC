#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<string>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	for(int k=1;k<=n/2;k++){
		vector<string>s(5,"");
		for(int i=k-1;i<=n-k;i++){
			s[1]+=a[k-1][i];
			s[2]+=a[i][n-k];
			s[3]+=a[n-k][n-1-i];
			s[4]+=a[n-1-i][k-1];
		}
		//for(int i=1;i<=4;i++)cout<<s[i]<<'\n';
		int len=n-(k-1)*2;
		int temp=0;
		for(int i=0;i<len;i++){
			char mx='a';
			for(int j=1;j<=4;j++){
				mx=max(mx,s[j][i]);
			}
			//cout<<mx<<'\n';
			int res=0;
			for(int j=1;j<=4;j++){
				res+=(int)(mx-s[j][i]);
				if(i==0||i==len-1)temp+=(int)(mx-s[j][i]);
			}
			if(i==0||i==len-1)continue;
			ans+=res;
		}
		ans+=temp/2;
		//cout<<k<<' '<<ans<<'\n';
	}
	//ans/=2;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}