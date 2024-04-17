#include <QApplication>
#include "buttoncolors.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    UI::buttoncolors ui;
    ui.show();
    return QApplication::exec();
}
