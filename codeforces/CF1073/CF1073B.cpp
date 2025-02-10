#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	int start=0;
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>x;
		m[x]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>y;
		if(m[y]>start){
			cout<<m[y]-start<<' ';
			start=m[y];
		}else cout<<0<<' ';
	}
	return 0;
}
