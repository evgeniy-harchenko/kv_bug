#ifndef TEST_SEARCHFIELD_H
#define TEST_SEARCHFIELD_H

#include <QLineEdit>

class QResizeEvent;
class QToolButton;

class SearchField : public QLineEdit {
Q_OBJECT

public:
    SearchField(QWidget *parent = nullptr);

    QSize sizeHint() const override;

    void updateStyleSheet(bool isCustom);

protected:
    void resizeEvent(QResizeEvent *) override;

private:
    QToolButton *mClearButton;
    QToolButton *mAdvancedButton = nullptr;
};

#endif //TEST_SEARCHFIELD_H
