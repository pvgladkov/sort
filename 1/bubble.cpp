#include <iostream>
using namespace std;

#define rdtscll(val) __asm__ __volatile__("rdtsc" :"=A"(val))

int main() {
    int a[100];
    int t;
    int count;
    char question;
    long long c1, c2;
    
    while (question != 'n') {
		cout << "Введите кол-во элементов массива: ";
		cin >> count;
		cout << "Введите элементы массива \n";
		for (int i = 0; i < count; ++i) {
			cin >> a[i];
		}
		rdtscll(c1); 
		for (int i = 0; i < count; ++i) {
			for (int j = count - 1; j > i; j--) {
				if (a[j-1] > a[j]) {
					t = a[j-1];
					a[j-1] = a[j];
					a[j] = t;
				}
			}
		}      
		rdtscll(c2); 
		cout << "Отсортированный массив: ";
		for (int i = 0; i < count; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
		cout << "Время выполнения в тиках: ";
		cout << c2 - c1;
		cout << "\n";
		cout << "Еще? (y/n) ";
		cin >> question;
	}
}

