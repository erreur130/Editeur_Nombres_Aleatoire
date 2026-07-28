#ifndef ROTATIONBITS_H
#define ROTATIONBITS_H

#include "module.h"

class RotationBits : public Module{
    Q_OBJECT
    unsigned char decalage;
public:
    RotationBits();
    ~RotationBits();
    uint64_t etatSuivant(uint64_t etat[2]) const ;
    Module* copie() const;
    QWidget* creerPaneauParametres() const;
    QWidget* creerBulleInfo() const;
    void sauvegarder(std::ostream &) const;

    inline void changerDecalage(unsigned char decalage_){decalage = decalage_;};
    inline unsigned char avoirDecalage(){return decalage;};
};

#endif // ROTATIONBITS_H
