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

/**
 * 
 */
void Heapify( int A[100], int i, int iHeapSize){
	
	int iRight, iLeft, iMax;

	iRight = 2*i + 1;
	iLeft = 2*i;
	
	if( iLeft <= iHeapSize and A[ iLeft ] > A[ i ] ){
		iMax  = iLeft;
	} else {
		iMax = i;
	}
	if(iRight <= iHeapSize and A[ iRight ] > A[ iMax ]){
		iMax = iRight;
	}
	
	if( iMax != i ){
		int iTemp = A[i];
		A[i] = A[iMax];
		A[iMax] = iTemp;
		Heapify( A, iMax, iHeapSize );
	}
}

/**
 * 
 */
void BuildMaxHeap( int A[100], int iCount ){
	
	int i;
	
	cout << " размер кучи: " << iCount  << "\n";
	
	for( i = iCount/2; i > 0; i-- ){
		Heapify( A, i, iCount );
	}
}

/**
 * Сортировка
 */
void HeapSort( int A[100], int iCount ){

	int iHS = iCount;
	
	BuildMaxHeap( A, iCount );
	for( int i = iCount; i > 1; i-- ){
		iHS--;
		int iTemp = A[1];
		A[1] = A[i];
		A[i] = iTemp;
		Heapify( A, 1, iHS );
	}
}

/*
 * Основной блок программы
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
		HeapSort(array, count );
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