#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
char a[maxn][maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int h,w;cin>>h>>w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			string x;cin>>x;
			if(x=="0")a[i][j]='.';
			else{
				int sz=x.size();
				int t=0;
				for(int i=0;i<sz;i++){
					t=t*10+x[i]-'0';
				}
				a[i][j]='A'+t-1;
			}
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)cout<<a[i][j];
		cout<<'\n';
	}
	return 0;
}
