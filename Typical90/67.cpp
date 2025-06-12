#include <bits/stdc++.h>
using namespace std;

long long baseToDecimal(const string& num, int base) {
    long long result = 0;
    long long power = 1;
    for (int i = num.size() - 1; i >= 0; i--) {
        result += (num[i] - '0') * power;
        power *= base;
    }
    return result;
}

string DecimalToBase(long long num, int base) {
    if (num == 0) return "0";
    string result = "";
    while (num > 0) {
        result += (num % base) + '0';
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N; int K; cin >> N >> K;

    string tmp = N;
    while (K--) {
        long long decimalVal = baseToDecimal(tmp, 8);
        tmp = DecimalToBase(decimalVal, 9);
        for (char& c : tmp) {
            if (c == '8') c = '5';
        }
    }
    cout << tmp << endl;

    return 0;
}
