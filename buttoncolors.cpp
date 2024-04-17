#include "buttoncolors.h"
#include "ui_buttoncolors.h"

namespace UI {
    buttoncolors::buttoncolors(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::buttoncolors) {
        ui->setupUi(this);
        generateTableCells(ui->overrideColorTableActive);
    }

    buttoncolors::~buttoncolors() {
        delete ui;
    }

    void buttoncolors::generateTableCells(QTableWidget *table)
    {
        int numRows = 5;

        for (int rowIndex = 0; rowIndex < numRows; rowIndex++) {
            QTableWidgetItem *verticalHeaderItem = new QTableWidgetItem();
            table->insertRow(rowIndex);
            table->setVerticalHeaderItem(rowIndex, verticalHeaderItem);
        }

        QString activeString = (table == ui->overrideColorTableActive) ? QStringLiteral("Active") : QStringLiteral("Inactive");

        for (int columnIndex = 0; columnIndex < numRows; columnIndex++) {
            table->insertColumn(columnIndex);
            QString columnName = "Column " + columnIndex;
            for (int rowIndex = 0; rowIndex < numRows; rowIndex++) {
                QString rowName = "" + rowIndex;
                QVBoxLayout *vlayout = new QVBoxLayout();
                QCheckBox *checkBox = new QCheckBox();
                vlayout->addWidget(checkBox);
                vlayout->addStretch();
                QWidget *w = new QWidget();
                w->setLayout(vlayout);
                table->setCellWidget(rowIndex, columnIndex, w);
            }
        }
    }
}
