#include "MainWindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent,
                       Qt::WindowFlags flags)
        : QMainWindow(parent, flags),
          button(new QPushButton(this)){
    setAttribute(Qt::WA_DeleteOnClose);

    //button->setIcon(QIcon(QStringLiteral(":/icon.svg")));
    button->setIcon(QIcon::fromTheme(QStringLiteral("dialog-error")));
    button->setCheckable(true);
}
