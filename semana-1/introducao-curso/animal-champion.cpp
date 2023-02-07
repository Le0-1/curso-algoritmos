#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

void openFile(ifstream& myFile, std::string fileName) {
    myFile.open(fileName);

    if (myFile.is_open()) {
        std::cout << "Successefully opened the file" << std::endl;
    }
    else {
        std::cout << "File was not opened, terminating program" << std::endl;
        exit(-1);
    }
}

int numberOfWords(ifstream& myFile) {
    string line, word;
    istringstream iss;

    int counterOfWords = 1;

    while (getline (myFile, line)) {

        if (myFile.good()) {
            iss.clear();
            iss.str(line);

            while (iss.good()) {
                iss >> word;
                counterOfWords++;
            }
        }
    }
    myFile.close();

    return counterOfWords;
}

string animalChampion(ifstream& myFile) {
    istringstream iss;
    string line, word;
    string champion = "No Winner";
    double chanceOfWord = (1.0/numberOfWords(myFile)) * 100.0;

    myFile.open("text.txt");

    srand(time(0));

    while (getline (myFile, line)) {

        if (myFile.good()) {
            iss.clear();
            iss.str(line);

            while (iss.good()) {
                double randomNumber = rand() % 100;
                iss >> word;

                if (chanceOfWord > randomNumber) {
                    champion = word;
                    return champion;
                }
            }
        }
    }
    myFile.close();
    return champion;
}


int main() {
    ifstream myFile;

    openFile(myFile, "text.txt");

    std::cout << animalChampion(myFile) << std::endl;

    myFile.close();
    
    
}
