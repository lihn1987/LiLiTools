#include "clipboard_widget.h"
#include "ui_clipboard_widget.h"
#include <QMimeData>
#include <QUrl>
#include <QDebug>


ClipboardWidget::ClipboardWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClipboardWidget)
{
    ui->setupUi(this);
    Init();
}

ClipboardWidget::~ClipboardWidget()
{
    delete ui;
}

bool ClipboardWidget::Init(){
    board = QApplication::clipboard();
    if (!board) {
        return false;
    }
    connect(board, SIGNAL(changed(QClipboard::Mode)), this, SLOT(OnClipBoardChanged(QClipboard::Mode)));
    connect(board, SIGNAL(dataChanged()), this, SLOT(OnClipBoardDataChanged()));
    connect(board, SIGNAL(findBufferChanged()), this, SLOT(OnClipBoardFindBufferChanged()));
    connect(board, SIGNAL(selectionChanged()), this, SLOT(OnClipBoardSelectionChanged()));
    return true;
}

void ClipboardWidget::OnClipBoardChanged(QClipboard::Mode mode){
    qDebug()<<__FUNCTION__<<mode;
}
void ClipboardWidget::OnClipBoardDataChanged(){
    const QMimeData* mime_data = board->mimeData();

    std::shared_ptr<std::unordered_map<QString, QByteArray>> widget_data = std::make_shared<std::unordered_map<QString, QByteArray>>();
    for (QString& format: mime_data->formats()) {
        (*widget_data)[format] = mime_data->data(format);
    }
    // 若历史记录不为0，且数据相同，就不用插入了
    if (clip_list.size() != 0 && *widget_data == *clip_list[clip_list.size() - 1]->GetData()){
        return;
    }
    ClipboardItem *widget = new ClipboardItem();
    widget->SetData(widget_data);
    clip_list.push_back(widget);
    ui->lytClipList->insertWidget(ui->lytClipList->count(), widget);
}
void ClipboardWidget::OnClipBoardFindBufferChanged(){
    qDebug()<<__FUNCTION__;
}
void ClipboardWidget::OnClipBoardSelectionChanged(){
    qDebug()<<__FUNCTION__;
}
