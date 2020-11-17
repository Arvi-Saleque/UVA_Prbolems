#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
typedef long long int ll;
const ll mod = 100000007;
const int sz = 10010;

int sum,n;
int arr[30];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    while(cin >> sum){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        int ans = -1;
        int pos = 0;
        for(int i=1;i<=(1<<n);i++){
        	int res = 0;
        	for(int j=0;j<n;j++){
        		if(((bool)(i & (1<<j))) == 1) {
        			res += arr[j];
        		}
        	}
        	//cout << res << endl;
        	if(res <= sum && res > ans){
        		ans = res;
        		pos = i;
        	} 
        }

        for(int j=0;j<n;j++){
	    	if(((bool)(pos & (1<<j))) == 1) {
    			cout << arr[j] << " ";
    		}
        }

        cout << "sum:" << ans << endl;
    }

}
