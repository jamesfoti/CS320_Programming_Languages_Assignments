/*
 Lab 2
 James Foti
 Red ID: 820124143
 CS 320
 Professor Healey
 7/8/2019
 */


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "MarbleString.cpp"

using namespace std;

void readFile(string fileName);
void outPutMarbleFile(string fileName);

vector<string>listOfWords;
vector<string>listOfCharArrayNames;
vector<string>listOfCharStrings;

void readFile(string fileName) {
    string word;
    ifstream file;
    file.open(fileName);
    
    if (!file.is_open()) return;
    
    while (file >> word) {
        word.erase(remove(word.begin(), word.end(), '['), word.end());
        word.erase(remove(word.begin(), word.end(), ']'), word.end());
        word.erase(remove(word.begin(), word.end(), '"'), word.end());
        word.erase(remove(word.begin(), word.end(), ';'), word.end());
        listOfWords.push_back(word);
    }
    
    for (int i = 0; i < listOfWords.size(); i++) {
        if (listOfWords[i] == "char" && listOfWords[i+2] == "=") {
            listOfCharArrayNames.push_back(listOfWords[i+1]);
            listOfCharStrings.push_back(listOfWords[i+3]);
        }
    }
}
void outPutMarbleFile(string fileName) {
    std::ifstream fin(fileName) ;
    std::ofstream fout("mbl-" + fileName) ;
    std::string line;
    int count = 0;
    while(getline( fin, line) )  {
        stringstream iss(line, ';');
        if (line.find("char") != string::npos && line.find("=") != string::npos) {
            fout << "MarbleString "<<listOfCharArrayNames[count]<<" = ";
            fout<<"\""<<((MarbleString(listOfCharStrings[count])).msArr)<<"\";"<<endl;
            count++;
        }
        else {
            fout<<line<<endl;
        }
    }
}
int main() {
    string fileName = "SourceFile.cpp";
    readFile(fileName);
    outPutMarbleFile(fileName);
    return 0;
}
