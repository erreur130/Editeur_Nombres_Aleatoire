#ifndef MODULE_H
#define MODULE_H

#include <QWidget>

class Module : public QObject {
    public:
        Module();
        ~Module();
        virtual uint64_t etatSuivant(uint64_t etat[2]) const = 0;
        virtual Module* copie() const = 0;
        virtual QWidget* creerPaneauParametres() const = 0;
        virtual QWidget* creerBulleInfo() const = 0;
        virtual void sauvegarder(std::ostream &) const = 0;
};

#endif // MODULE_H
