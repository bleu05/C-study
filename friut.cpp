#include <iostream>// c언어의 <stdio.h>와 같은 역할
using namespace std;//std::을 생략하기 위해 입력

int main() {//프로그램의 시작점
	cout << "당신의 이름은 무엇입니까?";//count은 데이터를 화면에 출려할때 사용, <<뒤에 보여질 문자 표현
	char name[11];/*문자열 지정,항상 문자수+1의 갑으로 입력해주어야 함
				  배열의 크기가 11이므로 10개 이하의 문자 저장 가능
				  영어나 숫자는 1글자 당 1비트씩, 한글은 1글자 당 2비트씩 들어감*/
	cin.getline(name, 11, '\n');/*cin은 c언어의 scanf와 같은 기능을 함
								cin 객체의 gentline()멤버함수 이용시 공백 포함한 문자열 입력 받기 가능
								cin.getlin(저장할 배열,크기,입력 끝 구분문자)*/
	cout << "반갑습니다." << name << "님" << endl;//endl 줄바꿈
	
	
	int apple, banana, orange;//가격 변수 생성
	int num1, num2, num3;//갯수 변수 생성
	
	cout << "apple의 가격은 얼마입니까?";
	cin >> apple;//>>은 왼쪽의 객체로부터 데이터를 읽어 오른쪽 연산자에게 지정된 변수에 삽입, apple의 가격 입력
	cout << "banana의 가격은 얼마입니까?";
	cin >> banana;//banana의 가격 입력
	cout << "orange의 가격은 얼마입니까?";
	cin >> orange;//orange의 가격 입력
	cout << "apple은 몇 개 있습니까?";
	cin >> num1;//apple의 갯수 입력
	cout << "banana은 몇 개 있습니까?";
	cin >> num2;//banana의 갯수 입력
	cout << "orange은 몇 개 있습니까?";
	cin >> num3;//orange의 갯수 입력

	int total = apple * num1 + banana * num2 + orange * num3 - 500;//변수선언과 500이 할인 된 총액 지정

	cout << "총" << total <<"원 입니다.";

	return 0;


}