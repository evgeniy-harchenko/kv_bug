#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H
#include <QMainWindow>

class ToolBar;
class MenuBar;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,
               Qt::WindowFlags flags = Qt::WindowFlags());

    ToolBar *toolBar() const { return mToolBar; }

    void setToolBarStyleSheet(const QString style);

private:
    ToolBar *mToolBar;
    MenuBar *mMenuBar;
};
#endif //TEST_MAINWINDOW_H
