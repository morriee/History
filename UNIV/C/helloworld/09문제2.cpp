/*
2. ü��(kg,�Ǽ�)�� Ű(m, �Ǽ�)�� �Է¹޾Ƽ� ü���� ������ ���ϴ� ���α׷��� ����� ������.
*/

#include <stdio.h>
int main() {
	float weight;
	float height;

	printf("ü�� �Է� (kg) : ");
	scanf_s("%f", &weight);
	printf("Ű �Է� (m) : ");
	scanf_s("%f", &height);

	// t�� ���� = t * t
	float bmi = weight / (height * height);

	printf("BMI : %f\n", bmi);
}