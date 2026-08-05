#include "listemodulesactifs.h"

ListeModulesActifs::ListeModulesActifs(QWidget* parent) : QListWidget(parent) {
    setAcceptDrops(true);
    setDragDropMode(QAbstractItemView::DragDrop);
}

void ListeModulesActifs::dropEvent(QDropEvent* event) {
    // code à finir ---------------------------------------------------------------------------------------------------
    event->acceptProposedAction();
}