//每次都把最小的两堆合并
#include<bits/stdc++.h>
using namespace std;
int a;
int ans=0;
int main(){
	priority_queue<int ,vector<int>,greater<int> >q;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		q.push(a);
	}
	for(int i=1;i<n;i++){
		a=q.top();
		q.pop();
		a+=q.top();
		q.pop();
		ans+=a;
		q.push(a);
	}
	cout<<ans;
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//int res[100005];
//int p=1,ans=0;
//int main(){
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>res[i];
//	}
//	sort(res+1,res+1+n);
//	for(int i=1;i<=n-1;i++){
//		res[p+1]+=res[p];
//		ans+=res[p+1];
//		p++;
//		sort(res+p,res+n+1);
//	}
//	cout<<ans;
//	return 0;
//}
