#ifndef COMBOTREE_H
#define COMBOTREE_H

#include <QScopedPointer>
#include <QComboBox>
#include <QTreeView>
#include <QEvent>
#include <QPaintEvent>

#include "TreeModel.h"

class ComboTree : private QComboBox
{
    Q_OBJECT
public:
    explicit ComboTree(QWidget* = nullptr);
    virtual ~ComboTree();

public:
    void showPopup() override;
    void hidePopup() override;
    void hideColumn(int);
    void expandAll();
    void selectIndex(const QModelIndex &index);

    void SetModel(TreeModel*);
    void MoveResize(QPoint,QSize);

protected:
    void paintEvent(QPaintEvent*) override;

protected:
    bool SkipHide;
    QString StrSelect,StrPaint;
    QScopedPointer<QTreeView> View;

public slots:
    void ItemSelection(const QItemSelection &, const QItemSelection &);
    void SHide(const QModelIndex&);
    void CurrentIndexChanged(int index);

signals:

};

#endif // COMBOTREE_H
