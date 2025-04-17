#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;

    vector<char> mp(26);
    for(int i = 0; i < 26; i++) mp[i] = char('a' + i);

    for(int qi = 0; qi < Q; qi++){
        char c, d;
        cin >> c >> d;
        for(int i = 0; i < 26; i++){
            if(mp[i] == c) mp[i] = d;
        }
    }

    for(char &ch : S){
        ch = mp[ch - 'a'];
    }
    cout << S << "\n";

    return 0;
}
