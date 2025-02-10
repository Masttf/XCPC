#include<bits/stdc++.h>
using namespace std;
int daff[100005];
int res[100005];
int main(){
	int l,m;
	cin>>l>>m;
	int x,y;
	daff[1]++;
	daff[l+2]--;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		daff[x+1]--;
		daff[y+2]++;
	}
	int sum=0;
	for(int i=1;i<=l+1;i++){
		res[i]=daff[i]+res[i-1];
		if(res[i]==1)sum++;
	}
	cout<<sum;
	return 0;
}
