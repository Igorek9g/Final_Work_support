//
// Created by student on 14.05.17.
//

#ifndef FINAL_RUNACT_HH
#define FINAL_RUNACT_HH

#include <G4UserRunAction.hh>

class RunAct: public G4UserRunAction{
public:
    RunAct();
    ~RunAct();

    G4Run* GenerateRun();
    void BeginOfRunAction(const G4Run* aRun);
    void EndOfRunAction(const G4Run* aRun);

};


#endif //FINAL_RUNACT_HH
