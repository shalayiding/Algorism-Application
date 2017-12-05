#include "sorting algorithms.h"
#include<algorithm>
#include<fstream>
void Bubblesort::BubSort(int nums[],int n)
{
	int loopCC = 1;//loop control push the sorting to maxspeed
	for (int k = 0; k < n-1; k++)
	{
		for (int i = 0; i < n-loopCC; i++)//last element being sorting so we can save the loop time
		{
			if (nums[i] > nums[i + 1])
				swap(nums[i], nums[i + 1]);
		}
	}
}

void SelectionSort::SelecSort(int nums[], int n)
{
	int i, j, first, temp;
	int numLength = n;
	for (i = numLength - 1; i > 0; i--)
	{
		first = 0;                 
		for (j = 1; j <= i; j++)   // locate smallest between positions 1 and i.
		{
			if (nums[j] > nums[first])
				first = j;
		}	
		temp = nums[first];   // Swap smallest found with element in position i.
		nums[first] = nums[i];
		nums[i] = temp;
	}
	
}

void InsertionSort::InserSort(int nums[], int n)
{
	int j, temp;

	for (int i = 0; i < n; i++) {
		j = i;

		while (j > 0 && nums[j] < nums[j - 1]) {
			temp = nums[j];
			nums[j] = nums[j - 1];
			nums[j - 1] = temp;
			j--;
		}
	}
}

void MergeSort::Mergesort(int nums[], int n)
{


}
