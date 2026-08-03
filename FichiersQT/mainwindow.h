#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "egna.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT
    QVector<Module*> *modulesActif;
    QVector<Module*> modulesParDefaut;
    EGNA editeur;

    void afficherStats() const;
    void afficherListeModules() const;
    void miseAJourMethodesActives() const;
    void afficherBruit();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionModules_triggered();
    void on_actionTests_triggered();
    void on_actionSauvegarder_sous_triggered();
    void on_actionCharger_triggered();
    void on_actionInfo_Projet_triggered();
    void on_spinBoxResolution_valueChanged(int arg1);
    void on_textGraine_editingFinished();

public slots:
    void recevoirNomClasse(QString);

private:
    Ui::MainWindow *ui;
protected:
    void resizeEvent(QResizeEvent *event) override;
};
#endif // MAINWINDOW_H
