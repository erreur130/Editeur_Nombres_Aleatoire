#ifndef EGNA_H
#define EGNA_H

#include "module.h"
#include <QFile>

class EGNA{
    uint64_t graine;
    uint64_t etat[2];
    QVector<Module*> *modules;
public:
    EGNA(QVector<Module*>*);
    ~EGNA();

    bool charger(QString nomFichier);
    bool sauvegarder(QString nomFichier) const;
    void renitialiserEtat();
    inline void changerGraine(uint64_t graine_){graine = graine_;};

    unsigned char suivantPixelBruit();
    double calculeMoyenne(int nbTirages) const;
    double calculeCV(int nbTirages) const;
    double calculeMediane(int nbTirages) const;
    double calculeUniformite(int nbTirages) const;
    double calculeAutocorrelation(int nbTirages) const;
    double calculeEquilibreBits(int nbTirages) const;
};

#endif // EGNA_H
