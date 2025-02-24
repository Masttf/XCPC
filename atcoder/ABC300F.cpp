#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){//首先肯定是把连续x的位置变成o 所以枚举第一个字符串中第一个x变o的位置然后算个数就行了
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	string s;cin>>s;
	vector<int>p;
	for(int i=0;i<n;i++){
		if(s[i]=='x')p.push_back(i);
	}
	int cnt=p.size();
	if(cnt*m==k)cout<<n*m;
	else{
		int res=max(k/cnt*n+p[k%cnt],k/cnt*n+(n-1-p[cnt-k%cnt-1]));
		for(int i=0;i<cnt;i++){
			if(i+k+1<m*cnt){//两边都是不包含
				res=max(res,p[(k+i+1)%cnt]+n*((k+i+1)/cnt)-p[i]-1);
			}
		}
		cout<<res;
	}
	return 0;
}
