#include <QDebug>
#include <QPainter>
#include <QStylePainter>
#include <QPaintEvent>

#include "combotree.h"
#include "TreeNode.h"

ComboTree::ComboTree(QWidget *parent) : QComboBox(parent),
    SkipHide(false),
    View(new QTreeView())
{
    StrSelect = QString();
    StrPaint = QString();

    View->setFrameShape(QFrame::NoFrame);
    View->setEditTriggers(QTreeView::NoEditTriggers);
    View->setAlternatingRowColors(false);
    View->setSelectionBehavior(QTreeView::SelectRows);
    View->setRootIsDecorated(true);
    View->setWordWrap(false);
    View->setAllColumnsShowFocus(true);
    View->setItemsExpandable(true);
    View->setHeaderHidden(true);

    setView(View.data());
}

ComboTree::~ComboTree()
{
}

void ComboTree::SetModel(TreeModel *M)
{
    setModel(M);
    connect(View->selectionModel(),
        SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)),
        this, SLOT(ItemSelection(const QItemSelection&,const QItemSelection&)));

    connect(View.data(),SIGNAL(expanded(const QModelIndex&)),this, SLOT(SHide(const QModelIndex&)));
    connect(View.data(),SIGNAL(collapsed(const QModelIndex&)),this, SLOT(SHide(const QModelIndex&)));

    connect(this,SIGNAL(currentIndexChanged(int)),this, SLOT(CurrentIndexChanged(int)));
}

void ComboTree::MoveResize(QPoint Pos,QSize Size)
{
    move(Pos);
    resize(Size);
}

void ComboTree::SHide(const QModelIndex&)
{
    SkipHide = true;
}

void ComboTree::CurrentIndexChanged(int)
{
    StrPaint = StrSelect;
}

void ComboTree::ItemSelection(const QItemSelection &, const QItemSelection &)
{
    QModelIndex IndSelect = View->selectionModel()->currentIndex();
    TreeNode *ChosenItem = static_cast<TreeModel*>(model())->getItem(IndSelect); // Выделенный объект

    StrSelect.clear();
    while (1)
    {
        StrSelect.prepend(ChosenItem->data(0).toString());
        ChosenItem = ChosenItem->parentItem();
        if (ChosenItem->parentItem() != nullptr)
            StrSelect.prepend(QString(" - "));
        else
            break;
    }
}

void ComboTree::paintEvent(QPaintEvent *)
{
    QStylePainter painter(this);

    // draw the combobox frame, focusrect and selected etc.
    QStyleOptionComboBox opt;
    this->initStyleOption(&opt);

    opt.currentText = StrPaint;

    painter.drawComplexControl(QStyle::CC_ComboBox, opt);

    // draw the icon and text
    painter.drawControl(QStyle::CE_ComboBoxLabel, opt);
}

void ComboTree::showPopup()
{
    setRootModelIndex(QModelIndex());
    QComboBox::showPopup();
}

void ComboTree::hidePopup()
{
    if (SkipHide == false)
    {
        setRootModelIndex(View->currentIndex().parent());
        setCurrentIndex(View->currentIndex().row());
        QComboBox::hidePopup();
    }
    SkipHide = false;
}

void ComboTree::hideColumn(int n)
{
    View->hideColumn(n);
}

void ComboTree::expandAll()
{
    View->expandAll();
    SkipHide = false;
}

void ComboTree::selectIndex(const QModelIndex &index)
{
    setRootModelIndex(index.parent());
    setCurrentIndex(index.row());
    View->setCurrentIndex(index);
}
