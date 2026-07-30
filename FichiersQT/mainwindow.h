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
    QVector<Module*> *modulesActif;
    QVector<Module*> modulesParDefaut;
    EGNA editeur;

    void afficherStats() const;
    void afficherListeModules() const;
    void miseAJourMethonesActives() const;
    void afficherBruit();
    //void spinBox_on_resolutionBruit_valueChanged(int value);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionModules_triggered();
    void on_actionTests_triggered();

    void on_spinBoxResolution_valueChanged(int arg1);

    void on_spinBoxGraine_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
protected:
    void resizeEvent(QResizeEvent *event) override;
};
#endif // MAINWINDOW_H
