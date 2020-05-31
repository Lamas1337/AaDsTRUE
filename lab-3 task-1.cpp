#include <iostream>

using namespace std;

// функция нахождения наибольшего подмассива при слиянии левой и правой части
int* FindMaxCrossingSubArray(int* array, int low, int mid, int high) {
	int LeftSum = INT_MIN;
	int sum = 0;
	int maxLeft;

	// находим сумму элементов левой части
	// запоминая индекс ключевого элемента
	for (int i = mid; i >= low; i--) {
		sum += array[i];
		if (sum > LeftSum) {
			LeftSum = sum;
			maxLeft = i;
		}
	}

	int RighSum = INT_MIN;
	int maxRight = 0;
	sum = 0;

	// находим сумму элементов правой части
	// запоминая индекс ключевого элемента
	for (int j = mid + 1; j <= high; j++) {
		sum += array[j];
		if (sum > RighSum) {
			RighSum = sum;
			maxRight = j;
		}
	}

	// возвращам оптимальный интервал левой части
	int OptIntrvArray[3];
	OptIntrvArray[0] = maxLeft;
	// возвращам оптимальный интервал правой части
	OptIntrvArray[1] = maxRight;
	// Сумма интервалов
	OptIntrvArray[2] = LeftSum + RighSum;
	return OptIntrvArray;
}

// функция нахождения максимального под.массива
int* FindMaxSubArray(int* array, int low, int high) {
	if (high == low) {
		int* Arr4 = new int[3];
		Arr4[0] = low;
		Arr4[1] = high;
		Arr4[2] = array[low];
		return (Arr4);
	}
	else {
		int mid = (low + high) / 2;
		// создаём временные массивы для хранения результата последующих вычислений
		int* Arr1 = new int[3];
		int* Arr2 = new int[3];
		int* Arr3 = new int[3];
		// находим наибольшие массивы среди:
		//1)слева 
		//2)справа 
		//3)левой и правой части одновременно
		Arr1 = FindMaxSubArray(array, low, mid);
		Arr2 = FindMaxSubArray(array, (mid + 1), high);
		Arr3 = FindMaxCrossingSubArray(array, low, mid, high);
		// выбираем случай, который больше
		if (Arr1[2] >= Arr2[2] && Arr1[2] >= Arr3[2]) return (Arr1);
		else if (Arr2[2] >= Arr1[2] && Arr2[2] >= Arr3[2]) return (Arr2);
		else return (Arr3);
	}

}
int main() {
	// выбираем количество дней
	const int n = 31;
	if (n <= 1) {

		cout << "Error" << endl;
		system("pause");
	}
	// индекс последнего дня
	const int k = n - 1;
	// индекс центрального дня
	int mid = k / 2;
	// массив изменения цен между днями
	int Array[k];
	// массив цен на каждый день
	int ArrayWithCost[n] = { 190,155,119,105,182,125,114,142,170,137,161,141,118,185,160,107,151,146,171,159,197,181,144,148,104,147,179,115,177,136,176 };

	// заполняем массив изменения цены
	for (int i = 0; i < k; i++) {
		Array[i] = ArrayWithCost[i + 1] - ArrayWithCost[i];
		cout << Array[i] << " ";	
	}
	cout << endl;


	// 1)день покупки
	// 2)день продажи
	// 3)прибыль
	int* Arr6 = new int[3];
	Arr6 = FindMaxSubArray(Array, 0, k);
	cout << "Day of purchase: " << Arr6[0] + 1 << endl;
	Arr6 = FindMaxSubArray(Array, 0, k);
	cout << "Sale day: " << Arr6[1] + 2 << endl;
	Arr6 = FindMaxSubArray(Array, 0, k);
	cout << "Earnings: " << Arr6[2] << endl;

	system("pause");
	return 0;
}