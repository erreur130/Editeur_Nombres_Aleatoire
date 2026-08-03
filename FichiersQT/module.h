#ifndef MODULE_H
#define MODULE_H

#include <QWidget>

class Module : public QObject {
    public:
        explicit Module(QObject* parent);
        ~Module();
        virtual void valeurSuivante(uint64_t (&val)[2]) const = 0; // prend par référence
        virtual Module* copie() const = 0;
        virtual QWidget* creerPaneauParametres() const = 0;
        virtual void sauvegarder(std::ostream &) const = 0;
};

#endif // MODULE_H
