#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
int st[maxn][25];
void solve(){
	unordered_map<int,int>x;
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i],st[i][0]=b[i];
	for(int k=1;k<=log2(n);k++){//预处理最小值
		for(int s=1;s+(1LL<<k)<=n+1;s++){
			st[s][k]=max(st[s][k-1],st[s+(1LL<<(k-1))][k-1]);
		}
	}
	int m;cin>>m;
	for(int i=1;i<=m;i++){
		int sz;cin>>sz;
		x[sz]++;
	}
	int flag=1;
	vector<pair<int,int>>bb(1,{0,0});
	for(int i=1;i<=n;i++){
		if(a[i]==b[i])continue;
		else if(a[i]<b[i]){
			flag=0;
		}else{
			bb.push_back({b[i],i});
		}
	}
	if(flag){
		int kk=bb.size();
		sort(bb.begin()+1,bb.end());
		int f=1;
		unordered_map<int,int>res;
		for(int i=1;i<=kk-1;i++){
			while(i<=kk-2&&bb[i].first==bb[i+1].first){
				int l=bb[i].second,r=bb[i+1].second;
				int len=r-l+1;
				len=log2(len);
				int mx=max(st[l][len],st[r-(1LL<<len)+1][len]);
				if(mx>bb[i].first)res[bb[i].first]++;
				i++;
			}
			res[bb[i].first]++;
			if(res[bb[i].first]>x[bb[i].first]){
				f=0;
				break;
			}
		}
		if(f)cout<<"yes\n";
		else cout<<"no\n";
	}else cout<<"no\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
