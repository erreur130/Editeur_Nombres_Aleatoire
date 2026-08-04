#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_aideModules.h"
#include "ui_aideTests.h"
#include "ui_infoProjet.h"
#include "demandenomclasse.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , modulesActif(new QVector<Module*>), modulesParDefaut(QVector<Module*>()), editeur(EGNA(modulesActif)), ui(new Ui::MainWindow){
    ui->setupUi(this);

    // Initialiser l'image avec 1px blanc
    QImage image(1, 1, QImage::Format_Indexed8);
    QVector<QRgb> colorTable(255);
    colorTable[0] = qRgb(255, 255, 255);
    image.fill(0);
    image.setColorTable(colorTable);
    ui->imageBruit->setPixmap(QPixmap::fromImage(image));

    // On limite les valeurs possible à mettre dans le QLineEdite pour la graine (hexadécimale)
    ui->textGraine->setValidator(new QRegularExpressionValidator(QRegularExpression("^0x[0-9A-Fa-f]{1,16}$"), ui->textGraine));
    // On met la graine en visuel
    ui->textGraine->setText("0x" + QString::number(editeur.avoirGraine(), 16));

    // On met le nb valeur en visuel (par défaut c'est 256*256)
    ui->labelNbValeurs->setText(QString::number(ui->spinBoxResolution->value() * ui->spinBoxResolution->value()));

    // On remplie la liste des templates
    modulesParDefaut.push_back(new RotationBits(this, 5));
    /* ...----------------------------------------------------------------------------------------------------------------------------------------------------------*/
    afficherListeModules();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event); //pour conserver le comportement par défaut

    // le rezise de l'image carré / singleShot() pour que le layout ait le temps de s'update
    QTimer::singleShot(0, this, [this](){
        int tailleMin = qMin(ui->layoutImage->geometry().height(),ui->layoutImage->geometry().width());
        ui->imageBruit->setFixedSize(QSize(tailleMin - 10, tailleMin - 10));
    });
}

void MainWindow::afficherStats(bool vider) const {
    if (vider){ // affichage par défaut
        ui->labelAquilibreBits->setText("---");
        ui->labelMoyenne->setText("---");
        ui->labelCV->setText("---");
        ui->labelUniformite->setText("---");
        ui->labelCorrelation->setText("---");
    } else {
        ui->labelAquilibreBits->setText(QString::number(editeur.avoirEquilibreBits()));
        ui->labelMoyenne->setText(QString::number(editeur.avoirMoyenne()));
        ui->labelCV->setText(QString::number(editeur.avoirCV()));
        ui->labelUniformite->setText(QString::number(editeur.avoirUniformite()));
        ui->labelCorrelation->setText(QString::number(editeur.avoirAutocorrelation()));
    }
}

void MainWindow::afficherListeModules() const {
    ui->listModulesTemplate->clear();
    for (Module* module : modulesParDefaut){
        QWidget *widget = module->creerPaneauParametres(); // on créé le widget (le new est dans la fonction)

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(widget->sizeHint()); // On définit la taille qu'il prendra dans la liste

        ui->listModulesTemplate->addItem(item); // on met la taille
        ui->listModulesTemplate->setItemWidget(item, widget); // on met le widget

        // Rajout du séparateur
        QListWidgetItem* separateur = new QListWidgetItem();
        separateur->setFlags(Qt::NoItemFlags); // non sélectionnable, non cliquable
        separateur->setSizeHint(QSize(0,1)); // hauteur réservée pour la ligne, largeur auto
        QFrame* ligne = new QFrame();
        ligne->setFrameShape(QFrame::HLine);
        ligne->setFrameShadow(QFrame::Sunken);
        ui->listModulesTemplate->addItem(separateur); // on met la taille
        ui->listModulesTemplate->setItemWidget(separateur, ligne); // on met le séparateur
    }
}

void MainWindow::miseAJourMethodesActives() const {
    ui->listModulesActifs->clear();
    for (Module* module : modulesParDefaut){
        QWidget *widget = new QWidget(module->creerPaneauParametres()); // on créé le widget

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(widget->sizeHint()); // On définit la taille qu'il prendra dans la liste

        ui->listModulesActifs->addItem(item); // on met la taille
        ui->listModulesActifs->setItemWidget(item, widget); // on met le widget
    }
}

void MainWindow::afficherBruit(){
    ui->imageBruit->clear();

    int resolution = ui->spinBoxResolution->value();
    QImage image(resolution, resolution, QImage::Format_Indexed8);

    // Initialiser la palette
    QVector<QRgb> colorTable(256);
    for (int i = 0; i < 256; ++i) colorTable[i] = qRgb(i, i, i);
    image.setColorTable(colorTable);

    // création de l'image
    for (int y = 0; y < resolution; ++y) {
        for (int x = 0; x < resolution; ++x) {
            unsigned char gris = editeur.suivantPixelBruit(); // nouvelle couleur généré
            image.setPixel(x, y, gris);
        }
    }

    // Affichage de l'image dans le label
    ui->imageBruit->setPixmap(QPixmap::fromImage(image));
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

void MainWindow::on_actionInfo_Projet_triggered(){
    QDialog *fenetre = new QDialog();
    Ui::InfoProjet ui;
    ui.setupUi(fenetre);
    fenetre->setWindowFlags(Qt::Window);  // force que ce soit une fenêtre indépendante
    fenetre->setWindowTitle(" ");
    fenetre->show();
}

void MainWindow::on_actionSauvegarder_sous_triggered(){
    QString nomFichier;

    // demande à l'utilisateur le nom du ficher à créé
    DemandeNomClasse *fenetre = new DemandeNomClasse(this);
    connect(fenetre, SIGNAL(envoyerNomClasse(QString)), this, SLOT(recevoirNomClasse(QString)));
    fenetre->setWindowTitle(" ");
    fenetre->exec(); // bloque la fenetre

    // en attente d'une réponse ou non (recevoirNomClasse() est la suite)
}

void MainWindow::on_actionCharger_triggered(){
    QString nomFichier = QFileDialog::getOpenFileName( // permet de chercher un fichier
        0,
        "Gestionaire des fichiers",
        "/home",
        "Fichiers spéciaux (*.txt)"); // format txt à modifier si nésésaire ----------------------------------------------------------------------------------------------

    if(nomFichier != ""){ // Si il existe on charge les données, puis le visuel
        editeur.charger(nomFichier);

        // update
        if (modulesActif->size() > 0){ // Si nésésaire
            miseAJourMethodesActives();
            afficherBruit();
            afficherStats(true);
        } else {
            afficherStats();
        }
    }
}

void MainWindow::on_spinBoxResolution_valueChanged(int val){
    ui->labelNbValeurs->setText(QString::number(ui->spinBoxResolution->value() * ui->spinBoxResolution->value()));
    // update
    if (modulesActif->size() > 0){ // Si nésésaire
        editeur.changerNbValeursTotale(val);
        editeur.renitialiserEtat();
        afficherBruit();
        afficherStats(true);
    } else {
        afficherStats();
    }
}

void MainWindow::recevoirNomClasse(QString nomClasse){
    if(nomClasse != "")
        editeur.sauvegarder(nomClasse);
}

void MainWindow::on_textGraine_editingFinished(){
    // change la graine
    bool ok;
    uint64_t valeur = ui->textGraine->text().toULongLong(&ok, 16); // base 16 (hexadécimale)
    if (ok){
        qDebug() << "Graine changer";
        editeur.changerGraine(valeur);

        // update
        if (modulesActif->size() > 0){ // Si nésésaire
            editeur.renitialiserEtat();
            afficherBruit();
            afficherStats(true);
        } else {
            afficherStats();
        }
    } else
        qDebug() << "Graine non changer";
}

