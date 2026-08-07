#ifndef LISTEMODULESTEMPLATE_H
#define LISTEMODULESTEMPLATE_H

#include <QListWidget>
#include <QDrag>
#include <QMimeData>
#include <QDropEvent>

class ListeModulesTemplate : public QListWidget {
    Q_OBJECT
public:
    explicit ListeModulesTemplate(QWidget* parent = nullptr);

protected:
    void startDrag(Qt::DropActions action) override;
    void dropEvent(QDropEvent* event) override;

    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;

signals:
    void envoyerSuprimerModule(int idOrigine, bool vientDeTemplate);
};

#endif // LISTEMODULESTEMPLATE_H
