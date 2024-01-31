#ifndef CLIPBOARD_ITEM_H
#define CLIPBOARD_ITEM_H

#include <QWidget>
#include <QMimeData>

namespace Ui {
class ClipboardItem;
}

class ClipboardItem : public QWidget
{
    Q_OBJECT

public:
    explicit ClipboardItem(QWidget *parent = nullptr);
    void SetData(std::shared_ptr<std::unordered_map<QString, QByteArray>> clip_data);
    std::shared_ptr<std::unordered_map<QString, QByteArray>> GetData();
    ~ClipboardItem();

private:
    Ui::ClipboardItem *ui;
    std::shared_ptr<std::unordered_map<QString, QByteArray>> clip_data;
};

#endif // CLIPBOARD_ITEM_H
