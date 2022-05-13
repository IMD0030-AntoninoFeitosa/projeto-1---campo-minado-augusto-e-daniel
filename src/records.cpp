#include "records.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void saveRecord(double time, std::vector<Record> &RecVec){
    std::string resposta;
    std::cout << "Deseja salvar o seu tempo? [Y/N] ";
    std::cin >> resposta;
    Record current;
    if(resposta == "Y"){
        current.milliseconds = time;
        std::cout << "Digite o seu nome: ";
        std::cin >> current.name;
        RecVec.push_back(current);
    }
    else if(resposta == "N"){
        std::cout << "De toda forma, parabéns pela partida!" << std::endl;
    }
}

void printRecords(std::string fileDirectory){
    std::ifstream recordsFile(fileDirectory);
    std::string printRecords;
    while(getline(recordsFile, printRecords)){
      std::cout << printRecords << std::endl;
    }
}