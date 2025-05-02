#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<tuple<int,ll,ll>>> adj(N+1);
    for(int i = 0; i < M; i++){
        int A, B; ll X, Y;
        cin >> A >> B >> X >> Y;
        adj[A].emplace_back(B, X,  Y);
        adj[B].emplace_back(A, -X, -Y);
    }

    vector<bool> seen(N+1, false);
    vector<ll> X(N+1), Y(N+1);

    queue<int> q;
    seen[1] = true;
    X[1] = 0;  Y[1] = 0;
    q.push(1);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &[v, dx, dy] : adj[u]){
            if(!seen[v]){
                seen[v] = true;
                X[v] = X[u] + dx;
                Y[v] = Y[u] + dy;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        if(seen[i]){
            cout << X[i] << " " << Y[i] << "\n";
        } else {
            cout << "undecidable\n";
        }
    }
    return 0;
}
