//
// Created by idalov on 10.05.17.
//

#include <Geometry.hh>
#include <G4PVPlacement.hh>
#include <Logger.hh>
#include <G4Tubs.hh>
#include <G4GeometryManager.hh>
#include <G4SolidStore.hh>
#include <G4RunManager.hh>
#include <G4UImanager.hh>
#include <G4Color.hh>

Geometry::Geometry(){

    nist = G4NistManager::Instance();
    world_mat = nist->FindOrBuildMaterial("G4_AIR");

    det_H=20;

    Logger::Info("\"Geometry\" have been built");
    detMes =new Mes(this);

}

Geometry::~Geometry(){
    delete detMes;
    delete world;
    delete world_log;
    delete world_VP;
    Logger::Info("\"Geometry\" have been destroyed");
}
G4VPhysicalVolume* Geometry::Construct() {
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();


    G4double size = 50*m;
    world = new G4Box("world", size/2., size/2.,size/2.);
    world_log = new G4LogicalVolume(world, world_mat, "world_log");
    world_VP = new G4PVPlacement(0,G4ThreeVector(),world_log,"world_PV",0,false,0);

    det_Mat = nist->FindOrBuildMaterial("G4_WATER");
    G4Tubs* det=new G4Tubs("det", 0, 100, det_H, 0, 360*deg);
    G4LogicalVolume* det_log= new G4LogicalVolume(det, det_Mat, "det_log");

    //G4VisAttributes* Clr = new G4VisAttributes (G4Colour::Black());
   // det_log->SetVisAttributes(Clr);

    new G4PVPlacement (0, G4ThreeVector (), det_log, "ded_PVP", world_log, false,0);

    return world_VP;
}

void Geometry::SetH (G4double newH){
    det_H = newH;
    Logger::Info("\"Messenger: New_H = ", det_H);
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
    G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");

}

void Geometry::SetMat (G4String newMat){
    det_Mat = nist->FindOrBuildMaterial(newMat);
    Logger::Info("\"Messenger: New_Mat = " + det_Mat->GetName());
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
    G4UImanager::GetUIpointer()->ApplyCommand("/vis/geometry/set/visibility world_log 0 false");

}