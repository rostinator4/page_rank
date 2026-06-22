#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>



int main(int argc, char* argv[]) {
    std::unordered_map<std::string, std::string> web_map;

    std::ifstream myFile("test1.txt");

    if(!myFile.is_open()){
        std::cerr << "The file could not be open" << std::endl;
        return 1;
    }

    



    

    return 0;
}