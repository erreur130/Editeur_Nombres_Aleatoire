#ifndef EGNA_H
#define EGNA_H

#include "module.h"

class EGNA{
    uint64_t graine;
    uint64_t etat[2];
    QVector<Module*> modules;
public:
    EGNA();
    ~EGNA();

    void charger(QString fichier);
    void sauvegarder(QString fichier);
    void renitialiserEtat();
    inline void changerGraine(uint64_t graine_){graine = graine_;};

    unsigned char suivantPixelBruit();
    double calculeMoyenne(int nbTirages);
    double calculeVariance(int nbTirages);
    double calculeEcartType(int nbTirages);
    double calculeMediane(int nbTirages);
    double calculeUniformite(int nbTirages);
    double calculeAutocorrelation(int nbTirages);
    double calculeEquilibreBits(int nbTirages);
};

#endif // EGNA_H
