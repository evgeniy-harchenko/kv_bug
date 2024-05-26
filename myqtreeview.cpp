#include "myqtreeview.h"

#include <QHeaderView>
#include <QLineEdit>
#include <QMimeData>
#include <QMouseEvent>

MyQTreeView::MyQTreeView(QWidget *parent)
        : QTreeView(parent) {
}

bool MyQTreeView::eventFilter(QObject *object, QEvent *event) {
    if (object == m_entryEditor && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Escape) {
            closeEntryEditor();
            return true;
        }
    }
    return false;
}

void MyQTreeView::mouseReleaseEvent(QMouseEvent *event) {
    if (m_editorIndex.isValid()) {
        closeEntryEditor();
    } else {
        QTreeView::mouseReleaseEvent(event);
    }
}

void MyQTreeView::keyPressEvent(QKeyEvent *event) {
    if (m_editorIndex.isValid()) {
        switch (event->key()) {
            case Qt::Key_Return:
            case Qt::Key_Enter: {
                QLineEdit *editor = static_cast<QLineEdit *>(indexWidget(m_editorIndex));
                Q_EMIT entryChanged(editor->text());
                closeEntryEditor();
                break;
            }
            default:
                QTreeView::keyPressEvent(event);
        }
    } else if (event->key() == Qt::Key_F2) {
        renameSelectedEntry();
    } else {
        QTreeView::keyPressEvent(event);
    }
}

void MyQTreeView::renameSelectedEntry() {
    QModelIndex currentIndex = selectionModel()->currentIndex();
    currentIndex = (currentIndex.parent().isValid()) ? currentIndex.parent().model()->index(currentIndex.row(), 0,
                                                                                            currentIndex.parent())
                                                     : model()->index(currentIndex.row(), 0);
    openEntryEditor(currentIndex);
}

void MyQTreeView::openEntryEditor(const QModelIndex &index) {
    m_editorIndex = index;
    openPersistentEditor(index);
    m_entryEditor = static_cast<QLineEdit *>(indexWidget(m_editorIndex));
    m_entryEditor->installEventFilter(this);
    m_entryEditor->setText(index.data().toString());
    m_entryEditor->setFocus(Qt::OtherFocusReason);
    m_entryEditor->selectAll();
}

void MyQTreeView::closeEntryEditor() {
    m_entryEditor->removeEventFilter(this);
    closePersistentEditor(m_editorIndex);
    m_editorIndex = QModelIndex();
}

#include "moc_myqtreeview.cpp"

