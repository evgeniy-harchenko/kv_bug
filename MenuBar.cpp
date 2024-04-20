#include <QMainWindow>
#include "MenuBar.h"

const QString kMenuBarStyle = "QMenuBar::item {"
                              "background-color: black;"
                              "}";


MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent) {
    QMenu *menu1 = addMenu(tr("menu1"));
    menu1->addAction("submenu1");
    menu1->addAction("submenu2");

    QMenu *menu2 = addMenu(tr("menu2"));
    menu2->addAction("submenu1");
    menu2->addAction("submenu2");

    QMenu *menu3 = addMenu(tr("menu3"));
    menu3->addAction("submenu1");
    menu3->addAction("submenu2");

    setStyleSheet(kMenuBarStyle);
}

void MenuBar::registerActions(QWidget *parent) const {
    parent->addActions(actions());
}

MenuBar *MenuBar::instance(QWidget *widget) {
    QMainWindow *window = qobject_cast<QMainWindow *>(widget->window());
    if (!window)
        return nullptr;

    if (!qobject_cast<MenuBar *>(window->menuBar()))
        window->setMenuBar(new MenuBar(window));

    return static_cast<MenuBar *>(window->menuBar());
}

void MenuBar::updateStyleSheet(bool isCustom) {
    setStyleSheet(isCustom ? kMenuBarStyle : "");
}
