#ifndef CLIPBOARDWIDGET_H
#define CLIPBOARDWIDGET_H

#include <QWidget>
#include <QClipboard>
#include <memory>
#include "clipboard_item.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class ClipboardWidget;
}
QT_END_NAMESPACE

class ClipboardWidget : public QWidget
{
    Q_OBJECT

public:
    ClipboardWidget(QWidget *parent = nullptr);
    ~ClipboardWidget();
public:
    bool Init();
private slots:
    void OnClipBoardChanged(QClipboard::Mode mode);
    void OnClipBoardDataChanged();
    void OnClipBoardFindBufferChanged();
    void OnClipBoardSelectionChanged();

private:
    Ui::ClipboardWidget *ui;
    QClipboard* board = nullptr;
    std::vector<ClipboardItem*> clip_list;
};
#endif // CLIPBOARDWIDGET_H
