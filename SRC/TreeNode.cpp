#include "TreeNode.h"

TreeNode::TreeNode(const QList<QVariant> &data, TreeNode *parent) :
    ParentItem(parent),
    NodeData(data)
{
}

TreeNode::~TreeNode()
{
    qDeleteAll(ChildItems);
}

void TreeNode::appendChild(TreeNode *item)
{
    ChildItems.append(item);
}

TreeNode *TreeNode::child(int row)
{
    if (row < 0 || row >= ChildItems.size())
        return nullptr;
    return ChildItems.at(row);
}

int TreeNode::childCount() const
{
    return ChildItems.count();
}

int TreeNode::columnCount() const
{
    return 1;
}

QVariant TreeNode::data(int column) const
{
    return NodeData.value(column);
}

int TreeNode::row() const
{
    if (ParentItem)
        return ParentItem->ChildItems.indexOf(const_cast<TreeNode*>(this));

    return 0;
}

TreeNode *TreeNode::parentItem()
{
    return ParentItem;
}

int TreeNode::childNumber() const
{
    if (ParentItem)
        return ParentItem->ChildItems.indexOf(const_cast<TreeNode*>(this));

    return 0;
}

