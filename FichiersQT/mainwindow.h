#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "egna.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT
    EGNA editeur;
    QVector<Module*> modulesActif;
    QVector<Module*> modulesParDefaut;

    void afficherStats();
    void afficherListeMethodes();
    void afficherBruit();
    //void spinBox_on_resolutionBruit_valueChanged(int value);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
