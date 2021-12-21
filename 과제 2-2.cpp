//과제 2-2, 2021111332, 정보보호학과, 방세경,2021년 12월 1일
#include <iostream>
#include <stdlib.h>//exit함수를 이용하여 프로그램을 종료하기 위해 선언한다.
#include <vector>
#include <string>
using namespace std;


class employ {//값을 저장할 클래스
	int pay;
	string name;
	string address;
public:
	employ(string name, string address, int pay) {//초기화가 가능하게 만들기 위해서 매개변수가 있는 생성자 선언
		this->name = name;//사용자가 입력한 값이 들어있는 name변수를 저장할 name변수의 값으로 저장
		this->address = address;//사용자가 입력한 값이 들어있는 address변수를 저장할 address변수의 값으로 저장
		this->pay = pay;//사용자가 입력한 값이 들어있는 pay변수를 저장할 pay변수의 값으로 저장
	};
	string getName() { return name; }//입력받은 값을 가져올 수 있는 get함수 선언
	string getaddress() { return address; }//입력받은 값을 가져올 수 있는 get함수 선언
	int getpay() { return pay; }//입력받은 값을 가져올 수 있는 get함수 선언
	void setname(string name) {//입력받은 값을 name으로 지정해주기 위한 set함수 선언
		this->name = name;
	}
	void setaddress(string address) {//입력받은 값을 address으로 지정해주기 위한 set함수 선언
		this->address = address;
	}
	void setpay(int pay) {//입력받은 값을 pay으로 지정해주기 위한 set함수 선언
		this->pay = pay;
	}
};

class employee {//기능이 구현될 함수들이 저장될 클래스
	vector<employ*> em;/*입력된 정보들은 모두 employ클래스에서 다루고 있다. 
					   이 정보들을 묶음으로 사용하기 위해 vector를 employ를 타입으로 지정해 다룬다*/
public:
	void add();//값을 추가받을 함수
	void search();//입력한 값을 찾을 함수
	void show();//입력한 값들을 출력할 함수
	void remove();//입력한 값을 삭제할 함수
	void change();//입력한 값을 수정할 함수
	void exit1();//종료할 함수
};


void employee::add() {//추가할 직원의 이름, 주소, 급여를 입력받는 함수다.
	string name, address;
	int pay;
	cout << endl;
	cout << "이름 : ";
	cin >> name;
	cout << "주소 : ";
	cin.ignore();
	getline(cin, address);
	cout << "급여 : ";
	cin >> pay;
	cout << endl;

	em.push_back(new employ(name, address, pay));/*vector에 입력한 값들을 추가하기 push_back()함수를 사용하며 
												 새로운 객체를 만들어 입력받은 name,address,pay를 추가한다.*/
}

void employee::search() {//찾을 직원의 이름을 입력하면 해당 직원의 정보가 출력되는 함수다.
	string name;

	cout << "검색하고자 하는 직원의 이름을 입력해주세요 : ";
	cin >> name;
	cout << endl;

	vector<employ*>::iterator it = em.begin();//it의 값이 원소의 처음에 있도록 초기화한다.
	while (it != em.end()) {//원소의 끝에 도달할때까지 반복한다.
		employ* p = *it;
		if (p->getName() == name) {//p가 가르키는 즉 it가 가리키는 원소의 값과 입력한 값이 같은 경우
			cout << "이름 : " << p->getName() << endl;//해당 원소가 가리키는 name 출력
			cout << "주소 : " << p->getaddress() << endl;//해당 원소가 가리키는 address 출력
			cout << "급여 : " << p->getpay() << endl;//해당 원소가 가리키는 pay 출력
			cout << endl;
			break;//입력한 직원의 정보를 다 출력했으므로 반복문을 빠져나온다.
		}
		else {//p가 가르키는 즉 it가 가리키는 원소의 값과 입력한 값이 같지 않은 경우
			it++;//다음 인덱스로 넘어가 같은 값이 있는지 확인한다.
		}

	}
}

void employee::show() {//입력받아져 있는 전체 직원의 정보를 출력하는 함수다.
	vector<employ*>::iterator it;//vector를 처음부터 끝까지 접근하기 위해 iterator를 사용한다.
	for (it = em.begin(); it != em.end(); it++) {/*for문을 사용해 iterator의 처음부터 끝까지 수행하도록 만든다. 
												 즉, 처음부터 끝까지 반복이 가능해진다*/
		employ* p = *it;//임의로 만들었던 타입에 접근하기 위해 해당 내용을 선언한다.
		cout << endl;
		cout << "이름 : " << p->getName() << endl;//employ클래스에서 선언하였던 get함수를 통해 저장되어 있는 값을 가져온다.
		cout << "주소 : " << p->getaddress() << endl;//employ클래스에서 선언하였던 get함수를 통해 저장되어 있는 값을 가져온다.
		cout << "급여 : " << p->getpay() << endl;//employ클래스에서 선언하였던 get함수를 통해 저장되어 있는 값을 가져온다.
		cout << endl;
	}
	cout << endl;
}

void employee::remove() {//입력받은 직원의 이름에 관한 정보를 삭제하는 함수
	show();//삭제를 진행하기 전 직원들의 정보를 확인하기 위해 show함수 출력

	string name;

	cout << "삭제하고자 하는 직원의 이름을 입력해주세요 : ";
	cin >> name;
	cout <<name<< "직원 삭제가 완료되었습니다." << endl;

	vector<employ*>::iterator it = em.begin();//it의 값이 원소의 처음에 있도록 초기화한다.
	while (it != em.end()) {//원소의 끝에 도달할때까지 반복한다.
		employ* p = *it;
		if (p->getName() == name) {//p가 가르키는 즉 it가 가리키는 원소의 값과 입력한 값이 같은 경우
			it = em.erase(it);//erase함수를 사용하여 해당 원소의 값을 삭제한다.
			delete p;//포인터 p도 삭제한다.
			break;//같은 이름을 찾아 삭제하였으니 반복문을 빠져나온다.
		}
		else {//p가 가르키는 즉 it가 가리키는 원소의 값과 입력한 값이 같지 않은 경우
			it++;//다음 원소를 가리키도록 한다
		}

	}

}

void employee::change() {//입력받은 이름의 직원의 정보를 수정한다.
	while (true) {
		int fix;
		string name;
		string address;
		int want;
		int pay;
		vector<employ*>::iterator it = em.begin();//it의 값이 원소의 처음에 있도록 초기화한다.
		cout << "주소 혹은 급여를 수정하시겠습니까?(수정을 원하시면 1을 눌러주세요) : ";
		cin >> fix;
		if (fix == 1) {//수정을 원한다는 1을 입력받은 경우
			cout << "어떤 직원의 수정을 원하시나요? : ";
			cin >> name;
			cout << "주소의 수정을 원하시면 1, 급여의 수정을 원하시면 2를 눌러주세요 : ";
			cin >> want;
			if (want == 1) {//주소의 수정을 원한다는 1을 입력받은 경우
				for (it = em.begin(); it != em.end(); it++) {//원소의 처음부터 끝까지 반복되도록 만든다.
					employ* p = *it;
					if (p->getName() == name) {//p가 가르키는 즉 it가 가리키는 원소의 값과 입력한 값이 같은 경우
						cout << "수정할 주소를 입력해주세요 : ";
						cin.ignore();
						getline(cin, address);
						p->setaddress(address);//입력받은 값을 set함수를 사용하여 원소의 address값으로 지정한다.
					}
				}
			}
			if (want == 2) {//급여의 수정을 원한다는 2을 입력받은 경우
				for (it = em.begin(); it != em.end(); it++) {
					employ* p = *it;
					if (p->getName() == name) {
						cout << "수정할 급여를 입력해주세요 : ";
						cin >> pay;
						p->setpay(pay);//입력받은 값을 set함수를 사용하여 원소의 pay값으로 지정한다.
					}
				}
			}
			continue;//종료를 원할때까지 반복하기 위해 해당 내용이 끝난 후 다시 반복문으로 돌아간다.
		}
		else {//수정을 원한다는 1이 아닌 다른 입력을 받은 경우
			cout << "수정을 원하시지 않으므로 프로그램을 종료하겠습니다" << endl;
			break;//수정을 진행하지 않기 때문에 반복문에서 빠져나온다.
		}
	}
}

void employee::exit1() {//프로그램을 종료하는 함수
	cout << "프로그램을 종료합니다" << endl;
	exit(0);//프로그램을 종료하게 만들어주는 exit함수를 사용한다.
}



int main() {
	string name;
	string address;
	int pay = 0;
	int num;
	employee e;

	while (1) {//프로그램 종료인 6번이 아닌 이상 계속 반복되게 만들어준다.
		cout << "1. 직원 추가하기" << endl;
		cout << "2. 이름으로 직원 검색하기" << endl;
		cout << "3. 직원 정보 수정하기" << endl;
		cout << "4. 전체 직원 출력하기" << endl;
		cout << "5. 직원 삭제하기" << endl;
		cout << "6. 프로그램 종료하기" << endl;
		cout << "선택할 번호를 입력해주세요 : ";
		cin >> num;
		if (num == 1) {//직원 추가를 원하는 경우
			e.add();//직원을 추가하는 내용이 담겨 있는 add함수 사용
			cout << endl;
		}
		else if (num == 2) {//직원 검색을 원하는 경우
			e.search();//직원을 검색하는 내용이 담겨 있는 search함수 사용
			cout << endl;
		}
		else if (num == 3) {//직원 수정을 원하는 경우
			e.change();//직원을 수정하는 내용이 담겨있는 change함수 사용
			cout << endl;
		}
		else if (num == 4) {//전체 직원 출력을 원하는 경우
			e.show();//직원을 출력하는 내용을 담은 show함수 사용
			cout << endl;
		}
		else if (num == 5) {//직원 삭제를 원하는 경우
			e.remove();//직원을 삭제하는 내용을 담은 remove함수 사용
			cout << endl;
		}
		else if (num == 6) {//프로그램 종료를 원하는 경우
			e.exit1();//프로그램을 종료하는 내용을 담은 exit1함수 사용
		}

	}
}
