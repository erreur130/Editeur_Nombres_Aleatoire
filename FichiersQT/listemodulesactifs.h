#ifndef LISTEMODULESACTIFS_H
#define LISTEMODULESACTIFS_H

#include <QListWidget>
#include <QDropEvent>

class ListeModulesActifs : public QListWidget {
    Q_OBJECT
public:
    explicit ListeModulesActifs(QWidget* parent = nullptr);

protected:
    void dropEvent(QDropEvent* event) override;
};

#endif // LISTEMODULESACTIFS_H
