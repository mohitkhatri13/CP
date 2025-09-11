// link - https://www.codechef.com/problems/MAXMST7?tab=statement

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	// your code goes here
	int ta;
	cin>>ta;
	while(ta--){
	    int n ;
	    cin>>n;
	    
	    int m = (n * ( n-1))/2;
	    vector<int>weight(m);
	    for(int i=0 ; i< m ; i++){
	        cin>>weight[i];
	    }
	    sort(weight.begin() , weight.end());
	    
	    int ans = 0;
	    
	    int skip = 0;
	    int i =0;
	    while(i<m){
	        ans+= weight[i];
	        i+= skip;
	        i++;
	        skip++;
	    }
	    
	    cout<<ans<<endl;
	}
	
	return 0;
}
