#include "listemodulestemplate.h"

ListeModulesTemplate::ListeModulesTemplate(QWidget* parent) : QListWidget(parent){}

void ListeModulesTemplate::startDrag(Qt::DropActions action){
    QListWidgetItem* item = currentItem();
    if (!item){
        qDebug() << "Impossiblilité de prendre cette objet !";
        return;
    }

    QMimeData* mime = new QMimeData;
    mime->setText(QString("%1;%2").arg(row(item)).arg(true)); // On donne la localisation de l'originale / on dit que ça vient de la liste de templates

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mime);
    drag->exec(action);
}

void ListeModulesTemplate::dropEvent(QDropEvent* event){

    // On lit les info qu'il contient
    QStringList parties = event->mimeData()->text().split(';'); //
    int idOrigine = parties[0].toInt();
    bool vientDeTemplate = parties[1].toInt();

    qDebug() << "Module à l'indice " << idOrigine << "vas dans Template ";
    emit envoyerSuprimerModule(idOrigine, vientDeTemplate);
}

void ListeModulesTemplate::dragEnterEvent(QDragEnterEvent* event) {
    event->acceptProposedAction();
    event->accept();
}

void ListeModulesTemplate::dragMoveEvent(QDragMoveEvent* event) {
    event->acceptProposedAction();
    event->accept();
}