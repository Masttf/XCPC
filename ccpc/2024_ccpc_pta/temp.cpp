#include<bits/stdc++.h>
using namespace std;
const int MAX = 3e7+10;
#define int long long
const int mod=1e9+7;
string s;
int lc[MAX];
char ch[MAX];
int sz;
struct Manacher
{
 Manacher(string s){init(s);manacher();}
 /* s 1 bas */
 void init(string s)
 {
     int n = s.size()-1;
     ch[n*2 +1] = '#';
     ch[0] = '@';
     ch[n*2 +2] = '\0';
     for (int i=n;i>=1;i--)
     {
        ch[i*2] = s[i];ch[i*2 -1] = '#';
     }
     sz = 2* n +1;
 }
 void manacher()
 {
     lc[1]=1; int k=1;
     for (int i=2;i<=sz;i++)
     {
         int p = k+lc[k]-1;
         if (i<=p)
         {
             lc[i]=min(lc[2*k-i],p-i+1);
         }
         else
        { 
            lc[i]=1; 
        }
        while (ch[i+lc[i]]==ch[i-lc[i]])lc[i]++;
        if (i+lc[i]>k+lc[k])k=i;
     }
 }
 void debug()
 {
     puts(ch);
     for (int i=1;i<=sz;i++)
   {
      cout<<"lc["<<i<<"]"<<"="<<lc[i]<<endl;
      //printf("lc[%d]=%d\n",i,lc[i]);
   }
 }
 bool check(int l,int r)
 {
   int ll=2*l;
   int rr=2*r;
   int mid=ll+rr>>1;
   //cout<<mid<<endl;
   int len=r-l+1;
   //cout<<lc[mid]-1<<endl;
   if(lc[mid]-1>=len) return true;
   return false;
 }
};
signed main()
{
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    if(n<m)
    {
        cout<<0<<endl;
        return 0;
    }
    s1=' '+s1;
    s2=' '+s2;
    vector<int> dp(n+1,0);
    int idx=1;
    bool flag1=false,flag2=false;
    vector<int> suf(n+1,0);
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(idx<=m&&s1[i]==s2[idx])
        {
            if(idx==m) flag1=true;
            pre[idx]=i;
            idx++;
        }

    }
    idx=1;
    for(int i=n;i>=1;i--)
    {
        if(idx<=m&&s1[i]==s2[idx])
        {
            if(idx==m) flag2=true;
            suf[idx]=i;
            idx++;
        }
    }
    if(!flag1||!flag2)
    {
        cout<<0<<endl;
        return 0;
    }
    int l=pre[m]+1;
    int r=suf[m]-1;
    int ans=0;
    // if(l==r+1)
    // {
    //     ans=1;
    // }
     if(pre[m] < suf[m])
    {
        //dcout<<"a"<<endl;
       // set<char> se;
        vector<int> last(30,0);
        for(int i=l;i<=r;i++)
        {
            int t=s1[i]-'a';
            if(last[t]==0)
            {
                dp[i]=(dp[i-1]*2+1)%mod;
                last[t]=i;
            }
            else
            {
                dp[i]=(dp[i-1]*2%mod-dp[last[t]-1]+mod)%mod;
                last[t]=i;
            }
            ans=dp[i];
        }
        ans+=1;
        ans%=mod;
    }
   // cout<<ans<<endl;
    s=s2;
    Manacher Manacher(s);
   // if(Manacher.check(m,m)) cout<<"aa"<<endl;
    for(int i=m;i>=1;i--)
    {
        if(Manacher.check(i,m))
        {
     //       cout<<i<<"aa"<<endl;
            int pos=i-1;
            if(pos==0) 
            {
                ans++;
                ans%=mod;
            }
            else if(suf[pos]>pre[m]) 
            {
                ans+=1;
                ans%=mod;
            }

        }
    }
    cout<<ans<<endl;



}