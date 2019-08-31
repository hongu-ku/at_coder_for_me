#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define CON 1000000000000
#define SIX 1000000
using namespace std;

int n;
int find(long now, bool is_3, bool is_5, bool is_7){
    if(now > n){
        return 0;
    }
    int ans = is_3 && is_5 && is_7;
    ans += find(now * 10 + 3, true, is_5, is_7);
    ans += find(now * 10 + 5, is_3, true, is_7);
    ans += find(now * 10 + 7, is_3, is_5, true);
    return ans;
}

int main(){
    cin >> n;
    cout << find(0, false, false, false) << endl;
}
