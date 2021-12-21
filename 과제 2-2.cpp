//���� 2-2, 2021111332, ������ȣ�а�, �漼��,2021�� 12�� 1��
#include <iostream>
#include <stdlib.h>//exit�Լ��� �̿��Ͽ� ���α׷��� �����ϱ� ���� �����Ѵ�.
#include <vector>
#include <string>
using namespace std;


class employ {//���� ������ Ŭ����
	int pay;
	string name;
	string address;
public:
	employ(string name, string address, int pay) {//�ʱ�ȭ�� �����ϰ� ����� ���ؼ� �Ű������� �ִ� ������ ����
		this->name = name;//����ڰ� �Է��� ���� ����ִ� name������ ������ name������ ������ ����
		this->address = address;//����ڰ� �Է��� ���� ����ִ� address������ ������ address������ ������ ����
		this->pay = pay;//����ڰ� �Է��� ���� ����ִ� pay������ ������ pay������ ������ ����
	};
	string getName() { return name; }//�Է¹��� ���� ������ �� �ִ� get�Լ� ����
	string getaddress() { return address; }//�Է¹��� ���� ������ �� �ִ� get�Լ� ����
	int getpay() { return pay; }//�Է¹��� ���� ������ �� �ִ� get�Լ� ����
	void setname(string name) {//�Է¹��� ���� name���� �������ֱ� ���� set�Լ� ����
		this->name = name;
	}
	void setaddress(string address) {//�Է¹��� ���� address���� �������ֱ� ���� set�Լ� ����
		this->address = address;
	}
	void setpay(int pay) {//�Է¹��� ���� pay���� �������ֱ� ���� set�Լ� ����
		this->pay = pay;
	}
};

class employee {//����� ������ �Լ����� ����� Ŭ����
	vector<employ*> em;/*�Էµ� �������� ��� employŬ�������� �ٷ�� �ִ�. 
					   �� �������� �������� ����ϱ� ���� vector�� employ�� Ÿ������ ������ �ٷ��*/
public:
	void add();//���� �߰����� �Լ�
	void search();//�Է��� ���� ã�� �Լ�
	void show();//�Է��� ������ ����� �Լ�
	void remove();//�Է��� ���� ������ �Լ�
	void change();//�Է��� ���� ������ �Լ�
	void exit1();//������ �Լ�
};


void employee::add() {//�߰��� ������ �̸�, �ּ�, �޿��� �Է¹޴� �Լ���.
	string name, address;
	int pay;
	cout << endl;
	cout << "�̸� : ";
	cin >> name;
	cout << "�ּ� : ";
	cin.ignore();
	getline(cin, address);
	cout << "�޿� : ";
	cin >> pay;
	cout << endl;

	em.push_back(new employ(name, address, pay));/*vector�� �Է��� ������ �߰��ϱ� push_back()�Լ��� ����ϸ� 
												 ���ο� ��ü�� ����� �Է¹��� name,address,pay�� �߰��Ѵ�.*/
}

void employee::search() {//ã�� ������ �̸��� �Է��ϸ� �ش� ������ ������ ��µǴ� �Լ���.
	string name;

	cout << "�˻��ϰ��� �ϴ� ������ �̸��� �Է����ּ��� : ";
	cin >> name;
	cout << endl;

	vector<employ*>::iterator it = em.begin();//it�� ���� ������ ó���� �ֵ��� �ʱ�ȭ�Ѵ�.
	while (it != em.end()) {//������ ���� �����Ҷ����� �ݺ��Ѵ�.
		employ* p = *it;
		if (p->getName() == name) {//p�� ����Ű�� �� it�� ����Ű�� ������ ���� �Է��� ���� ���� ���
			cout << "�̸� : " << p->getName() << endl;//�ش� ���Ұ� ����Ű�� name ���
			cout << "�ּ� : " << p->getaddress() << endl;//�ش� ���Ұ� ����Ű�� address ���
			cout << "�޿� : " << p->getpay() << endl;//�ش� ���Ұ� ����Ű�� pay ���
			cout << endl;
			break;//�Է��� ������ ������ �� ��������Ƿ� �ݺ����� �������´�.
		}
		else {//p�� ����Ű�� �� it�� ����Ű�� ������ ���� �Է��� ���� ���� ���� ���
			it++;//���� �ε����� �Ѿ ���� ���� �ִ��� Ȯ���Ѵ�.
		}

	}
}

void employee::show() {//�Է¹޾��� �ִ� ��ü ������ ������ ����ϴ� �Լ���.
	vector<employ*>::iterator it;//vector�� ó������ ������ �����ϱ� ���� iterator�� ����Ѵ�.
	for (it = em.begin(); it != em.end(); it++) {/*for���� ����� iterator�� ó������ ������ �����ϵ��� �����. 
												 ��, ó������ ������ �ݺ��� ����������*/
		employ* p = *it;//���Ƿ� ������� Ÿ�Կ� �����ϱ� ���� �ش� ������ �����Ѵ�.
		cout << endl;
		cout << "�̸� : " << p->getName() << endl;//employŬ�������� �����Ͽ��� get�Լ��� ���� ����Ǿ� �ִ� ���� �����´�.
		cout << "�ּ� : " << p->getaddress() << endl;//employŬ�������� �����Ͽ��� get�Լ��� ���� ����Ǿ� �ִ� ���� �����´�.
		cout << "�޿� : " << p->getpay() << endl;//employŬ�������� �����Ͽ��� get�Լ��� ���� ����Ǿ� �ִ� ���� �����´�.
		cout << endl;
	}
	cout << endl;
}

void employee::remove() {//�Է¹��� ������ �̸��� ���� ������ �����ϴ� �Լ�
	show();//������ �����ϱ� �� �������� ������ Ȯ���ϱ� ���� show�Լ� ���

	string name;

	cout << "�����ϰ��� �ϴ� ������ �̸��� �Է����ּ��� : ";
	cin >> name;
	cout <<name<< "���� ������ �Ϸ�Ǿ����ϴ�." << endl;

	vector<employ*>::iterator it = em.begin();//it�� ���� ������ ó���� �ֵ��� �ʱ�ȭ�Ѵ�.
	while (it != em.end()) {//������ ���� �����Ҷ����� �ݺ��Ѵ�.
		employ* p = *it;
		if (p->getName() == name) {//p�� ����Ű�� �� it�� ����Ű�� ������ ���� �Է��� ���� ���� ���
			it = em.erase(it);//erase�Լ��� ����Ͽ� �ش� ������ ���� �����Ѵ�.
			delete p;//������ p�� �����Ѵ�.
			break;//���� �̸��� ã�� �����Ͽ����� �ݺ����� �������´�.
		}
		else {//p�� ����Ű�� �� it�� ����Ű�� ������ ���� �Է��� ���� ���� ���� ���
			it++;//���� ���Ҹ� ����Ű���� �Ѵ�
		}

	}

}

void employee::change() {//�Է¹��� �̸��� ������ ������ �����Ѵ�.
	while (true) {
		int fix;
		string name;
		string address;
		int want;
		int pay;
		vector<employ*>::iterator it = em.begin();//it�� ���� ������ ó���� �ֵ��� �ʱ�ȭ�Ѵ�.
		cout << "�ּ� Ȥ�� �޿��� �����Ͻðڽ��ϱ�?(������ ���Ͻø� 1�� �����ּ���) : ";
		cin >> fix;
		if (fix == 1) {//������ ���Ѵٴ� 1�� �Է¹��� ���
			cout << "� ������ ������ ���Ͻó���? : ";
			cin >> name;
			cout << "�ּ��� ������ ���Ͻø� 1, �޿��� ������ ���Ͻø� 2�� �����ּ��� : ";
			cin >> want;
			if (want == 1) {//�ּ��� ������ ���Ѵٴ� 1�� �Է¹��� ���
				for (it = em.begin(); it != em.end(); it++) {//������ ó������ ������ �ݺ��ǵ��� �����.
					employ* p = *it;
					if (p->getName() == name) {//p�� ����Ű�� �� it�� ����Ű�� ������ ���� �Է��� ���� ���� ���
						cout << "������ �ּҸ� �Է����ּ��� : ";
						cin.ignore();
						getline(cin, address);
						p->setaddress(address);//�Է¹��� ���� set�Լ��� ����Ͽ� ������ address������ �����Ѵ�.
					}
				}
			}
			if (want == 2) {//�޿��� ������ ���Ѵٴ� 2�� �Է¹��� ���
				for (it = em.begin(); it != em.end(); it++) {
					employ* p = *it;
					if (p->getName() == name) {
						cout << "������ �޿��� �Է����ּ��� : ";
						cin >> pay;
						p->setpay(pay);//�Է¹��� ���� set�Լ��� ����Ͽ� ������ pay������ �����Ѵ�.
					}
				}
			}
			continue;//���Ḧ ���Ҷ����� �ݺ��ϱ� ���� �ش� ������ ���� �� �ٽ� �ݺ������� ���ư���.
		}
		else {//������ ���Ѵٴ� 1�� �ƴ� �ٸ� �Է��� ���� ���
			cout << "������ ���Ͻ��� �����Ƿ� ���α׷��� �����ϰڽ��ϴ�" << endl;
			break;//������ �������� �ʱ� ������ �ݺ������� �������´�.
		}
	}
}

void employee::exit1() {//���α׷��� �����ϴ� �Լ�
	cout << "���α׷��� �����մϴ�" << endl;
	exit(0);//���α׷��� �����ϰ� ������ִ� exit�Լ��� ����Ѵ�.
}



int main() {
	string name;
	string address;
	int pay = 0;
	int num;
	employee e;

	while (1) {//���α׷� ������ 6���� �ƴ� �̻� ��� �ݺ��ǰ� ������ش�.
		cout << "1. ���� �߰��ϱ�" << endl;
		cout << "2. �̸����� ���� �˻��ϱ�" << endl;
		cout << "3. ���� ���� �����ϱ�" << endl;
		cout << "4. ��ü ���� ����ϱ�" << endl;
		cout << "5. ���� �����ϱ�" << endl;
		cout << "6. ���α׷� �����ϱ�" << endl;
		cout << "������ ��ȣ�� �Է����ּ��� : ";
		cin >> num;
		if (num == 1) {//���� �߰��� ���ϴ� ���
			e.add();//������ �߰��ϴ� ������ ��� �ִ� add�Լ� ���
			cout << endl;
		}
		else if (num == 2) {//���� �˻��� ���ϴ� ���
			e.search();//������ �˻��ϴ� ������ ��� �ִ� search�Լ� ���
			cout << endl;
		}
		else if (num == 3) {//���� ������ ���ϴ� ���
			e.change();//������ �����ϴ� ������ ����ִ� change�Լ� ���
			cout << endl;
		}
		else if (num == 4) {//��ü ���� ����� ���ϴ� ���
			e.show();//������ ����ϴ� ������ ���� show�Լ� ���
			cout << endl;
		}
		else if (num == 5) {//���� ������ ���ϴ� ���
			e.remove();//������ �����ϴ� ������ ���� remove�Լ� ���
			cout << endl;
		}
		else if (num == 6) {//���α׷� ���Ḧ ���ϴ� ���
			e.exit1();//���α׷��� �����ϴ� ������ ���� exit1�Լ� ���
		}

	}
}
