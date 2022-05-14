#ifndef RECORD_H_
#define RECORD_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::string RECORDS_FILE_BEGINNER = "records/records_b.txt";
const std::string RECORDS_FILE_INTER = "records/records_i.txt";
const std::string RECORDS_FILE_ADVANCED = "records/records_a.txt";

struct Record
{
    std::string name;
    double milliseconds;
};

void printRecords(std::vector<Record> &recordsVec);

void sortRecords(std::vector<Record> &recordsVec);

void saveRecord(double recordTime, std::vector<Record> &recordsVec);

void readRecordsFile(std::vector<Record> &recordsVec, std::string difficulty);

void writeRecordsFile(std::vector<Record> &recordsVec, std::string difficulty);

#endif

