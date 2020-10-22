#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc == 2) {
        std::ofstream writer("testcases.txt");
        for (int i = 1; i <= std::stoi(argv[1]); i++) {
            writer << i << " ";
            for (int j = 1; j <= i; j++) {
                writer << j << " ";
            }
            writer << std::endl;
        }
        writer << "0";
        writer.close();
    }
    return 0;
}