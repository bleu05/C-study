#include<iostream>
#include<string>
using namespace std;

class VendingMachine
{
private:
	string name; // 음료 이름
	int price; // 가격
	int total = 0; // 음료 합산 값
public:
	VendingMachine() {}; 
	void purchase(double v1);//거스름돈계산
	void menu();//메뉴추가전
	void upgrademenu();//메뉴추가
	string getName();//추가될 메뉴 이름 리턴
	double getPrice();//추가될 메뉴 가격 설정
	double getTotal(double total);//총합 리턴
	void setName(string n);//추가될 메뉴 이름 설정
	void setPrice(int p);//추가될 메뉴 가격 리턴
	void setTotal(int t);
	int returngap = 200;//거스름돈 제한
};
void VendingMachine::menu() {
	cout << "==========SWING 자판기==========" << endl;
	cout << "1. 코카콜라 : 1200원" << endl;
	cout << "2. 칠성 사이다 : 1400원" << endl;
	cout << "3. 미에로 화이바 : 1800원" << endl;
	cout << "4. 준비 중" << endl;
	cout << "5. 계산" << endl;
	cout << "6. 종료" << endl;
}
void VendingMachine::upgrademenu() {
	cout << "==========SWING 자판기==========" << endl;
	cout << "1. 코카콜라 : 1200원" << endl;
	cout << "2. 칠성 사이다 : 1400원" << endl;
	cout << "3. 미에로 화이바 : 1800원" << endl;
	cout << "4."<<name <<":"<<price<<"원"<< endl;//입력받은 메뉴의 이름과 가격이 들어간 후 출력되게 한다
	cout << "5. 계산" << endl;
	cout << "6. 종료" << endl;
}
void VendingMachine::purchase(double v1) {
	int gap;//사용자에게 입력받은 가격이 들어가지는 변수
	cout << endl << "총 금액 :" << v1 << endl;
	cout << "지폐를 입력하세요 :";
	cin >> gap;
	int change = gap - v1;/*입력받은 가격에서 총합을 뺀 값을 넣어준다
						  거스름돈을 받아야하는지 돈을 더 내야하는지 결정해야하기 때문*/

	for (;;) {
		if (gap > v1) {//지폐의 금액이 총합보다 큰 경우
			if (change % 100 == 0) {//받아야하는 거스름돈이 100원단위로 떨어지는 경우
				cout << "거스름 돈입니다" << endl;
				if (change/100 <= returngap) {//기계안에 있는 100원의 갯수가 받아야하는 거스름돈보다 많아 거스름돈을 받을 수 있는 경우
					cout << "100원 :" << change / 100 << endl;
					cout << "기기에 남은 거스름돈(100원 개수) :" << returngap - (change / 100) << endl;/*거스름돈을 받은 만큼
																						   기계안에 있는 100원의 갯수를 줄인다*/
					break;
				}
				else {//기계안에 있는 100원의 갯수가 받아야하는 거스름돈보다 적어 거스름돈을 받을 수 없는 경우
					cout << "기기내의 잔돈이 부족합니다. 010-0000-0000으로 연락주세요" << endl;
					cout << "기기에 남은 거스름돈(100원의 개수) : 0" << endl;
					break;
				}
			}
			else {//받아야하는 거스름돈이 100원단위로 떨어지지 않는 경우
				cout << "거스름돈은 100원만 가능합니다" << endl;
				cout << "100원 :" << change / 100 << "개" << endl;
				cout << "기기에 남은 거스름돈(100원 개수) :" << returngap - (change / 100) << endl;
				break;
			}
		}
		else {//지폐의 금액이 총합보다 작거나 같은 경우
			if (gap == v1) {//지폐의 금액과 총합이 같은 경우
				cout << "거스름돈이 필요 없습니다. 안녕히 가세요" << endl;
				cout << "기기에 남은 거스름돈(100원 개수) :" << returngap << endl;
				break;
			}
			else {//지폐의 금액이 총합보다 작은 경우
				cout << "금액이 부족합니다. 다시 넣어주세요" << endl;
				cout << "지폐를 입력하세요 :";
				cin >> gap;
				change = gap - v1;
			}
		}
	}
}
void VendingMachine::setName(string n) {
	cout << "추가할 음료 이름을 입력해주세요 : ";
	cin >>  name;//사용자에게 추가될 음료의 이름을 입력받는다
}
string VendingMachine::getName() {
	return name;//음료 이름 리턴
}
void VendingMachine::setPrice(int p) {
	cout << "판매할 가격을 입력하세요 : ";
	cin >> price;//사용자에게 추가될 음료의 가격을 입력받는다
}
double VendingMachine::getPrice() {
	return price;//음료 가격 리턴
}
double VendingMachine::getTotal(double total) {
	return total;//총합 리천
}

int main() {
	string name;
	int price = 0;
	int number1 = 0;
	int number2 = 0;
	int number3 = 0;
	int number4 = 0;
	int select;
	int goods1 = 0;
	int goods2 = 0;
	int goods3 = 0;
	int goods4 = 0;
	double total=0;
	VendingMachine a;
	a.menu();
	a.setName(name);
	a.getName();
	a.setPrice(price);
	a.upgrademenu();
	for (;;) {
		cout << "번호를 선택해주세요 :";
		cin >> select;
		if (select == 1) {//1번을 선택한 경우
			goods1 = 1200;
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> number1;
			continue;
		}
		else if (select == 2) {//2번을 선택한 경우
			goods2 = 1400;
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> number2;
			continue;
		}
		else if (select == 3) {//3번을 선택한 경우
			goods3 = 1800;
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> number3;
			continue;
		}
		else if (select == 4) {//4번을 선택한 경우
			goods4 = price;/*4번의 금액은 정해진 것이 아닌 사용자에게 입력을 받아야 하기 때문에
						   사용자가 입력한 금액이 들어가져 있는 변수 price를 적어준다*/
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> number4;
			continue;
		}
		else if (select == 5) {
			total = goods1 * number1 + goods2 * number2 + goods3 * number3 + goods4 * number4;
			cout << "계산 중입니다. 기다려주세요..." << endl;
			cout << endl;
			a.getTotal(total);
			break;
		}
	}
	a.purchase(total);
}
