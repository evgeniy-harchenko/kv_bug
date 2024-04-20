#include "MainWindow.h"
#include "MenuBar.h"
#include "ToolBar.h"

MainWindow::MainWindow(QWidget *parent,
                       Qt::WindowFlags flags)
        : QMainWindow(parent, flags) {
    setAttribute(Qt::WA_DeleteOnClose);

    mMenuBar = new MenuBar(this);
    mMenuBar = MenuBar::instance(this);
    mMenuBar->registerActions(this);

    mToolBar = new ToolBar(this);
    addToolBar(Qt::TopToolBarArea, mToolBar);
}

void MainWindow::setToolBarStyleSheet(const QString style)
{
    mToolBar->setStyleSheet(style);
}