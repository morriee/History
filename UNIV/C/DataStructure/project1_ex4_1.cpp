// �Է°� ����� ����ϰ� ���� �� ���� �������� �� ¥���ִ°�.
#include <stdio.h>

void test1() {	//��ȯ���� �ʱ�� ������, ���⼭ ��¹����.
	int sum = 0;	
	for (int i = 1; i < 11; i++) {
		sum += i;
	}	
	printf("test1()�� sum = %d ", sum);
}

int test2() {	// ���������� ��ȯ�ϱ�� �Ͽ�����, ���⼭ ����� ������ ��¦ �����.
	int sum = 0;
	for (int i = 1; i < 11; i++) {
		sum += i;
	}
	return sum;
}

void test3(int x) {
	int sum = 0;
	for (int i = 1; i < x; i++) {
		sum += i;
	}
	printf("test3()�� sum = %d ", sum);
}

int test4(int x) {	
	int sum=0;
	for (int i = 1; i < x; i++) {
	 sum += i;
	}
	printf("test4()�� sum = %d ", sum);
	return 0;
}

int main() {
	int res;	//����:�޸𸮸���û�Ѵ�.

	test1();
	printf("\n");

	//�Լ��� ����� ��ȯ�Ͽ� ������, ����� ������ ���� �� ������ �������� ��밡��.
	res = test2();
	printf("test2()�� sum = %d ", res);
	//�Ǵ� ȣ���Ͽ� ��ȯ�Ѵٴ� ���� ����Ͽ� ������ ���� �ص� ����
	printf("test2()�� sum = %d ", test2());
	printf("\n");

	int x = 10;		//���������� ���� + �ʱ�ȭ
	test3(x);	//x�� �ǸŰ�����: ����, ���, ���ĵ� ����.
	printf("\n");

	test4(100);
	printf("test4()�� sum =%d\n", test4(x));
	printf("test4()�� sum = %d\n", test4(34));
	printf("\n");

}

