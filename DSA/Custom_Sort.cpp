// how to declate cusstom sort in vector<pair<int, int>>
✅ Option 1: Local struct inside main
#include <bits/stdc++.h>
using namespace std;

int main() {
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first != b.first) {
                return a.first < b.first;  // smaller first comes first
            }
            return a.second > b.second;    // if tie, larger second comes first
        }
    };

    vector<pair<int,int>> v = {{1,2}, {3,4}, {3,2}, {4,5}, {1,5}};
    
    sort(v.begin(), v.end(), cmp());  // pass comparator object

    for (auto &p : v) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

✅ Option 2: Lambda comparator
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> v = {{1,2}, {3,4}, {3,2}, {4,5}, {1,5}};
    
    auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;  // smaller first comes first
        }
        return a.second > b.second;    // if tie, larger second comes first
    };

    sort(v.begin(), v.end(), cmp);

    for (auto &p : v) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}


⚡ Difference:

priority_queue → you must declare comparator type in the template.

sort → just pass a comparator object (function, struct instance, or lambda).


*********************** For the priority-queue*****************8
✅ Option 1: Define a struct inside main
#include <bits/stdc++.h>
using namespace std;

int main() {
    // you can placed this struct as it is to the top 
    struct cmp {
        bool operator()(const pair<int , string>& a, const pair<int , string>& b) const {
            if (a.first != b.first) {
                return a.first < b.first;  // higher rating first
            }
            return a.second > b.second;    // lexicographically smaller first
        }
    };

    priority_queue<pair<int , string>, vector<pair<int , string>>, cmp> pq;

    pq.push({2 , "hello"});
    pq.push({3 , "gello"});
    pq.push({3 , "aello"});
    pq.push({4 , "mello"});

    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}


Here cmp is local to main, but still a type, so you can use it as the third template parameter.

✅ Option 2: Use a lambda comparator

Since C++11, you can avoid defining a struct altogether:

#include <bits/stdc++.h>
using namespace std;

int main() {
    auto cmp = [](const pair<int , string>& a, const pair<int , string>& b) {
        if (a.first != b.first) {
            return a.first < b.first;  // higher rating first
        }
        return a.second > b.second;    // lexicographically smaller first
    };

    priority_queue<
        pair<int , string>,
        vector<pair<int , string>>,
        decltype(cmp)
    > pq(cmp);  // must pass cmp object to constructor

    pq.push({2 , "hello"});
    pq.push({3 , "gello"});
    pq.push({3 , "aello"});
    pq.push({4 , "mello"});

    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}


With lambda, you just need decltype(cmp) as the comparator type, and pass the lambda instance when constructing the priority queue.