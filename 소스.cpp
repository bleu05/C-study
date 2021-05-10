#include<iostream>
#include<string.h>
using namespace std;

void total(int* a, int* b, int* c, int* d) {/*모든 은행 계좌의 금액의 총합을 저장해야하기 때문에
									  금액의 갯수인 4개만큼의 포인터 변수를 지정해주었습니다.*/
	int sum;//합계를 저장할 변수
	sum = *a + *b + *c + *d;//총합을 만들기 위해 변수들의 값이 저장되어 있는 포인터 변수를 이용합니다.
	cout << "현재 SWING 자산관리 서비스에 등록된 회원님의 총 자산은 " << sum << "원입니다. " << endl;
	cout << "********************************************************************" << endl;
}

void myaccounts(string * a1, int* b1) {//매개변수로 포인트변수 사용
	for (int i = 0; i < 4; i++) {//배열이 0~3까지 존재하기 때문에 4이하의 숫자까지 반복이 되게 만든다.
		cout << a1[i] << '|';
	}
	cout << endl;//한 줄을 띄워주기 위하여 사용
	for (int i = 0; i < 4; i++) {//배열이 0~3까지 존재하기 때문에 4이하의 숫자까지 반복이 되게 만든다.
		cout << b1[i] << '|';
	}
	cout << endl;//한 줄을 띄워주기 위하여 사용
}

int main() {
	int total_money;//모든 은행 계좌의 금액의 총합을 저장할 변수
	string bank_name[4] = { "하나","우리","신한","국민" };/*은행 명을 저장할 배열
												            문자열이기 때문에 string을 사용합니다*/
	int bank[4] = { 5000,4000,0,10 };//은행 별 금액 저장할 배열

	cout << "******************SWING 자산관리 서비스******************" << endl;
	cout << "=====================은행 별 계좌정보=====================" << endl;
	myaccounts(bank_name, bank);/*myaccounts함수를 선언하여 은행 계좌 별 금액을 출력합니다
								  포인터변수에 메모리 값을 넘겨 출력하게 만들어줍니다*/
	cout << "===================================================================" << endl;
	total(&bank[0], &bank[1], &bank[2], &bank[3]);/*total 함수의 매개변수에 bank배열 값들의 주소를 넘겨
												  포인터 변수들에 저장하기 위해 각 변수 값들 앞에 &을 같이 써줍니다.*/




}