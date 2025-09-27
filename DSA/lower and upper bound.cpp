

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v= {1 ,2 , 3 , 4 ,5 , 5 , 6, 7 , 8};
    
     vector<int>:: iterator it1 = lower_bound(v.begin() , v.end() , 4);
     
     // we can use auto or  same ds on while we applied the functions followed by :: iterator it
    int index1 = it1-v.begin(); // aise index nikalte hai
    cout<<*it1<<endl; // direct value aise aati hai 
    cout<<v[index1]<<endl;
    
    
     auto it2 = upper_bound(v.begin() , v.end() , 5);
    int index2 = it2-v.begin();
    cout<<index2<<endl;// hamesha sbse phle jo bada hoga vo dega
    cout<< v[index2]<<endl;
    
     auto it3 = upper_bound(v.begin() , v.end() , 8);
    int index3 = it3-v.begin();
    cout<<index3<<endl;// index got out of bound 
    cout<< v[index3]<<endl;

    return 0;
}