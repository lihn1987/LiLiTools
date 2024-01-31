#include "clipboard_item.h"
#include "ui_clipboard_item.h"

#include <QDataStream>
#include <QDebug>
#include <QMimeData>
ClipboardItem::ClipboardItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClipboardItem)
{
    ui->setupUi(this);

}

void ClipboardItem::SetData(std::shared_ptr<std::unordered_map<QString, QByteArray>> clip_data){
    this->clip_data = clip_data;
    QMimeData* mime_data = new QMimeData();
    for (auto item: *clip_data) {
        mime_data->setData(item.first, item.second);
    }

    if (mime_data->hasImage()) {
        ui->wgtIcon->setStyleSheet("border-image: url(:/resource/clipboard/image.png);");
    } else if (mime_data->hasUrls()) {
        ui->wgtIcon->setStyleSheet("border-image: url(:/resource/clipboard/file.png);");
    } else if (mime_data->hasHtml()) {
        ui->wgtIcon->setStyleSheet("border-image: url(:/resource/clipboard/html.png);");
    } else if (mime_data->hasText()) {
        ui->wgtIcon->setStyleSheet("border-image: url(:/resource/clipboard/text.png);");
    }
    // for(QString format:mime_data->formats()) {
    //     QPushButton* btn = new QPushButton(format);
    //     QByteArray array = mime_data->data(format);

    //     if (array.isEmpty() == false) {
    //         qDebug()<<"========>1";
    //         qDebug()<<format;
    //         qDebug()<<"========>2";
    //         qDebug()<<array;
    //         qDebug()<<"========>3";
    //         qDebug()<<QString::fromLocal8Bit(array);
    //         qDebug()<<"========>4";
    //         qDebug()<<QImage::fromData(array);
    //         ui->lytFormat->insertWidget(ui->lytFormat->count(), btn);
    //     }
    // }
    // QByteArray byteArray;
    // QDataStream dataStream(&byteArray, QIODevice::WriteOnly);
    // dataStream << *mime_data;
    // this->mime_data.setData();
    delete mime_data;
}

std::shared_ptr<std::unordered_map<QString, QByteArray> > ClipboardItem::GetData(){
    return clip_data;
}

ClipboardItem::~ClipboardItem(){
    delete ui;
}
