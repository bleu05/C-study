#include <iostream>
using namespace std;

class Oval {
	int A, B;
public:
	Oval();//기본 생성자
	Oval(int w, int h);//매개변수 있는 생성자
	~Oval();//소멸자
	double Area();//타원의 넓이 구하는 함수,넓이를 구할때 3.14를 곱해주기 때문에 int가 아닌 double형식을 사용한다
	int getA();//A값 리턴
	int getB();//B값 리턴
	void set(int w, int h);//높이, 너비 설정해주는 함수
};
Oval::Oval() {
	A = 1; B = 1;//높이, 너비 값 초기화
}
Oval::Oval(int w, int h) {
	A = w; B = h;
}
Oval::~Oval() {
	cout << "Oval 소멸 : width = " << A << ", height = " << B << endl;
}
double Oval::Area() {
	return (A/2) * (B/2) * 3.14;//넓이를 구할때는 A의 값 반과 B의 값 반이 필요하기 때문에 /2를 해준다
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
	a.set(10, 20);//a의 높이와 너비값을 set함수를 이용하여 받는다
	double aarea = a.Area();//a의 넓이
	double barea = b.Area();//b의 넓이
	cout << "타원의 넓이는" << aarea << "이다" << endl;
	cout << "타원의 넓이는" << barea << "이다" << endl;
}