#include<bits/stdc++.h>
using namespace std;
int res[100005],start=1;
int e=1;
int main(){
	int n,m;cin>>m>>n;
	int cnt=0;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		int flag=1;
		for(int i=start;i<e;i++){
			if(res[i]==x){
				flag=0;
			}
		}
		if(flag){
			if(e-start==m){
				start++;
			}
			res[e++]=x;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
