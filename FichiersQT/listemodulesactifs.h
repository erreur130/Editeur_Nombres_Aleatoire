#ifndef LISTEMODULESACTIFS_H
#define LISTEMODULESACTIFS_H

#include <QListWidget>
#include <QDropEvent>
#include <QDrag>
#include <QMimeData>

class ListeModulesActifs : public QListWidget {
    Q_OBJECT
public:
    explicit ListeModulesActifs(QWidget* parent = nullptr);

protected:
    void dropEvent(QDropEvent* event) override;
    void startDrag(Qt::DropActions action) override;

    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;

signals:
    void envoyerIdModule(int idOrigine, int idCible, bool vientDeTemplate);
};

#endif // LISTEMODULESACTIFS_H
