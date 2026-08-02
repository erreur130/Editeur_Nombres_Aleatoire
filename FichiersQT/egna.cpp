#include "egna.h"

EGNA::EGNA(QVector<Module*> *modules_) {

}

EGNA::~EGNA(){

}

bool EGNA::charger(QString nomFichier){
    QFile fichier(nomFichier);

    if(fichier.open(QFile::ReadOnly | QFile::Text)){ // Si on arrive pas à ouvrir
        qDebug() << "Erreur" << fichier.errorString();
        return false;
    }

    QString text = fichier.readAll();

    /*truc pour charger et pour rénitialiser--------------------------------------------------------*/

    fichier.close();
    return true;
}

bool EGNA::sauvegarder(QString nomFichier) const {
    QFile fichier(nomFichier);
    if(!fichier.open(QFile::WriteOnly | QFile::Text)){ // Si on arrive pas à ouvrir
        qDebug() << "Erreur" << fichier.errorString();
        return false;
    }

    /*fichier.write(...); -------------------------------------------------------------------------------*/

    fichier.close();
    return true;
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