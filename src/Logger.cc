//
// Created by idalov on 10.05.17.
//

#include <Logger.hh>

std::ofstream Logger::fout;

int Logger::verbose_level = 0;

void Logger::Open(int Verbose_level){
    verbose_level=(Verbose_level)?1:0;
    fout.open("//home//student//CLionProjects//Final_upto_1305//log.txt");
}

void Logger::Close(){
    fout.close();
}

void Logger::Info(std::string a){
    if(!verbose_level)return;
    G4AutoLock l(&aMutex);
    try {if(!fout.is_open())throw 14;
        fout << title(1) << a << std::endl;
    }catch (int b){
        std::cout<<"Logger didn't initialize:"<<b<<std::endl;
    }
}

void Logger::Info(std::string b, int a){
    if(!verbose_level)return;
    try {if(!fout.is_open())throw 14;
        fout << title(1) << b << a << std::endl;
    }catch (int b){
        std::cout<<"Logger didn't initialize:"<<b<<std::endl;
    }
}

std::string Logger::title(int level) {
    std::ostringstream strs;
    time_t t = time(0);
    struct tm * now = localtime( & t );
    strs << (level?"INFO:":"ERROR:") <<
         (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday << '|'
         << (now->tm_hour) << ':'
         << (now->tm_min) << ':'
         << (now->tm_sec) << '|'
         <<"ThreadID#" << G4Threading::G4GetThreadId() << ":";
    return strs.str();
}