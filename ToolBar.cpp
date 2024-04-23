#include "MainWindow.h"
#include "ToolBar.h"
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOptionToolButton>
#include <QToolButton>
#include <QWindow>
#include <QtMath>

class SegmentedButton : public QWidget {
public:
    SegmentedButton(QWidget *parent = nullptr) : QWidget(parent) {
        mLayout = new QHBoxLayout(this);
    }

    void addButton(QAbstractButton *button) {
        mLayout->addWidget(button);
    }

private:
    QHBoxLayout *mLayout;
};

class CheckButton : public QToolButton {
public:
    CheckButton(QWidget *parent = nullptr) : QToolButton(parent) {}
    
    void paintEvent(QPaintEvent *event) override {
        QToolButton::paintEvent(event);

        QStyleOptionToolButton opt;
        initStyleOption(&opt);

        QPainter painter(this);
        painter.setPen(QPen(opt.palette.buttonText(), 1));
        painter.setRenderHint(QPainter::Antialiasing);

        qreal x = width() / 2.0;
        qreal y = height() / 2.0;

        QPainterPath path;
        path.moveTo(x - 1, y + 2);
        path.lineTo(x - 3, y - 1);
        path.lineTo(x - 7, y - 1);
        path.lineTo(x - 2, y + 6);
        path.lineTo(x + 1, y + 6);
        path.lineTo(x + 7, y - 6);
        path.lineTo(x + 3, y - 6);
        path.closeSubpath();

        if (window()->windowHandle()->devicePixelRatio() > 1.0) {
            painter.drawPath(path);
        } else {
            painter.fillPath(path, opt.palette.buttonText());
        }
    }
};

ToolBar::ToolBar(MainWindow *parent) : QToolBar(parent) {
    setMovable(false);

    SegmentedButton *segmentedButton = new SegmentedButton(this);
    addWidget(segmentedButton);

    mSegmentedButton = new CheckButton(segmentedButton);
    segmentedButton->addButton(mSegmentedButton);

    mNotSegmentedButton = new CheckButton(this);
    addWidget(mNotSegmentedButton);
}