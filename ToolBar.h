#ifndef TEST_TOOLBAR_H
#define TEST_TOOLBAR_H
#include <QAction>
#include <QToolBar>

class MainWindow;
class SearchField;
class QToolButton;

class ToolBar : public QToolBar {

public:
    ToolBar(MainWindow *parent);

private:
    QToolButton *mSegmentedButton;

    QToolButton *mNotSegmentedButton;

    SearchField *mSearchField;

    friend class MainWindow;
};
#endif //TEST_TOOLBAR_H
