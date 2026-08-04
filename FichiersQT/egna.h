#ifndef EGNA_H
#define EGNA_H

#include "module.h"
#include <QFile>

class EGNA{
    uint64_t graine;
    uint64_t etat[2];
    QVector<Module*> *modules;
    double moyenne;
    double cv;
    double uniformite;
    double autoCorrelation;
    double equilibleBits;
    int nbValeursActuel;
    int nbValeursTotale;

public:
    EGNA(QVector<Module*>*);
    ~EGNA();

    bool charger(QString nomFichier);
    bool sauvegarder(QString nomFichier) const;
    void renitialiserEtat();
    inline uint64_t avoirGraine() const {return graine;};
    inline void changerGraine(uint64_t graine_){graine = graine_;};
    inline void changerNbValeursTotale(int nbValeursTotale_){nbValeursTotale = nbValeursTotale_;};

    uint8_t suivantPixelBruit();
    inline double avoirMoyenne() const {return moyenne;};
    inline double avoirCV() const {return cv;};
    inline double avoirUniformite() const {return uniformite;};
    inline double avoirAutocorrelation() const {return autoCorrelation;};
    inline double avoirEquilibreBits() const {return equilibleBits;};

private :
    void calculeMoyenne();
    void calculeCV();
    void calculeUniformite();
    void calculeAutocorrelation();
    void calculeEquilibreBits();
};

#endif // EGNA_H
