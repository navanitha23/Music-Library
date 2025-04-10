#include <bits/stdc++.h>
#define R(x) { cout << x << endl; return;}
#define all(x) x.begin(),x.end()
#define f(i,n) for(int i = 0;i<n;i++)
#define fr(i,x) for(auto& i:x)

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void solve() {
    int n,m;
    cin >> n>> m;
    vvi a(n,vi(2));
    fr(i,a) cin >> i[1] >> i[0];
    sort(all(a)); // if i choose a job with minimum end time i can maximize the time to watch other movies.
    int res = 0;
    multiset<int> ET;
    for(int i = 0;i<m;i++) ET.insert(0);
    // for(int i:ET) cout << i<< " ";
    // cout << endl;
    // int res = 0;
    for(int i = 0;i<n;i++){
        // for(int i:ET) cout << i<< " ";
        // cout << endl;
        auto bestGuy = ET.upper_bound(a[i][1]);
        if(bestGuy == ET.begin()) continue;
        bestGuy--;
        // cout << *bestGuy << endl;
        ET.erase(bestGuy);
        ET.insert(a[i][0]);
        res++;
        
    }
    R(res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}