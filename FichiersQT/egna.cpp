#include "egna.h"

EGNA::EGNA(QVector<Module*> *modules_)
    : graine(uint64_t()), etat{uint64_t()}, modules(modules_), moyenne(0), cv(0), uniformite(0), autoCorrelation(0), equilibleBits(0), nbValeursActuel(0), nbValeursTotale(256*256){

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
    nbValeursActuel = 0; // renitialise le compteur
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
    // calcule de l'état
    for (qsizetype indice = 0; indice < modules->size(); indice++){ // On parcourt tout les modules
        modules->at(indice)->valeurSuivante(etat);
    }

    // calcule des stats sur l'état
    nbValeursActuel++; // fait commencé à 1
    calculeMoyenne();
    calculeCV();
    calculeUniformite();
    calculeEquilibreBits();

    return static_cast<uint8_t>(etat[0]); // le cast ne prend que les 8 derniers bits ce qui correspond à faire modulo 256
}

void EGNA::calculeMoyenne(){
    // nbValeursActuel commence à 1
    if (nbValeursActuel == 1){ // pour initialiser
        // prend les 53 bits de poids fort de etat[0] et les divise par 2^53
        moyenne = static_cast<double>(etat[0] >> 11) / (1ULL << 53);
    } else {
        // moyene = ( (MoyTotal*nbValsTotalAvant) + (1autreMoy*1) ) / (nbVals)
        moyenne = ( (moyenne*(nbValeursActuel-1)) + static_cast<double>(etat[0] >> 11) / (1ULL << 53) ) / nbValeursActuel;
    }
}

void EGNA::calculeCV(){
    if (moyenne != 0){
        /* // à aprofondire
        double variance = m2 / nbValeursActuel; // variance
        double ecartType = std::sqrt(variance);
        cv = ecartType / moyenne;   // coefficient de variation
        */
    } else
        qDebug() << "moyenne == 0 !";
}

void EGNA::calculeUniformite(){

}

void EGNA::calculeAutocorrelation(){

}

void EGNA::calculeEquilibreBits(){

}