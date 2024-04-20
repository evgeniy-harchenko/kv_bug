#ifndef TEST_MENUBAR_H
#define TEST_MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar {
Q_OBJECT

public:
    MenuBar(QWidget *parent);

    static MenuBar *instance(QWidget *widget);

    void registerActions(QWidget *parent) const;

    void updateStyleSheet(bool isCustom);
};
#endif //TEST_MENUBAR_H
