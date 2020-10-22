#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>

/*void linearSearch(std::ofstream &writer, int target, int size, int *vector) {
    clock_t begin = clock();
    for (int i = 0; i < size; i++) {
        if (vector[i] == target) {
            break;
        }
    }
    clock_t end = clock();
    double time = double (end - begin) * 1000;
    writer << size << " " << time << std::endl;
}

void binarySearch(std::ofstream &writer, int target, int size, int *vector) {
    clock_t begin = clock();
    int start = 0, last = size - 1, half;
    while (start <= last) {
        half = (start + last) / 2;
        if (target < vector[half]) {
            last = half -1;
        } else if (target > vector[half]) {
            start = half + 1;
        } else {
            break;
        }
    }
    clock_t end = clock();
    double time = double (end - begin) * 1000;
    writer << size << " " << time << std::endl;
}*/



int main() {
    int input;
    std::ifstream dataReader("testcases.txt");
    std::ofstream linearWriter("lineardata.csv");
    std::ofstream binaryWriter("binarydata.csv");
    dataReader >> input;
    while (input != 0) {
        int vector[input];
        int target = rand() % input + 1;
        for (int i = 0; i < input; i++) {
            dataReader >> vector[i];
        }
        // linearSearch(linearWriter, target, input, &vector[0]);
        // binarySearch(binaryWriter, target, input, &vector[0]);
        dataReader >> input;
    }
    dataReader.close();
    linearWriter.close();
    binaryWriter.close();
    return 0;
}