#ifndef TEST_TOOLBAR_H
#define TEST_TOOLBAR_H
#include <QAction>
#include <QToolBar>

class MainWindow;
class QToolButton;

class ToolBar : public QToolBar {

public:
    ToolBar(MainWindow *parent);

private:
    QToolButton *mSegmentedButton;

    QToolButton *mNotSegmentedButton;

    friend class MainWindow;
};
#endif //TEST_TOOLBAR_H
