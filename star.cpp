#include<iostream>
using namespace std;

int main() {
	int n;//�Է¹޴� ���ڸ� �����޴� ����
	cin >> n;

	for (int p = 1; p <= n; p++) {//n���� �� ������ n�� �ݺ��� �� �ֵ��� �����Ѵ�

		if (n % 2 == 0) {//���� ¦���� ���

			for (int i = 1; i <= n / 2; i++) {/*¦���� ��� ���� ���� ������ŭ ���ٿ� �� ������ ���Ƿ� 
											  i<=n/2�� �������� ���� �Ѵ�*/
				cout << " * ";//���⸦ ������ *�� �Է����ش�
			}

			cout << endl;//��� *�� ���� �����ϱ� ���� endl�� ���� ���ش�.
		}
		else//Ȧ���� ���
		{
			for (int k = 1; k <= n / 2 + 1; k++)/*Ȧ���� ��� ���ٿ� ���� ���� �ͺ��� 1���� ���� �� ���Ƿ� 
												k<=n/2+1�� �������� ���� �Ѵ�*/
			{
				cout << " * ";
			}
			cout << endl;
		}
		cout << " ";/*���� �ؿ� �� �ι�° �ٿ� ���� ���� �Է����ֱ� ����
					���⸦ �־��ش�.*/
		for (int k = 1; k <= n / 2; k++) {/*�Է��� ������ ���� ���� ��ŭ �ι�° �ٿ� ���� �ϱ� ������
										  ���ǽ��� k <= n / 2�� �Ѵ�.*/
			cout << " * ";
		}
		cout << endl;
	}
	return 0;
}