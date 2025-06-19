#include <bits/stdc++.h>
using namespace std;

long long cross_product_direction(int Ax, int Ay, int Bx, int By, int Cx, int Cy)
{
    long long vecAx = Bx - Ax;
    long long vecAy = By - Ay;
    long long vecBx = Cx - Ax;
    long long vecBy = Cy - Ay;
    return vecAx * vecBy - vecAy * vecBx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    long long dir1 = cross_product_direction(Ax, Ay, Bx, By, Cx, Cy);
    long long dir2 = cross_product_direction(Bx, By, Cx, Cy, Dx, Dy);
    long long dir3 = cross_product_direction(Cx, Cy, Dx, Dy, Ax, Ay);
    long long dir4 = cross_product_direction(Dx, Dy, Ax, Ay, Bx, By);

    if (dir1 >= 0 && dir2 >= 0 && dir3 >= 0 && dir4 >= 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
