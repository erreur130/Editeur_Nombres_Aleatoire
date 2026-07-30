#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_aideModules.h"
#include "ui_aideTests.h"
#include "ui_infoProjet.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , modulesActif(new QVector<Module*>), modulesParDefaut(QVector<Module*>()), editeur(EGNA(modulesActif)), ui(new Ui::MainWindow){
    ui->setupUi(this);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event); //pour conserver le comportement par défaut

    // le rezise de l'image carré
    static bool estTest = true;
    int tailleMin = (ui->layoutImage->geometry().height() < ui->layoutImage->geometry().width()) ? ui->layoutImage->geometry().height() : ui->layoutImage->geometry().width();
    ui->imageBruit->setFixedSize(QSize(estTest?118:tailleMin-10, estTest?118:tailleMin-10));
    estTest = false;

}
void MainWindow::afficherStats() const {

}

void MainWindow::afficherListeModules() const {

}

void MainWindow::miseAJourMethonesActives() const {

}

void MainWindow::afficherBruit(){

}

void MainWindow::on_actionModules_triggered(){
    QDialog *fenetre = new QDialog();
    Ui::AideModules ui;
    ui.setupUi(fenetre);
    fenetre->setWindowFlags(Qt::Window);  // force que ce soit une fenêtre indépendante
    fenetre->setWindowTitle(" ");
    fenetre->show();
}

void MainWindow::on_actionTests_triggered(){
    QDialog *fenetre = new QDialog();
    Ui::AideTests ui;
    ui.setupUi(fenetre);
    fenetre->setWindowFlags(Qt::Window);  // force que ce soit une fenêtre indépendante
    fenetre->setWindowTitle(" ");
    fenetre->show();
}


void MainWindow::on_spinBoxResolution_valueChanged(int arg1){

}


void MainWindow::on_spinBoxGraine_valueChanged(int arg1){

}

