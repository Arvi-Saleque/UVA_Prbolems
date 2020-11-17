#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
typedef long long int ll;
const ll mod = 100000007;
const int sz = 10010;

int sum,n;
int dp[sz][30];
int arr[30];

int fun(int pos,int val){
    if(val<=0 || pos==n) return 0;
    if(dp[val][pos] != -1) return dp[val][pos];

    int a = 0, b = 0;
    if(val-arr[pos] >= 0) a = arr[pos] + fun(pos+1,val-arr[pos]);
    b = fun(pos+1,val);

    if(a>b){
        dp[val][pos] = a;
    }
    else dp[val][pos] = b;

    return dp[val][pos];
}

void dfs(int pos,int val){
    if(val<=0 || pos==n) return ;
    if(val-arr[pos] >= 0) if(arr[pos]+fun(pos+1,val-arr[pos])==dp[val][pos]){
        cout<<arr[pos]<<" ";
        dfs(pos+1,val-arr[pos]);
        return ;
    }
    dfs(pos+1,val);
    return ;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    while(cin >> sum){
        memset(dp,-1,sizeof dp);
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        int ans = fun(0,sum);
        dfs(0,sum);
        cout <<"sum:"<< ans << endl;
    }

}
