//
// Created by idalov on 10.05.17.
//

#ifndef FINAL_GEOMETRY_HH
#define FINAL_GEOMETRY_HH

#include <G4VUserDetectorConstruction.hh>
#include <G4Box.hh>
#include <G4NistManager.hh>
#include <G4SystemOfUnits.hh>
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "Mes.hh"

class Mes;
class Geometry: public G4VUserDetectorConstruction {
private:
    G4Box               *world;
    G4LogicalVolume     *world_log;
    G4VPhysicalVolume   *world_VP;

    G4NistManager*      nist;
    G4Material*         world_mat;
    virtual G4VPhysicalVolume *Construct();

    G4double det_H;
    Mes* detMes;
    G4Material* det_Mat;

public:
    Geometry();

    ~Geometry();
    void SetH (G4double newH);
    void SetMat (G4String newMat);
    void SetCol (G4String newCol);

};

#endif //FINAL_GEOMETRY_HH
