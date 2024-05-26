#ifndef SIMPLETREEMODEL_MYQTREEVIEW_H
#define SIMPLETREEMODEL_MYQTREEVIEW_H


#include <QStyledItemDelegate>
#include <QTreeView>

class QLineEdit;

class MyQTreeView : public QTreeView
{
Q_OBJECT

public:
    explicit MyQTreeView(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *object, QEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

Q_SIGNALS:
    void entryChanged(const QString &name);

private:
    void renameSelectedEntry();
    void openEntryEditor(const QModelIndex &index);
    void closeEntryEditor();
    QModelIndex m_editorIndex;
    QLineEdit *m_entryEditor = nullptr;
};


#endif //SIMPLETREEMODEL_MYQTREEVIEW_H
