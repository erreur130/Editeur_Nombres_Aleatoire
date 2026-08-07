#include "listemodulesactifs.h"

ListeModulesActifs::ListeModulesActifs(QWidget* parent) : QListWidget(parent){}

void ListeModulesActifs::dropEvent(QDropEvent* event){
    // on calcule l'indice où mettre de nouvelle item, on regarde où on le met par raport à ce qui à dessous
    QPoint position = event->position().toPoint();
    QListWidgetItem* itemSousLeCurseur = itemAt(position);
    int idCible;
    if (itemSousLeCurseur) {
        idCible = row(itemSousLeCurseur);
        // son vérifie si on est dans la moitié haute ou basse de l'item
        QRect rect = visualItemRect(itemSousLeCurseur);
        if (position.y() > rect.center().y()) {
            idCible++;
        }
    } else {
        idCible = count(); // aucun item sous le curseur = on droppe à la fin de la liste
    }

    // On lit les info qu'il contient
    QStringList parties = event->mimeData()->text().split(';'); //
    int idOrigine = parties[0].toInt();
    bool vientDeTemplate = parties[1].toInt();

    qDebug() << "Module à l'indice " << idOrigine << "vas à l'indice " << idCible;
    emit envoyerIdModule(idOrigine, idCible, vientDeTemplate);
}

void ListeModulesActifs::startDrag(Qt::DropActions action){
    QListWidgetItem* item = currentItem();
    if (!item){
        qDebug() << "Impossiblilité de prendre cette objet !";
        return;
    }

    QMimeData* mime = new QMimeData;
    mime->setText(QString("%1;%2").arg(row(item)).arg(false)); // On donne la localisation de l'originale / on dit que ça ne vient pas de la liste de templates

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mime);
    drag->exec(action);
}

void ListeModulesActifs::dragEnterEvent(QDragEnterEvent* event) {
    event->acceptProposedAction();
    event->accept();
}

void ListeModulesActifs::dragMoveEvent(QDragMoveEvent* event) {
    event->acceptProposedAction();
    event->accept();
}