#include <iostream>
#include <cstdlib>//atoi,rand,malloc ���� �޼ҵ尡 ���Ե� ���̺귯��
#include <ctime>//�ð��� ���õ� �޼ҵ�, ����� ���Ե� ���̺귯��
using namespace std;
class Random {
public:
    Random();
    int next();
    int nextInRange(int x, int y);
};
Random::Random() {
    srand((unsigned)time(0));/*rand()�Լ��� ����ϸ� ������ ���� ������� ������ ������ ������ ���� ������ ���� ���´�.
    �ֳ��ϸ� ���� seed���� �̿��ϱ� �����̴�. ���� srand�� �̿��� ���α׷��� ������ ������ �ٸ� seed���� �־��ָ�
    �Ź� �ٸ� ������ ���� ���ð��̴�.
    unsigned=0~32767������ ����*/
}
int Random::next() {
    return ((rand() / 2) * 2);//2�� ����� 2�� ���ϸ� ¦���� ������ ��µȴ�
}
int Random::nextInRange(int x, int y) {
    return ((((rand() % (y - x + 1)) + x) / 2) * 2) + 1;;//Ȧ�� ���� ����
}
int main() {
    Random r;
    int save[10];
    int c;
    cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10 ��--" << endl;//RAND_MAX=32767 ���
    for (int i = 0; i < 10; ++i) {
        int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ������  10���� �ݺ��� ���ؼ� ��µ�
        cout << n << ' ';//�����ϰ� ���� ¦�� �������� ���
    }
    cout << endl << endl << "== 2���� " << "30 ������ Ȧ�� ���� ���� 10 ��(��, �ߺ��� �Ǵ� ���� ����� ��) ==" << endl;
    for (int i = 0; i < 10; i++) {
        save[i]= r.nextInRange(2, 30);
        for (c = 0; c < i; c++) {
            if (save[i] == save[c]) {//���� ��µ� ������ �ߺ��ȴٸ�
                i--;//i�� ���ڰ� �ϳ� �پ� �ߺ��� ���ڰ� ��µ��� �ʰ� �����
                break;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << save[i]<<" ";//�迭�� ����Ͽ� �ߺ��Ǵ� ���� ������� �ʴ� Ȧ������ ����Ѵ�
    }
    cout << endl;
}