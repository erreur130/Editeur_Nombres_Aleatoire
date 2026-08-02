#include "demandenomclasse.h"
#include "ui_demandenomclasse.h"

DemandeNomClasse::DemandeNomClasse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DemandeNomClasse)
{
    ui->setupUi(this);
}

DemandeNomClasse::~DemandeNomClasse()
{
    delete ui;
}

void DemandeNomClasse::on_pushButton_clicked(){
    emit envoyerNomClasse(ui->textNom->text());
    close();
}

