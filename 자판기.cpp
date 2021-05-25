#include<iostream>
#include<string>
using namespace std;

class VendingMachine
{
private:
	string name; // ���� �̸�
	int price; // ����
	int total = 0; // ���� �ջ� ��
public:
	VendingMachine() {}; 
	void purchase(double v1);//�Ž��������
	void menu();//�޴��߰���
	void upgrademenu();//�޴��߰�
	string getName();//�߰��� �޴� �̸� ����
	double getPrice();//�߰��� �޴� ���� ����
	double getTotal(double total);//���� ����
	void setName(string n);//�߰��� �޴� �̸� ����
	void setPrice(int p);//�߰��� �޴� ���� ����
	void setTotal(int t);
	int returngap = 200;//�Ž����� ����
};
void VendingMachine::menu() {
	cout << "==========SWING ���Ǳ�==========" << endl;
	cout << "1. ��ī�ݶ� : 1200��" << endl;
	cout << "2. ĥ�� ���̴� : 1400��" << endl;
	cout << "3. �̿��� ȭ�̹� : 1800��" << endl;
	cout << "4. �غ� ��" << endl;
	cout << "5. ���" << endl;
	cout << "6. ����" << endl;
}
void VendingMachine::upgrademenu() {
	cout << "==========SWING ���Ǳ�==========" << endl;
	cout << "1. ��ī�ݶ� : 1200��" << endl;
	cout << "2. ĥ�� ���̴� : 1400��" << endl;
	cout << "3. �̿��� ȭ�̹� : 1800��" << endl;
	cout << "4."<<name <<":"<<price<<"��"<< endl;//�Է¹��� �޴��� �̸��� ������ �� �� ��µǰ� �Ѵ�
	cout << "5. ���" << endl;
	cout << "6. ����" << endl;
}
void VendingMachine::purchase(double v1) {
	int gap;//����ڿ��� �Է¹��� ������ ������ ����
	cout << endl << "�� �ݾ� :" << v1 << endl;
	cout << "���� �Է��ϼ��� :";
	cin >> gap;
	int change = gap - v1;/*�Է¹��� ���ݿ��� ������ �� ���� �־��ش�
						  �Ž������� �޾ƾ��ϴ��� ���� �� �����ϴ��� �����ؾ��ϱ� ����*/

	for (;;) {
		if (gap > v1) {//������ �ݾ��� ���պ��� ū ���
			if (change % 100 == 0) {//�޾ƾ��ϴ� �Ž������� 100�������� �������� ���
				cout << "�Ž��� ���Դϴ�" << endl;
				if (change/100 <= returngap) {//���ȿ� �ִ� 100���� ������ �޾ƾ��ϴ� �Ž��������� ���� �Ž������� ���� �� �ִ� ���
					cout << "100�� :" << change / 100 << endl;
					cout << "��⿡ ���� �Ž�����(100�� ����) :" << returngap - (change / 100) << endl;/*�Ž������� ���� ��ŭ
																						   ���ȿ� �ִ� 100���� ������ ���δ�*/
					break;
				}
				else {//���ȿ� �ִ� 100���� ������ �޾ƾ��ϴ� �Ž��������� ���� �Ž������� ���� �� ���� ���
					cout << "��⳻�� �ܵ��� �����մϴ�. 010-0000-0000���� �����ּ���" << endl;
					cout << "��⿡ ���� �Ž�����(100���� ����) : 0" << endl;
					break;
				}
			}
			else {//�޾ƾ��ϴ� �Ž������� 100�������� �������� �ʴ� ���
				cout << "�Ž������� 100���� �����մϴ�" << endl;
				cout << "100�� :" << change / 100 << "��" << endl;
				cout << "��⿡ ���� �Ž�����(100�� ����) :" << returngap - (change / 100) << endl;
				break;
			}
		}
		else {//������ �ݾ��� ���պ��� �۰ų� ���� ���
			if (gap == v1) {//������ �ݾװ� ������ ���� ���
				cout << "�Ž������� �ʿ� �����ϴ�. �ȳ��� ������" << endl;
				cout << "��⿡ ���� �Ž�����(100�� ����) :" << returngap << endl;
				break;
			}
			else {//������ �ݾ��� ���պ��� ���� ���
				cout << "�ݾ��� �����մϴ�. �ٽ� �־��ּ���" << endl;
				cout << "���� �Է��ϼ��� :";
				cin >> gap;
				change = gap - v1;
			}
		}
	}
}
void VendingMachine::setName(string n) {
	cout << "�߰��� ���� �̸��� �Է����ּ��� : ";
	cin >>  name;//����ڿ��� �߰��� ������ �̸��� �Է¹޴´�
}
string VendingMachine::getName() {
	return name;//���� �̸� ����
}
void VendingMachine::setPrice(int p) {
	cout << "�Ǹ��� ������ �Է��ϼ��� : ";
	cin >> price;//����ڿ��� �߰��� ������ ������ �Է¹޴´�
}
double VendingMachine::getPrice() {
	return price;//���� ���� ����
}
double VendingMachine::getTotal(double total) {
	return total;//���� ��õ
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
		cout << "��ȣ�� �������ּ��� :";
		cin >> select;
		if (select == 1) {//1���� ������ ���
			goods1 = 1200;
			cout << "������ ������ �Է����ּ��� : ";
			cin >> number1;
			continue;
		}
		else if (select == 2) {//2���� ������ ���
			goods2 = 1400;
			cout << "������ ������ �Է����ּ��� : ";
			cin >> number2;
			continue;
		}
		else if (select == 3) {//3���� ������ ���
			goods3 = 1800;
			cout << "������ ������ �Է����ּ��� : ";
			cin >> number3;
			continue;
		}
		else if (select == 4) {//4���� ������ ���
			goods4 = price;/*4���� �ݾ��� ������ ���� �ƴ� ����ڿ��� �Է��� �޾ƾ� �ϱ� ������
						   ����ڰ� �Է��� �ݾ��� ���� �ִ� ���� price�� �����ش�*/
			cout << "������ ������ �Է����ּ��� : ";
			cin >> number4;
			continue;
		}
		else if (select == 5) {
			total = goods1 * number1 + goods2 * number2 + goods3 * number3 + goods4 * number4;
			cout << "��� ���Դϴ�. ��ٷ��ּ���..." << endl;
			cout << endl;
			a.getTotal(total);
			break;
		}
	}
	a.purchase(total);
}
