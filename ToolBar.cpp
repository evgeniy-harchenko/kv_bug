#include "MainWindow.h"
#include "ToolBar.h"
#include "SearchField.h"
#include <QMenu>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOptionToolButton>
#include <QToolButton>
#include <QWindow>
#include <QtMath>

const int kButtonWidth = 36;
const int kButtonHeight = 24;

const QString kStyleSheet = "QToolButton {"
                            "  border-radius: 4px;"
                            "  padding: 0px 4px 0px 4px"
                            "}"
                            "QToolButton#first {"
                            "  border-top-right-radius: 0px;"
                            "  border-bottom-right-radius: 0px"
                            "}"
                            "QToolButton#middle {"
                            "  border-left: none;"
                            "  border-radius: 0px"
                            "}"
                            "QToolButton#last {"
                            "  border-left: none;"
                            "  border-top-left-radius: 0px;"
                            "  border-bottom-left-radius: 0px"
                            "}"
                            "QToolButton::menu-indicator {"
                            "  image: none"
                            "}"
                            "QToolButton::menu-button {"
                            "  border: none;"
                            "  width: 10px"
                            "}"
                            "QToolButton::menu-arrow {"
                            "  image: none"
                            "}";

class SegmentedButton : public QWidget {
public:
    SegmentedButton(QWidget *parent = nullptr) : QWidget(parent) {
        mLayout = new QHBoxLayout(this);
        mLayout->setContentsMargins(0, 0, 0, 0);
        mLayout->setSpacing(0);
    }

    void addButton(QAbstractButton *button, const QString &text = QString(),
                   bool checkable = false) {
        button->setCheckable(checkable);

        mLayout->addWidget(button);
        mButtons.addButton(button, mButtons.buttons().size());
    }

private:
    QHBoxLayout *mLayout;
    QButtonGroup mButtons;
};

class CheckButton : public QToolButton {
public:
    CheckButton(QWidget *parent = nullptr) : QToolButton(parent) {}

    QSize sizeHint() const override { return QSize(kButtonWidth, kButtonHeight); }

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

bool isCustom = true;

ToolBar::ToolBar(MainWindow *parent) : QToolBar(parent) {
    setMovable(false);
    setStyleSheet(kStyleSheet);

    QToolButton *flipButton = new QToolButton(this);
    flipButton->setStyleSheet("QToolButton {color: red;}");
    flipButton->setText("Flip Style");
    addWidget(flipButton);

    QToolButton *testNormalButton = new QToolButton(this);
    testNormalButton->setIcon(QIcon::fromTheme("window-symbolic"));
    testNormalButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    testNormalButton->setText("Test Normal Button");
    addWidget(testNormalButton);

    connect(flipButton, &QAbstractButton::clicked,
            [parent] {
                isCustom = !isCustom;
                parent->setToolBarStyleSheet(isCustom ? kStyleSheet : "");
                parent->toolBar()->mSearchField->updateStyleSheet(isCustom);
                parent->menuBar()->updateStyleSheet(isCustom);
            });

    SegmentedButton *historyButton = new SegmentedButton(this);
    addWidget(historyButton);

    mSegmentedButton = new CheckButton(historyButton);
    historyButton->addButton(mSegmentedButton);

    QMenu *prevMenu = new QMenu(mSegmentedButton);
    mSegmentedButton->setMenu(prevMenu);

    mNotSegmentedButton = new CheckButton(this);
    addWidget(mNotSegmentedButton);

    mSearchField = new SearchField(this);
    addWidget(mSearchField);
}