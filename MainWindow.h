#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H
#include <QMainWindow>

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,
               Qt::WindowFlags flags = Qt::WindowFlags());

    class QPushButton *const button;
};
#endif //TEST_MAINWINDOW_H
