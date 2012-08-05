#include <iostream>
using namespace std;

#define rdtscll(val) __asm__ __volatile__("rdtsc" :"=A"(val))

void merge( int A[100], int p, int q, int r ) {
	
	int n1, n2;
	int L[100];
	int R[100];
	
	n1 = q - p + 1;
	n2 = r - q;
	for (int i = 1; i < n1 + 1; ++i ) {
		L[i] = A[p + i - 1];
	}
	for (int j = 1; j < n2 + 1; ++j ) {
		R[j] = A[q + j];
	}
	//L[n1 + 1] = 900000;
	//R[n2 + 1] = 900000;
	int i = 1;
	int j = 1;
	for (int k = p; k < r + 1; ++k) {
		if ((i <= n1) and (j <= n2)) {
			if (L[i] <= R[j]) {
				A[k] = L[i];
				i = i + 1;
			}
			else {
				A[k] = R[j];
				j = j + 1;
			}
		}
		else {
			if (i <= n1) {
				A[k] = L[i];
				i = i + 1;
			}
			if (j <= n2) {
				A[k] = R[j];
				j = j + 1;
			}
		}
	}
}

void merge_sort( int A[100], int p, int r ) {
	if (p < r) {
		int q = (p + r)/2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main()
{
	int array[100];
	int count;
	long long c1, c2;
	char question;
	while (question != 'n') {
		cout << "Введите кол-во элементов массива: ";
		cin >> count;
		cout << "Введите элементы массива \n";
		for (int i = 1; i < count + 1; ++i) {
			cin >> array[i];
		}
		rdtscll(c1); 
		merge_sort(array, 1, count);
		rdtscll(c2);
		cout << "Отсортированный массив: ";
		for (int i = 1; i < count + 1; ++i) {
			cout << array[i] << " ";
		}
		cout << "\n";
		cout << "Время выполнения в тиках: ";
		cout << c2 - c1;
		cout << "\n";
		cout << "Еще? (y/n) ";
		cin >> question;
	}
	return 0;
}
