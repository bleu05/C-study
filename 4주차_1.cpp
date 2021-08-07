#include<iostream>
using namespace std;

int main() {
    int m, n;
    int sum = 0;
    int min = 10001;
    cin >> m;
    cin >> n;
    if (m == 1)
        m++;
    for (; m <= n; m++) {
        int check = 1;
        for (int j = 2; j <= m / 2; j++) {
            if (m % j == 0) {
                check = 0;
                break;
            }
        }
        if (check == 1) {
            if (min > m)
                min = m;
            sum += m;
        }
    }
    if (sum == 0)
        cout << "-1";
    else {
        cout << sum << endl;
        cout << min << endl;
    }
    return 0;
}