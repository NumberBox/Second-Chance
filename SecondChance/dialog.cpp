#include "dialog.h"
#include "ui_dialog.h"
#include <QRegion>
#include <QBitmap>
#include <QtWidgets>

Dialog::Dialog(QString str, QWidget *parent) :
    QDialog(parent,Qt::FramelessWindowHint | Qt::WindowSystemMenuHint),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    lab = ui->label;
    lab->setText(str);
    qApp->installEventFilter(this);
    QPixmap bkgnd(":/new/prefix1/2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    QRegion maskedRegion(bkgnd.mask());
    setMask(maskedRegion);


    close.load(":/new/prefix1/close.png");
    close = close.scaled(ui->label_2->size(), Qt::KeepAspectRatio);
    close_clic.load(":/new/prefix1/close_clic.png");
    close_clic = close_clic.scaled(ui->label_2->size(), Qt::KeepAspectRatio);
    ui->label_2->setPixmap(close);
    ui->label_2->setMask(close.mask());

    connect(ui->label_2, SIGNAL(clicked()),this, SLOT(close()));

}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::Resize){

    }
    if (watched == ui->label_2){
        if(event->type() == QEvent::MouseButtonPress){
            ui->label_2->setPixmap(close_clic);
        }
        if(event->type() == QEvent::MouseButtonRelease){
            ui->label_2->setPixmap(close);
        }

        if(event->type() == QEvent::Leave){
            ui->label_2->setPixmap(close);
        }
        if(event->type() == QEvent::Enter){
            ui->label_2->setPixmap(close_clic);
        }
    }

    QObject::eventFilter(watched, event);
    return false;
}
