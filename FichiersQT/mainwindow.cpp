#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , modulesActif(new QVector<Module*>), modulesParDefaut(QVector<Module*>()), editeur(EGNA(modulesActif)), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::afficherStats() const {

}

void MainWindow::afficherListeModules() const {

}

void MainWindow::miseAJourMethonesActives() const {

}

void MainWindow::afficherBruit(){

}

