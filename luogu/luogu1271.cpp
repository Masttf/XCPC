#include<bits/stdc++.h>
using namespace std;
int res[2000000];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>res[i];
	}
	sort(res+1,res+1+m);
	for(int i=1;i<=m;i++){
		cout<<res[i]<<' ';
	}
	return 0;
}
