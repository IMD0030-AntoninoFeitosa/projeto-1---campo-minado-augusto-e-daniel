#include "records.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

bool record_cmp(Record &a, Record &b) {
  return a.milliseconds < b.milliseconds;
}

void sortRecords(std::vector<Record> &recordsVec){
    std::sort(recordsVec.begin(), recordsVec.end(), record_cmp);
}

void saveRecord(double time, std::vector<Record> &recordsVec){
    std::string resposta;
    std::cout << "Deseja salvar o seu tempo? [Y/N] ";
    std::cin >> resposta;
    Record current;
    if(resposta == "Y"){
        current.milliseconds = time;
        std::cout << "Digite o seu nome: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin,current.name);

        if(current.name == "")
            current.name = "Unknown";

        recordsVec.push_back(current);
    }
    else if(resposta == "N"){
        std::cout << "De toda forma, parabéns pela partida!" << std::endl;
    }
}

void printRecords(std::vector<Record> &recordsVec){
     for (int i = 0; i < recordsVec.size(); i++){
        std::cout << std::left;
        std::setprecision(3);
        std::cout <<  "[ " << std::setw(16) << recordsVec[i].name << " ] - ";
        std::cout << recordsVec[i].milliseconds/1000 << " seg" << std::endl;
    }
}

void readRecordsFile(std::vector<Record> &recordsVec, std::string difficulty) {
    int size;

    std::fstream recordsFile;
    if(difficulty == "b" || difficulty == "beginner")
        recordsFile.open(RECORDS_FILE_BEGINNER);
    else if(difficulty == "i" || difficulty == "intermediary")
        recordsFile.open(RECORDS_FILE_INTER);
    else if(difficulty == "a" || difficulty == "advanced")
        recordsFile.open(RECORDS_FILE_ADVANCED);

    if(recordsFile.is_open()){
        recordsVec.clear();
        recordsFile >> size;
        recordsFile.ignore();
        
        for(int i = 0; i < size; i++){
            Record temp;
            std::getline(recordsFile, temp.name, ';');
            recordsFile >> temp.milliseconds;
            recordsFile.ignore();
            recordsVec.push_back(temp);
        }
    } else {
        std::cout << "ERROR 404 - RECORDS NOT FOUND" << std::endl;
        exit(1);
    }
}

void writeRecordsFile(std::vector<Record> &recordsVec, std::string difficulty){
    std::ofstream recordsFile;

    if(difficulty == "b" || difficulty == "beginner")
        recordsFile.open(RECORDS_FILE_BEGINNER);
    else if(difficulty == "i" || difficulty == "intermediary")
        recordsFile.open(RECORDS_FILE_INTER);
    else if(difficulty == "a" || difficulty == "advanced")
        recordsFile.open(RECORDS_FILE_ADVANCED);

    if(recordsFile.is_open()){
        recordsFile << recordsVec.size() << std::endl;
        for(int i = 0; i < recordsVec.size(); i++){
            recordsFile << recordsVec[i].name << ";" << recordsVec[i].milliseconds << std::endl;
        }
        recordsFile.close();
    }
}