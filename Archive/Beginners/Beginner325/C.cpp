#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    atcoder::dsu uf(H * W);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') continue;

            int id = i * W + j;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue;
                    int ni = i + k, nj = j + l;
                    if(ni<0 || ni>=H || nj<0 || nj>=W) continue;
                    if(S[ni][nj] == '#'){
                        uf.merge(id, ni*W + nj);
                    }
                }
            }
        }
    }

    unordered_set<int> roots;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#'){
                int id = i * W + j;
                roots.insert( uf.leader(id) );
            }
        }
    }

    cout << roots.size() << endl;

    return 0;
}
