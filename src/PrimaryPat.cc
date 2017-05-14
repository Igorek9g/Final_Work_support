//
// Created by idalov on 10.05.17.
//

#include <PrimaryPat.hh>
#include <G4Gamma.hh>
#include <G4SystemOfUnits.hh>
#include <Logger.hh>

PrimaryPat::PrimaryPat() {
    gun = new G4ParticleGun(1);
    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
    Logger::Info("\"Primary particles generation actions\" have been built");
}

PrimaryPat::~PrimaryPat() {
    Logger::Info("\"Primary particles generation actions\" have been destroyed");
    delete gun;
}

void PrimaryPat::GeneratePrimaries(G4Event* anEvent){
    gun->SetParticleEnergy(0.661*MeV);
    gun->SetParticlePosition(G4ThreeVector(0,0,0));
    gun->SetParticleMomentumDirection(G4ThreeVector(0,1,0));
    gun->GeneratePrimaryVertex(anEvent);
}