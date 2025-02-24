#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=40;
string a[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]>='1'&&a[i][j]<='9'){
				int len=a[i][j]-'0';
				a[i][j]='.';
				for(int l=0;l<n;l++){
					for(int r=0;r<m;r++){
						if(a[l][r]>='1'&&a[l][r]<='9')continue;
						if(abs(l-i)+abs(r-j)<=len){
							a[l][r]='.';
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<'\n';
	}
	return 0;
}
