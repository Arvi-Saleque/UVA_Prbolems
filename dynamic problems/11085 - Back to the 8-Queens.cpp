#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
typedef long long int ll;
const ll mod = 100000007;
const int sz = 1000;

bool row[10],col[10];
bool dp[10][10];
bool save[100][10][10];
int limit = 8;
bool check(int r,int c){
	if(row[r]==1 || col[c]==1) return false;
	for(int i=r,j=c;i<limit&&j<limit;i++,j++){
		if(dp[i][j]==1) return false;
	}
	for(int i=r,j=c;i>=0&&j>=0;i--,j--){
		if(dp[i][j]==1) return false;
	}
	for(int i=r,j=c;i>=0&&j<limit;i--,j++){
		if(dp[i][j]==1) return false;
	}
	for(int i=r,j=c;i<limit&&j>=0;i++,j--){
		if(dp[i][j]==1) return false;
	}
	return true;
}
int run = 0;
void fun(int c){
	if(c==limit){	
		for(int i=0;i<limit;i++){
			for(int j=0;j<limit;j++){
				save[run][i][j] = dp[i][j];
			}
		}
		run++;
	}
	
	for(int r=0;r<limit;r++){
		if(check(r,c)){
			row[r] = 1;
			col[c] = 1;
			dp[r][c] = 1;
			fun(c+1);
			dp[r][c] = 0;
			row[r] = 0;
			col[c] = 0;
		}
	}
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   
    memset(row,0,sizeof row);
    memset(col,0,sizeof col);
    memset(dp,0,sizeof dp);
    memset(save,0,sizeof save);
    
    fun(0);

    int arr[9];
    int kase = 1;
    while(cin >> arr[1]){
    	cout << "Case " << kase++ << ": ";
    	for(int i=2;i<=8;i++){
    		cin >> arr[i];
    	}
    	int ans = INT_MAX;
    	for(int cnt=0;cnt<run;cnt++){
    		int res = 0;
    		for(int i=1;i<=8;i++){
    			int val = arr[i];
    			for(int j=0;j<8;j++){
    				if(save[cnt][j][i-1]==1){
    					if(j+1!=val) res++;
    					break;
    				}
    			}
    			
    		}
    		ans = min(ans,res);
    	}
    	cout << ans << endl;
    }
}
