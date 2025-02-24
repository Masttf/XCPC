#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
string a[maxn];
int ans[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='#'){
				pair<int,int>lu,ld,ru,rd;
				int len=0;
				lu.first=i-1;
				lu.second=j-1;
				ld.first=i+1;
				ld.second=j-1;
				ru.first=i-1;
				ru.second=j+1;
				rd.first=i+1;
				rd.second=j+1;
				//cout<<lu.first<<' '<<lu.second<<'\n'<<ld.first<<' '<<ld.second<<'\n'<<ru.first<<' '<<ru.second<<'\n'<<rd.first<<' '<<rd.second<<'\n';
				while(lu.first>=0&&lu.second>=0&&ld.first<n&&ld.second>=0&&ru.first>=0&&ru.second<m&&rd.first<n&&rd.second<m&&a[lu.first][lu.second]=='#'&&a[ld.first][ld.second]=='#'&&a[ru.first][ru.second]=='#'&&a[rd.first][rd.second]=='#'){
					lu.first--;
					lu.second--;
					ld.first++;
					ld.second--;
					ru.first--;
					ru.second++;
					rd.first++;
					rd.second++;
					//cout<<lu.first<<' '<<lu.second<<'\n'<<ld.first<<' '<<ld.second<<'\n'<<ru.first<<' '<<ru.second<<'\n'<<rd.first<<' '<<rd.second<<'\n';
					len++;
				}
//				if((lu.first>=0&&lu.second>=0&&a[lu.first][lu.second]=='.')||(ld.first<n&&ld.second>=0&&a[ld.first][ld.second]=='.')||(ru.first>=0&&ru.second<m&&a[ru.first][ru.second]=='.')||(rd.first<n&&rd.second<m&&a[rd.first][rd.second]=='.')){
//					ans[len]++;
//				}
				ans[len]++;
				//cout<<'\n';
			}
		}
	}
	for(int i=1;i<=min(n,m);i++)cout<<ans[i]<<' ';
	return 0;
}
