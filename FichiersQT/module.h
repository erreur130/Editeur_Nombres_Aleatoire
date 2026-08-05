#ifndef MODULE_H
#define MODULE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QFormLayout>
#include <QFile>

class Module : public QObject {
    public:
        explicit Module(QObject* parent);
        ~Module();
        virtual void valeurSuivante(uint64_t (&val)[2]) const = 0; // prend par référence
        virtual Module* copie() const = 0;
        virtual QWidget* creerPaneauParametres() = 0;
        virtual void sauvegarder(QFile &) const = 0;
        virtual QString avoirNom() const = 0;
};

#endif // MODULE_H
