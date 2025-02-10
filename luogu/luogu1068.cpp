#include<bits/stdc++.h>
using namespace std;
struct people{
	int id;
	int grade;
}res[5005];
bool cmp(people x,people y){
	if(x.grade!=y.grade)return x.grade>y.grade;
	else if(x.id!=y.id)return x.id<y.id;
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>res[i].id>>res[i].grade;
	}
	sort(res+1,res+1+n,cmp);
	int cnt=res[m*3/2].grade;
	int ans=m*3/2;
	while(res[ans+1].grade==cnt)ans++;
	cout<<cnt<<' '<<ans<<'\n';
	for(int i=1;i<=ans;i++){
		cout<<res[i].id<<' '<<res[i].grade<<'\n';
	}
	return 0;
}
