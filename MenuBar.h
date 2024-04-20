#ifndef TEST_MENUBAR_H
#define TEST_MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar {
Q_OBJECT

public:
    MenuBar(QWidget *parent = nullptr);

    static MenuBar *instance(QWidget *widget);

    void registerActions(QWidget *parent) const;
};
#endif //TEST_MENUBAR_H
