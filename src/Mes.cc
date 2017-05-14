//
// Created by student on 14.05.17.
//

#include <Mes.hh>
#include <Logger.hh>


Mes::Mes(Geometry* geom):detGeom(geom) {
    Logger::Info("\"Mes.cc\" works, command created");
    fDirectory = new G4UIdirectory (" !!!new_commands");

    change_H = new G4UIcmdWithADouble (" !!!new_commands/change_H", this);
    change_H->SetGuidance("/b/b/b/b/b/b/b");

    change_Mat = new G4UIcommand (" !!!new_commands/change_Mat", this);

   // change_Col = new G4UIcommand (" !!!new_commands/change_color", this);
    /*change_Mat->SetCandidates("G4_Fe");
    change_Mat->SetCandidates("G4_AIR");*/
}

void Mes::SetNewValue(G4UIcommand* cmd, G4String newvalue){
    Logger::Info("\"Mes.cc\"->cmd SetNewValue works");
    if (cmd == change_H)
        detGeom->SetH(change_H->GetNewDoubleValue(newvalue));
    if (cmd == change_Mat)
        detGeom->SetMat("G4_Fe");
       // detGeom->SetMat(change_Mat->GetCurrentValue());
        Logger::Info(" Material changed to-> smth");
    /*if (cmd == change_Col)
        detGeom->SetMat("G4_Fe");*/
}
