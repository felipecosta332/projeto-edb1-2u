#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void bubbleSort(std::ofstream &writer, int arr[], int n) 
{
    clock_t begin = clock();
	int i, j; 
	bool swapped; 
	for (i = 0; i < n-1; i++) 
	{ 
		swapped = false; 
		for (j = 0; j < n-i-1; j++) 
		{ 
			if (arr[j] > arr[j+1]) 
			{ 
				swap(&arr[j], &arr[j+1]); 
				swapped = true; 
			} 
		} 

		if (swapped == false) 
			break; 
	} 
    clock_t end = clock();
    int time = (double) (end - begin) * 1000;
    writer << n << " " << time << std::endl;
}

void selectionSort(std::ofstream &writer, int arr[], int n)  
{ 
    clock_t begin = clock();
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        swap(&arr[min_idx], &arr[i]);  
    }  
    clock_t end = clock();
    int time = (double) (end - begin) * 1000;
    writer << n << " " << time << std::endl;
}

int main() {
    srand(time(0));
    for (int i = 1; i <= 10; i++) {
        std::string bubbleFile, selectionFile;
        std::ostringstream fileName;
        fileName << "data/bubbledata" << i << ".csv";
        bubbleFile = fileName.str();
        fileName.str("");
        fileName.clear();
        fileName << "data/selectiondata" << i << ".csv";
        selectionFile = fileName.str();
        std::ofstream bubbleWriter(bubbleFile);
        std::ofstream selectionWriter(selectionFile);
        for (int j = 1; j <= 1000; j++) {
            int vectorA[j], vectorB[j];
            for (int k = 0; k < j; k++) {
                vectorA[k] = rand() % 100;
                vectorB[k] = vectorA[k];
            }
            bubbleSort(bubbleWriter, vectorA, j);
            selectionSort(selectionWriter, vectorB, j);
        }
        bubbleWriter.close();
        selectionWriter.close();
    }
    return 0;
}