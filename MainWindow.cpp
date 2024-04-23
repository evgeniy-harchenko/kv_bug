#include "MainWindow.h"
#include "ToolBar.h"

MainWindow::MainWindow(QWidget *parent,
                       Qt::WindowFlags flags)
        : QMainWindow(parent, flags) {
    setAttribute(Qt::WA_DeleteOnClose);

    mToolBar = new ToolBar(this);
    addToolBar(Qt::TopToolBarArea, mToolBar);
}