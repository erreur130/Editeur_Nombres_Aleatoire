#ifndef ROTATIONBITS_H
#define ROTATIONBITS_H

#include "module.h"

class RotationBits : public Module{
    Q_OBJECT
    uint8_t decalage;
public:
    RotationBits(QObject*, uint8_t = 1);
    ~RotationBits();
    void valeurSuivante(uint64_t (&val)[2]) const ;
    Module* copie() const;
    QWidget* creerPaneauParametres();
    void sauvegarder(QFile &) const;
    QString avoirNom() const;

    inline void changerDecalage(uint8_t decalage_){decalage = decalage_;};
    inline uint8_t avoirDecalage() const {return decalage;};
};

#endif // ROTATIONBITS_H
