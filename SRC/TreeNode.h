#ifndef TREENODE_H
#define TREENODE_H

#include <QVariant>
#include <QList>

class TreeNode
{
public:
    explicit TreeNode(const QList<QVariant>&, TreeNode* = nullptr);
    virtual ~TreeNode();

    void appendChild(TreeNode*);

    TreeNode *child(int);
    int childCount() const;
    int columnCount() const;
    QVariant data(int) const;
    int row() const;
    TreeNode *parentItem();
    int childNumber() const;

private:
    QList<TreeNode*> ChildItems;
    TreeNode *ParentItem;
    QList<QVariant> NodeData;
};

#endif // TREENODE_H
