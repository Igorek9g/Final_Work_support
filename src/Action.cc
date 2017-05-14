//
// Created by idalov on 10.05.17.
//

#include <Action.hh>
#include <PrimaryPat.hh>
#include <EventAct.hh>
#include <Logger.hh>
#include <RunAct.hh>

Action::Action(){
    Logger::Info("\"General actions\" have been built");
}

Action::~Action(){
    Logger::Info("\"General actions\" have been destroyed");
}

void Action::Build()const {
    Logger::Info("\"Action.cc->Action::Build working");

    SetUserAction(new RunAct);
    SetUserAction(new PrimaryPat);
    SetUserAction(new EventAct);
}