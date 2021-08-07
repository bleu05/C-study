#include<iostream>
using namespace std;

int main() {
    int food[5];
    int beverage;
    int burger;

    for (int i = 0; i < sizeof(food) / sizeof(int); i++) {
        cin>>food[i];
    }
    burger = food[0];
    beverage = (food[3] > food[4]) ? food[4] : food[3];

    if (food[0] > food[1]) {
        burger = food[1];
    }
    if (burger > food[2]) {
        burger = food[2];
    }
    cout<<burger + beverage - 50;
    return 0;
}