/* 
	2. 1, 2, 3, 4, 6, 12 ������ �ڿ����� ����Ͻÿ�.
*/

#include <stdio.h>
void NaturalNumber(int, int); 


int main() {
	int n; int i = 1;
	scanf("%d", &n);

	NaturalNumber(i,n);

}

void NaturalNumber(int i, int n) {
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			printf("%d, ", i);
		}
	}
	printf("%d\n", n);
}