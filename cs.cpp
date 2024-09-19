#include <bits/stdc++.h>
using namespace std;
int n;
int dfs(vector<int>a, int l = 0, int r = n-1){
    if(l ==r && 1 !=n / 2) return 0;
    int t = a[rand() % (r - 1 + 1)];
    vector<int>low,up;
    for(int i = 0; i < r - 1 + 1; i++){
        if(a[i] < t){
            low.push_back(a[i]); 
        }else if(a[i] > t){
           up.push_back(a[i]); 
        }
    }
    if(l + (int)low.size() - 1 >= n / 2)
        return dfs(low, l, l + low.size() - 1);
    else if(r - up.size() + 1 <= n / 2)
        return dfs(up, l + low.size() + 1, r);
    return  t;
}
int main(){
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << dfs(a);
    return 0;
}
