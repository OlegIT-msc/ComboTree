#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QScopedPointer>
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class TreeNode;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeModel(QObject* = nullptr);
    virtual ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    void AddItems(const QString&);
    TreeNode *getItem(const QModelIndex&) const;

private:
    void setupModelData(const QStringList &lines, TreeNode *parent);

private:
    QScopedPointer<TreeNode> rootItem;
};

#endif // TREEMODEL_H
