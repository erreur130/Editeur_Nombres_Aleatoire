#include "egna.h"

EGNA::EGNA(QVector<Module*> *modules_) {

}

EGNA::~EGNA(){

}

void EGNA::charger(QString fichier){

}

void EGNA::sauvegarder(QString fichier) const {

}

void EGNA::renitialiserEtat(){

}

unsigned char EGNA::suivantPixelBruit(){
    return 155; // pour tester
}

double EGNA::calculeMoyenne(int nbTirages) const {

}

double EGNA::calculeCV(int nbTirages) const {

}

double EGNA::calculeMediane(int nbTirages) const {

}

double EGNA::calculeUniformite(int nbTirages) const {

}

double EGNA::calculeAutocorrelation(int nbTirages) const {

}

double EGNA::calculeEquilibreBits(int nbTirages) const {

}