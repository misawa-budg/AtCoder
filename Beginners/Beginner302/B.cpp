#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin>>S[i];

    vector<pair<int,int>> dirs = {
        {0,1},{1,0},{0,-1},{-1,0},
        {1,1},{1,-1},{-1,1},{-1,-1}
    };
    string target = "snuke";

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]!='s') continue;
            for(auto [dx,dy]: dirs){
                int x=i, y=j, k;
                for(k=0;k<5;k++){
                    int nx = i + dx*k;
                    int ny = j + dy*k;
                    if(nx<0||nx>=H||ny<0||ny>=W) break;
                    if(S[nx][ny]!=target[k]) break;
                }
                if(k==5){
                    for(int t=0;t<5;t++){
                        cout<< (i+dx*t)+1<<" "<<(j+dy*t)+1<<"\n";
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}
