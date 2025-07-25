#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> sums;
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        sums.push_back((A + B) % N);
    }

    sort(sums.begin(), sums.end());

    ll parallel = 0;
    ll cnt = 1;
    for(int i = 1; i < M; i++){
        if(sums[i] == sums[i-1]){
            cnt++;
        } else {
            parallel += cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    parallel += cnt * (cnt - 1) / 2;

    ll total = (ll)M * (M - 1) / 2;
    ll answer = total - parallel;

    cout << answer << endl;
    return 0;
}
