#include <stdio.h>

int main() {
	printf("%d %d %d %d\n", sizeof(int), sizeof(char), sizeof(float), sizeof(double));

	int a; char b; float c; double d;
	printf("%d %d %d %d\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d));
}

//sizeof(x): x의 크기를 알려줌
//x: 형에 대한 이름이 들어갈 수 있음.(int, float,...), 변수이름이 들어갈 수있음.