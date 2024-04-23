#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H
#include <QMainWindow>
#include "ToolBar.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,
               Qt::WindowFlags flags = Qt::WindowFlags());

private:
    ToolBar *mToolBar;
};
#endif //TEST_MAINWINDOW_H
