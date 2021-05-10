#include <iostream>
using namespace std;

class Oval {
	int A, B;
public:
	Oval();//�⺻ ������
	Oval(int w, int h);//�Ű����� �ִ� ������
	~Oval();//�Ҹ���
	double Area();//Ÿ���� ���� ���ϴ� �Լ�,���̸� ���Ҷ� 3.14�� �����ֱ� ������ int�� �ƴ� double������ ����Ѵ�
	int getA();//A�� ����
	int getB();//B�� ����
	void set(int w, int h);//����, �ʺ� �������ִ� �Լ�
};
Oval::Oval() {
	A = 1; B = 1;//����, �ʺ� �� �ʱ�ȭ
}
Oval::Oval(int w, int h) {
	A = w; B = h;
}
Oval::~Oval() {
	cout << "Oval �Ҹ� : width = " << A << ", height = " << B << endl;
}
double Oval::Area() {
	return (A/2) * (B/2) * 3.14;//���̸� ���Ҷ��� A�� �� �ݰ� B�� �� ���� �ʿ��ϱ� ������ /2�� ���ش�
}
int Oval::getA() {
	return A;
}
int Oval::getB() {
	return B;
}
void Oval::set(int w, int h) {
	A = w; B = h;
}

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);//a�� ���̿� �ʺ��� set�Լ��� �̿��Ͽ� �޴´�
	double aarea = a.Area();//a�� ����
	double barea = b.Area();//b�� ����
	cout << "Ÿ���� ���̴�" << aarea << "�̴�" << endl;
	cout << "Ÿ���� ���̴�" << barea << "�̴�" << endl;
}