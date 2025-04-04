#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int root;
    for (int i = 0; i < N; i++) {
        if (i * i >= N) {
            root = i;
            break;
        }
    }

    vector<int> pointsMax(root);
    vector<int> pointsMin(root);
    vector<int> points(N);

    for (int i = 0; i < N; i++) {
        int point;
        cin >> point;
        points[i] = point;

        i % root == 0 ? pointsMax[i / root] = point : pointsMax[i / root] = max(pointsMax[i / root], point);
        i % root == 0 ? pointsMin[i / root] = point : pointsMin[i / root] = min(pointsMin[i / root], point);
    }

    for (int i = 0; i < K; i++) {
        int Al, Ar, Bl, Br;
        cin >> Al >> Ar >> Bl >> Br;
        Al--; Ar--; Bl--; Br--;

        float selectLimit = N / 2.0;
        int AselectCount = Ar - Al + 1;
        int BselectCount = Br - Bl + 1;
        if (AselectCount > selectLimit && BselectCount > selectLimit) {
            cout << "DRAW" << endl;
        } else if (AselectCount > selectLimit) {
            cout << "B" << endl;
        } else if (BselectCount > selectLimit) {
            cout << "A" << endl;
        } else {
            int Amax = points[Al], Amin = points[Al];
            int Aindex = Al;
            while (Aindex <= Ar) {
                if (Aindex % root == 0 && Aindex + root - 1 <= Ar) {
                    Amax = max(Amax, pointsMax[Aindex / root]);
                    Amin = min(Amin, pointsMin[Aindex / root]);
                    Aindex += root;
                } else {
                    Amax = max(Amax, points[Aindex]);
                    Amin = min(Amin, points[Aindex]);
                    Aindex++;
                }
            }

            int Bmax = points[Bl], Bmin = points[Bl];
            int Bindex = Bl;
            while (Bindex <= Br) {
                if (Bindex % root == 0 && Bindex + root - 1 <= Br) {
                    Bmax = max(Bmax, pointsMax[Bindex / root]);
                    Bmin = min(Bmin, pointsMin[Bindex / root]);
                    Bindex += root;
                } else {
                    Bmax = max(Bmax, points[Bindex]);
                    Bmin = min(Bmin, points[Bindex]);
                    Bindex++;
                }
            }

            int Ascore = Amax - Amin;
            int Bscore = Bmax - Bmin;
            if (Ascore > Bscore) {
                cout << "A" << endl;
            } else if (Ascore < Bscore) {
                cout << "B" << endl;
            } else {
                cout << "DRAW" << endl;
            }
        }
    }


    return 0;
}
