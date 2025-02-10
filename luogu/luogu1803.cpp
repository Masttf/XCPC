#include<bits/stdc++.h>
using namespace std;
struct complete{
	int start;
	int end;
}s[1000005];
bool cmp(complete x,complete y){
	return x.start<y.start;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].start>>s[i].end;
	}
	sort(s+1,s+1+n,cmp);
	int endline=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		//做出当前最好选择
		if(endline<=s[i].start){
			endline=s[i].end;
			ans++;
		}else{//修改选择
			if(s[i].end<endline){
				endline=s[i].end;
			}
		}
	}
	cout<<ans;
	return 0;
}
