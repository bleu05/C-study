#include <iostream>// c����� <stdio.h>�� ���� ����
using namespace std;//std::�� �����ϱ� ���� �Է�

int main() {//���α׷��� ������
	cout << "����� �̸��� �����Դϱ�?";//count�� �����͸� ȭ�鿡 ����Ҷ� ���, <<�ڿ� ������ ���� ǥ��
	char name[11];/*���ڿ� ����,�׻� ���ڼ�+1�� ������ �Է����־�� ��
				  �迭�� ũ�Ⱑ 11�̹Ƿ� 10�� ������ ���� ���� ����
				  ��� ���ڴ� 1���� �� 1��Ʈ��, �ѱ��� 1���� �� 2��Ʈ�� ��*/
	cin.getline(name, 11, '\n');/*cin�� c����� scanf�� ���� ����� ��
								cin ��ü�� gentline()����Լ� �̿�� ���� ������ ���ڿ� �Է� �ޱ� ����
								cin.getlin(������ �迭,ũ��,�Է� �� ���й���)*/
	cout << "�ݰ����ϴ�." << name << "��" << endl;//endl �ٹٲ�
	
	
	int apple, banana, orange;//���� ���� ����
	int num1, num2, num3;//���� ���� ����
	
	cout << "apple�� ������ ���Դϱ�?";
	cin >> apple;//>>�� ������ ��ü�κ��� �����͸� �о� ������ �����ڿ��� ������ ������ ����, apple�� ���� �Է�
	cout << "banana�� ������ ���Դϱ�?";
	cin >> banana;//banana�� ���� �Է�
	cout << "orange�� ������ ���Դϱ�?";
	cin >> orange;//orange�� ���� �Է�
	cout << "apple�� �� �� �ֽ��ϱ�?";
	cin >> num1;//apple�� ���� �Է�
	cout << "banana�� �� �� �ֽ��ϱ�?";
	cin >> num2;//banana�� ���� �Է�
	cout << "orange�� �� �� �ֽ��ϱ�?";
	cin >> num3;//orange�� ���� �Է�

	int total = apple * num1 + banana * num2 + orange * num3 - 500;//��������� 500�� ���� �� �Ѿ� ����

	cout << "��" << total <<"�� �Դϴ�.";

	return 0;


}