#include <bits/stdc++.h>
using namespace std;

int findDelay(const string &S, int startTime, char target, int M) {
    for(int delta=0; delta<M; delta++){
        if( S[(startTime + delta) % M] == target )
            return startTime + delta;
    }

    return LLONG_MAX;
}

int solveForWheel(const string &first,
                  const string &second,
                  const string &third,
                  int M)
{
    int best = LLONG_MAX;
    for(int i = 0; i < M; i++){
        char c = first[i];
        int t1 = i;
        int t23 = findDelay(second, t1+1, c, M);
        if(t23 != LLONG_MAX) t23 = findDelay(third, t23+1, c, M);

        int t32 = findDelay(third,  t1+1, c, M);
        if(t32 != LLONG_MAX) t32 = findDelay(second, t32+1, c, M);

        int t = min(t23, t32);
        best = min(best, t);
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;
    string S1,S2,S3;
    cin >> S1 >> S2 >> S3;

    int ans = LLONG_MAX;
    ans = min(ans, solveForWheel(S1,S2,S3,M));
    ans = min(ans, solveForWheel(S2,S3,S1,M));
    ans = min(ans, solveForWheel(S3,S1,S2,M));

    if(ans == LLONG_MAX) cout << -1 << "\n";
    else             cout << ans  << "\n";
    return 0;
}
