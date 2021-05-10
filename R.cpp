#include <iostream>
#include <cstdlib>//atoi,rand,malloc 등의 메소드가 포함된 라이브러리
#include <ctime>//시간과 관련된 메소드, 상수가 포함된 라이브러리
using namespace std;
class Random {
public:
    Random();
    int next();
    int nextInRange(int x, int y);
};
Random::Random() {
    srand((unsigned)time(0));/*rand()함수만 사용하면 무작위 수가 나오기는 하지만 실행할 때마다 같은 무작위 수가 나온다.
    왜냐하면 같은 seed값을 이용하기 때문이다. 따라서 srand를 이용해 프로그램을 시작할 때마다 다른 seed값을 넣어주면
    매번 다른 무작위 수가 나올것이다.
    unsigned=0~32767까지의 범위*/
}
int Random::next() {
    return ((rand() / 2) * 2);//2로 나누어서 2를 곱하면 짝수의 범위만 출력된다
}
int Random::nextInRange(int x, int y) {
    return ((((rand() % (y - x + 1)) + x) / 2) * 2) + 1;;//홀수 범위 지정
}
int main() {
    Random r;
    int save[10];
    int c;
    cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl;//RAND_MAX=32767 상수
    for (int i = 0; i < 10; ++i) {
        int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수가  10번의 반복을 통해서 출력됨
        cout << n << ' ';//랜덤하게 받은 짝수 정수들을 출력
    }
    cout << endl << endl << "== 2에서 " << "30 까지의 홀수 랜덤 정수 10 개(단, 중복이 되는 값이 없어야 함) ==" << endl;
    for (int i = 0; i < 10; i++) {
        save[i]= r.nextInRange(2, 30);
        for (c = 0; c < i; c++) {
            if (save[i] == save[c]) {//만약 출력된 정수가 중복된다면
                i--;//i의 숫자가 하나 줄어 중복된 숫자가 출력되지 않게 만든다
                break;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << save[i]<<" ";//배열을 사용하여 중복되는 값이 들어있지 않는 홀수들을 출력한다
    }
    cout << endl;
}