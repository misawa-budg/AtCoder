#include <bits/stdc++.h>
using namespace std;

vector<string> rotate90(const vector<string>& A){
    int N = A.size();
    vector<string> R(N, string(N, '-'));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            R[j][N-1-i] = A[i][j];
        }
    }
    return R;
}

int count_diffs(vector<string> &S, vector<string> &T)
{
    int diffs = 0;
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S[i].size(); j++) {
            if (S[i][j] != T[i][j]) {
                diffs++;
            }
        }
    }
    return diffs;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> T[i];

    int ans = INT_MAX;
    vector<string> cur = S;

    for(int k = 0; k < 4; k++){
        int diff = count_diffs(cur, T);
        ans = min(ans, k + diff);
        cur = rotate90(cur);
    }
    cout << ans << '\n';

    return 0;
}
