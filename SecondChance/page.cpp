#include "page.h"
#include "ui_page.h"

Page::Page(QString num, QString save, QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::Page)
{
    ui->setupUi(this);

    num_l = ui->label_2;
    save_l = ui->label;

    num_l->setText(num);
    save_l->setText(save);
}

Page::~Page()
{
    delete ui;
}
