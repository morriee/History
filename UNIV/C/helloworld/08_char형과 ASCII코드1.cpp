// char :character의 준말, 1바이트 정수형(참고 int:4바이트)
// character: 문자(반각문자 :  ABCabc12378-*+\/# 등 키보드로 입력할수있는 기호)만 됌. 한글, 한자, 일본어, 등 정각문자는 안됌.

#include <stdio.h>

int main() {
	char a = 67;

	printf("%c\n", a); // 'C' == 67
	//or printf("%d\n", 'C');
}

//ASCII : American Standard (문자와 숫자를 대응시키는 표)