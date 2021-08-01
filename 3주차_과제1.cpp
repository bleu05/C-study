#include<iostream>
using namespace std;

void N_sum()
{
    int N, M;
    int i, j;
    int sum;
    int num;
    cin>>N;
    for (i = 0; i < N; i++)
    {
        sum = 0;
        cin >> M;
        for (j = 0; j < M; j++)
        {
            cin >> num;
            sum += num;
        }
        cout << sum << endl;;
    }
}

int main() {
    N_sum();
}