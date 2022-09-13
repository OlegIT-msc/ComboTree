#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "combotree.h"
#include "TreeNode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent*) override;

private:
    Ui::MainWindow *ui;

    ComboTree *CT = nullptr;
    TreeModel *Model = nullptr;
};
#endif // MAINWINDOW_H
