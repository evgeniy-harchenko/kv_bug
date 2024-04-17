#include <QMainWindow>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QTableWidget>

namespace UI {
    QT_BEGIN_NAMESPACE
    namespace Ui { class buttoncolors; }
    QT_END_NAMESPACE

    class buttoncolors : public QMainWindow {
    Q_OBJECT

    public:
        explicit buttoncolors(QWidget *parent = nullptr);

        ~buttoncolors() override;

    private:
        Ui::buttoncolors *ui;

        void generateTableCells(QTableWidget *table);
    };
} // UI

