#include <iostream>
using namespace std;

int main() {

	int arr2d[2][3] = { {10, 20, 30}, {40, 50, 60} };

	int i, j;
	int(*ptr)[3] = arr2d; // 배열 포인터 선언 [3] 인 이유는 {10, 20 ,30} 2차원 배열에서 이동시키기 위해

	//int* p = arr2d; //2차원 배열은 그냥 포인터로는 불가능

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d ", ptr[i][j]); // 배열 포인터로 참조
		printf("\n");
	}

	return 0;
}