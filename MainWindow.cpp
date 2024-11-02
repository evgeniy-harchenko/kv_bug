#include "MainWindow.h"
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent,
                       Qt::WindowFlags flags)
        : QMainWindow(parent, flags),
          button(new QToolButton(this)){
    setAttribute(Qt::WA_DeleteOnClose);

    //button->setIcon(QIcon(QStringLiteral(":/icon.svg")));
    button->setIcon(QIcon::fromTheme(QStringLiteral("dialog-error")));
    button->setCheckable(true);
}
