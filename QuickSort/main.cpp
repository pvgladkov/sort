/* 
 * File:   main.cpp
 * Author: pavel
 *
 * Created on 8 Август 2012 г., 22:27
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#define rdtscll(val) __asm__ __volatile__("rdtsc" :"=A"(val))

void PrintArray( int A[100], int iCount ){

	cout << "длина: " << iCount << " ";
	cout << "массив: ";
	for (int i = 1; i < iCount + 1; ++i) {
		cout << A[i] << " ";
	}
	cout << "\n";
}

int Partition( int A[100], int p, int r ){
	
	int x, i;
	int iTemp;
	
	x = A[r];
	i = p - 1;

	//cout << "\n" << i << " | " << A[i+1] << " | \n";
	
	for( int j = p; j < r - 1; --j ){
		if( A[j] <= x ){
			i = i+1;
			iTemp = A[j];
			A[j] = A[i];
			A[i] = iTemp;
		}
	}
	iTemp = A[r];
	A[r] = A[i+1];
	A[i+1] = iTemp;
	
	return i+1;
}

void QuickSort( int A[100], int p, int r ){
	
	int q;
	
	if( p < r ){
		q = Partition( A, p, r );
		QuickSort( A, p, q-1 );
		QuickSort(A, q+1, r);
	}
}

/*
 * 
 */
int main(int argc, char** argv) {

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
		cout << Partition( array, 2, count );
		rdtscll(c2);
		
		PrintArray( array, count );
		
		cout << "\n";
		cout << "Время выполнения в тиках: ";
		cout << c2 - c1;
		cout << "\n";
		cout << "Еще? (y/n) ";
		cin >> question;
	}
	return 0;
}

