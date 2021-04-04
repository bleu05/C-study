#include<iostream>
using namespace std;

int main() {
	int a = 10;//변수 a의 값을 10으로 지정해줌
	int* pa = &a;//
	cout << "변수 a의 주소는 : " << &a<<endl;/*&는 a변수가 할당된 메모리의
									   시작 주소를 반환해준다.*/
	cout << "a의 값 : " << *pa << endl;/*pa에 a의 주소를 저장하였으므로 *을 이용해 
									 출력하게 되면 a변수의 값이 반환된다.*/


}