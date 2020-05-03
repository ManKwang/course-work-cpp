// CourseWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#define NARRAY 18   // Розмір масиву

using namespace std;

/**
* Структура блоку
*/
struct bucket
{
    int count;
    int* value;
};

/**
* Функція для порівняння двох змінних
* @return int
*/
int compareIntegers(const void* first, const void* second)
{
    int x = *((int*)first), y = *((int*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

/**
* Функція сортування типу void
* @param float arr[] масив для сортування
* @param int n розмір
*/
void bucketSort(int array[], int n)
{
    // створюэмо 3 блоки
    struct bucket buckets[3];
    int i, j, k;

    // Заповнюємо
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }

    for (k = 0, i = 0; i < 3; i++)
    {
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
}


/**
* Точка входу
* @return int
*/
int main(char* arg[])
{
	// Створюємо масив з 18 елементів
	// Подаємо матрицю 2х9 у вигляді звичайного списку (для оптимізації)
	int arr[NARRAY];

	for (int i = 0; i < NARRAY; i++)
	{
		// Заповнюємо масив випадковими числами від 1 до 100
		arr[i] = rand() % 100 + 1;
	}

	// Виводимо масив до сортування
	cout << "Before Sorting\n";
	for (int i = 0; i < NARRAY; i++)
		cout << arr[i] << " ";


	// Викликаємо функцію для сорутвання масиву
	bucketSort(arr, NARRAY);

	// Виводимо масив після сортування
	cout << "\nAfter Sorting \n";
	for (int i = 0; i < NARRAY; i++)
		cout << arr[i] << " ";

	return 0;
}

