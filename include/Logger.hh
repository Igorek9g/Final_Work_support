//
// Created by idalov on 10.05.17.
//

#ifndef FINAL_LOGGER_HH
#define FINAL_LOGGER_HH

#include <fstream>
#include <iostream>
#include <sstream>
#include <G4Threading.hh>
#include <G4AutoLock.hh>
#include <ctime>
namespace {
    G4Mutex aMutex=G4MUTEX_INITIALIZER;
}

class Logger{
private:

public:
    static std::ofstream fout;
    static int verbose_level;
    static void Open(int Verbose_level);
    static void Close();
    static void Info(std::string a);
    static void Info(std::string b, int a);
    static std::string title(int level);
};
#endif //FINAL_LOGGER_HH
