#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; i++) cin >> D[i];

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= D[i]; j++) {
            set<char> st;
            string month = to_string(i + 1);
            for (char c : month) st.insert(c);
            
            string day = to_string(j);
            for (char c : day) st.insert(c);
            if (st.size() == 1) count++;
        }
    }

    cout << count << endl;

    return 0;
}