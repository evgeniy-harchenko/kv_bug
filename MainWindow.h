#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H
#include <QMainWindow>
#include "MenuBar.h"
#include "ToolBar.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,
               Qt::WindowFlags flags = Qt::WindowFlags());

    ToolBar *toolBar() const { return mToolBar; }
    MenuBar *menuBar() const { return mMenuBar; }

    void setToolBarStyleSheet(const QString style);

private:
    MenuBar *mMenuBar;
    ToolBar *mToolBar;
};
#endif //TEST_MAINWINDOW_H
