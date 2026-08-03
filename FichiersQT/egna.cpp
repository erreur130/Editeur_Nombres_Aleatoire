#include "egna.h"

EGNA::EGNA(QVector<Module*> *modules_)
    : graine(uint64_t()), etat{uint64_t()}, modules(modules_){

    using namespace std::chrono;
    time_point<system_clock> now = system_clock::now();
    system_clock::duration temps = now.time_since_epoch();
    // Conversion duration -> nanoseconds -> uint64_t
    nanoseconds tempsNano = duration_cast<nanoseconds>(temps);
    graine = static_cast<uint64_t>(tempsNano.count());
}

EGNA::~EGNA(){}

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
    // cas vide
    if (modules->size() == 0){
        etat[0] = etat[1] = 255;
        return;
    }
    // cas non vide
    // on initalise l'etat avec la graine
    etat[0] = graine;
    etat[1] = -graine; // -graine est une valeur non signé, c'est juste pour faire une valeur différente
    for (qsizetype indice = 0; indice < modules->size(); indice++){ // On parcourt tout les modules
        modules->at(indice)->valeurSuivante(etat);
    }
}

uint8_t EGNA::suivantPixelBruit(){
    for (qsizetype indice = 0; indice < modules->size(); indice++){ // On parcourt tout les modules
        modules->at(indice)->valeurSuivante(etat);
    }
    return static_cast<uint8_t>(etat[0]); // le cast ne prend que les 8 derniers bits ce qui correspond à faire modulo 256
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