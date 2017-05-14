//
// Created by student on 14.05.17.
// на начало и конец всех запусков


#include <RunAct.hh>
#include <Logger.hh>
#include <Run.hh>

RunAct::RunAct() {
    Logger::Info("\"RunAct.cc works");

}

RunAct::~RunAct() {
    Logger::Info("\"RunAct.cc destructed");

}

G4Run* RunAct::GenerateRun(){

    return new Run;

}

void RunAct::BeginOfRunAction(const G4Run* aRun){
    Logger::Info("\"RunAct.cc->BeginOfRunAction works");
}

void RunAct::EndOfRunAction(const G4Run* aRun){
    Logger::Info("\"RunAct.cc->EndOfRunAction works");
}