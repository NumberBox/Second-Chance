#include "widget.h"
#include "ui_widget.h"
#include "label_clic.h"
#include "page.h"
#include "dialog.h"

#include <QBitmap>
#include <QDebug>
#include <QtWidgets>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QThread>
#include <QWidget>
#include <QScrollBar>

//#include <OC_Kyrsa_dynamic_lib/include/oc_kyrsa_dynamic_lib.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qApp->installEventFilter(this);
    QPixmap bkgnd(":/new/prefix1/1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    QRegion maskedRegion(bkgnd.mask());
    setMask(maskedRegion);

    connect(ui->label_2, SIGNAL(clicked()),qApp, SLOT(quit()));
    connect(ui->label_4, SIGNAL(clicked()),this, SLOT(help_on()));
    connect(ui->label_5, SIGNAL(clicked()),this, SLOT(showMinimized()));

    lab_move.load(":/new/prefix1/perem_2.png");
    lab_move = lab_move.scaled(ui->label_3->size(), Qt::KeepAspectRatio);
    lab_move_clic.load(":/new/prefix1/perem_clic_2.png");
    lab_move_clic = lab_move_clic.scaled(ui->label_3->size(), Qt::KeepAspectRatio);
    ui->label_3->setPixmap(lab_move);
    ui->label_3->setMask(lab_move.mask());

    close.load(":/new/prefix1/close.png");
    close = close.scaled(ui->label_2->size(), Qt::KeepAspectRatio);
    close_clic.load(":/new/prefix1/close_clic.png");
    close_clic = close_clic.scaled(ui->label_2->size(), Qt::KeepAspectRatio);
    ui->label_2->setPixmap(close);
    ui->label_2->setMask(close.mask());

    hide.load(":/new/prefix1/swertka.png");
    hide = hide.scaled(ui->label_5->size(), Qt::KeepAspectRatio);
    hide_clic.load(":/new/prefix1/swertka_clic.png");
    hide_clic = hide_clic.scaled(ui->label_5->size(), Qt::KeepAspectRatio);
    ui->label_5->setPixmap(hide);
    ui->label_5->setMask(hide.mask());

    vopros.load(":/new/prefix1/vopros.png");
    vopros = vopros.scaled(ui->label_4->size(), Qt::KeepAspectRatio);
    vopros_clic.load(":/new/prefix1/vopros_clic.png");
    vopros_clic = vopros_clic.scaled(ui->label_4->size(), Qt::KeepAspectRatio);
    ui->label_4->setPixmap(vopros);
    ui->label_4->setMask(vopros.mask());


    //ui->label_11->hide();
    QScrollBar * scroll = new QScrollBar(Qt::Vertical);
    scroll->setStyleSheet("QScrollBar:vertical {"
                          "border: 1px solid white;"
                          "background: white;"
                          "width: 22px;"
                          "margin: 22px 0 22px 0;"
                      "}"
                      "QScrollBar::handle:vertical {"
                          "border: 1px solid rgb(53, 137, 193);"
                          "border-radius: 8px;"
                          "background: white;"
                          "min-height: 20px;"
                      "}"
                      "QScrollBar::add-line:vertical {"
                          "background: rgb(255, 255, 255);"
                          "border: 1px solid rgb(53, 137, 193);"
                          "border-radius: 10px;"
                          "height: 20px;"
                          "subcontrol-position: bottom;"
                          "subcontrol-origin: margin;"
                      "}"
                          "QScrollBar::add-line:vertical:hover {"
                              "background: rgb(194, 217, 232);"
                              "border: 1px solid rgb(53, 137, 193);"
                              "border-radius: 10px;"
                              "height: 20px;"
                              "subcontrol-position: bottom;"
                              "subcontrol-origin: margin;"
                          "}"
                      "QScrollBar::sub-line:vertical {"
                          "background: rgb(255, 255, 255);"
                          "border: 1px solid rgb(53, 137, 193);"
                          "border-radius: 10px;"
                          "height: 20px;"
                          "subcontrol-position: top;"
                          "subcontrol-origin: margin;"
                      "}"
                          "QScrollBar::sub-line:vertical:hover {"
                              "background: rgb(194, 217, 232);"
                              "border: 1px solid rgb(53, 137, 193);"
                              "border-radius: 10px;"
                              "height: 20px;"
                              "subcontrol-position: top;"
                              "subcontrol-origin: margin;"
                          "}"
                      "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
                          "background: none;"
                      "}"

                          );
    ui->textEdit->setVerticalScrollBar(scroll);
   // ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    vec_rect.push_back(QRect(60,230,91,121));
    vec_rect.push_back(QRect(190,230,91,121));
    vec_rect.push_back(QRect(320,230,91,121));
    vec_rect.push_back(QRect(450,230,91,121));
    vec_rect.push_back(QRect(580,230,91,121));

    for(int i = 0; i<5;i++){
        Page *pag = new Page("?","1",ui->groupBox);
        pag->setGeometry(vec_rect.at(i));
        pag->show();
        vec_page.push_back(pag);
    }
    sourse_page = new Page("?"," ",ui->groupBox);
    sourse_page->setGeometry(721,230,91,121);
    sourse_page->show();

    timer = new QTimer();
    ui->textEdit->setReadOnly(true);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{

}

void Widget::mousePressEvent(QMouseEvent *event)
{

}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::Resize){

    }
    if (watched == ui->label_3){
        if(event->type() == QEvent::MouseButtonPress){
            ui->label_3->setPixmap(lab_move_clic);
            QMouseEvent *ev = static_cast<QMouseEvent*>(event);
            if (ev->button() == Qt::LeftButton) {
                dragPosition = ev->globalPos() - frameGeometry().topLeft();               
                event->accept();
                return true;
            }
        }
        if(event->type() == QEvent::MouseMove){
            QMouseEvent *ev = static_cast<QMouseEvent*>(event);
            if (ev->buttons() & Qt::LeftButton) {
                move(ev->globalPos() - dragPosition);
                event->accept();
                return true;
            }
        }
        if(event->type() == QEvent::MouseButtonRelease){
            ui->label_3->setPixmap(lab_move);
        }
        if(event->type() == QEvent::Leave){
            ui->label_3->setPixmap(lab_move);
        }
        if(event->type() == QEvent::Enter){
            ui->label_3->setPixmap(lab_move_clic);
        }

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
    if (watched == ui->label_5){
        if(event->type() == QEvent::MouseButtonPress){
            ui->label_5->setPixmap(hide_clic);
        }
        if(event->type() == QEvent::MouseButtonRelease){
            ui->label_5->setPixmap(hide);
        }

        if(event->type() == QEvent::Leave){
            ui->label_5->setPixmap(hide);
        }
        if(event->type() == QEvent::Enter){
            ui->label_5->setPixmap(hide_clic);
        }
    }
    if (watched == ui->label_4){
        if(event->type() == QEvent::MouseButtonPress){
            ui->label_4->setPixmap(vopros_clic);
        }
        if(event->type() == QEvent::MouseButtonRelease){
            ui->label_4->setPixmap(vopros);
        }

        if(event->type() == QEvent::Leave){
            ui->label_4->setPixmap(vopros);
        }
        if(event->type() == QEvent::Enter){
            ui->label_4->setPixmap(vopros_clic);
        }
    }


    QObject::eventFilter(watched, event);
    return false;
}

void Widget::help_on()//вызов справки
{   
    Dialog *dialog;
    //dialog->lab->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        HINSTANCE p_dll = LoadLibrary(L"Dll1_Oc_test.dll");
        if (!p_dll) {
            dialog = new Dialog("Реализация модели алгоритма\nзамены страниц \"вторая попытка\"\n\nСусленников Мелетий 484 группа 2020 год"
                                "\n\nСостояние Dll библиотеки - Не подключено",this);
        }
        else{
            dialog = new Dialog("Реализация модели алгоритма\nзамены страниц \"вторая попытка\"\n\nСусленников Мелетий 484 группа 2020 год"
                                "\n\nСостояние Dll библиотеки - Подключено",this);
        }
    dialog->exec();
}

void Widget::on_pushButton_clicked() //расчитать
{

    HINSTANCE p_dll = LoadLibrary(L"Dll1_Oc_test.dll");
    if (!p_dll) {
        Dialog *dialog = new Dialog("Библиотека Dll не подключена",this);
        dialog->exec();
        return;
    }

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->textEdit->clear();
    appeal.clear();
    str_bloks.clear();
    quantity_bloc = 0;
    color_textEdit = 0;
    //ui->pushButton_4->setEnabled(true);
    ui->pushButton_3->setEnabled(true);

    QStringList list = ui->lineEdit->text().split(QRegExp("\\s+"),QString::SkipEmptyParts);
    int nabor_nach_blok = list.size();
    if(list.size()==0){
        Dialog *dialog = new Dialog("Поле - \"Начальное положение страничных блоков\"\n пусто\n\n"
                                    "Введите числа через пробел",this);
        dialog->exec();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(false);
        appeal.clear();
        str_bloks.clear();
        quantity_bloc = 0;
        return;
    }
    for (int i = 0;i<list.size();i++) {
        bool ok;
        int number = list.at(i).toInt(&ok);
        if(ok){
            str_bloks.push_back(number);
        }
        else{
            Dialog *dialog = new Dialog("Поле - \"Начальное положение страничных блоков\"\n не соответствует правильному формату\n\n"
                                        "Введите числа через пробел",this);
            dialog->exec();
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(false);
            appeal.clear();
            str_bloks.clear();
            quantity_bloc = 0;
            return;
        }
    }
    list.clear();
    list = ui->lineEdit_2->text().split(QRegExp("\\s+"),QString::SkipEmptyParts);
    if(list.size()==0){
        Dialog *dialog = new Dialog("Поле - \"Список обращений\"\n пусто\n\n"
                                    "Введите числа через пробел",this);
        dialog->exec();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(false);
        appeal.clear();
        str_bloks.clear();
        quantity_bloc = 0;
        return;
    }
    for (int i = 0;i<list.size();i++) {
        bool ok;
        int number = list.at(i).toInt(&ok);
        if(ok){
            appeal.push_back(number);
        }
        else{
            Dialog *dialog = new Dialog("Поле - \"Список обращений\"\n не соответствует правильному формату\n\n"
                                        "Введите числа через пробел",this);
            dialog->exec();
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(false);
            appeal.clear();
            str_bloks.clear();
            quantity_bloc = 0;
            return;
        }
    }
    bool ok;
    int number = ui->lineEdit_3->text().toInt(&ok);
    if(ok){
        quantity_bloc = number;
    }
    else{
        Dialog *dialog = new Dialog("Поле - \"Количество страничных блоков\"\n не соответствует правильному формату\n\n"
                                    "Введите одно число",this);
        dialog->exec();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(false);
        appeal.clear();
        str_bloks.clear();
        quantity_bloc = 0;
        return;
    }
    if(nabor_nach_blok>quantity_bloc){
        Dialog *dialog = new Dialog("Набор начальных страничных блоков превышает\nобщее количество страничных блоков",this);
        dialog->exec();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(false);
        appeal.clear();
        str_bloks.clear();
        quantity_bloc = 0;
        return;

    }

    int *array_current_bloks = new int [str_bloks.size()];
    for (int i = 0;i<str_bloks.size();i++) {
        array_current_bloks[i] = str_bloks.at(i);
    }
    int *array_appeal = new int [appeal.size()];
    for (int i = 0;i<appeal.size();i++) {
        array_appeal[i] = appeal.at(i);
    }
    int blok_size = quantity_bloc;
    int control = 0;

    Func_library func = (Func_library)GetProcAddress(p_dll, "dll_func");
    char* out_func = func(array_current_bloks,array_appeal,blok_size,str_bloks.size(),appeal.size(),&control);
    QString ret_1 = out_func;
    QString ex;
    for (int i = 0;i<control;i++) {      
        ui->textEdit->setText(ui->textEdit->toPlainText()+ret_1.at(i));
    }
    FreeLibrary(p_dll);
    QString interrupt_chek = ui->textEdit->toPlainText();
    QString interrupt = "";
    for(int i = interrupt_chek.size()-1;i>0;i--){
        if(interrupt_chek.at(i)!='\n'){
            interrupt.insert(0,interrupt_chek.at(i));
            interrupt_chek.remove(i,1);
        }
        else{
            interrupt_chek.remove(i,1);
            ui->textEdit->setText(interrupt_chek);
            break;
        }

    }
    interrupt_chek = ui->textEdit->toPlainText();
    interrupt = "";
    for(int i = interrupt_chek.size()-1;i>=0;i--){
        if(interrupt_chek.at(i)!='\n'){
            interrupt.insert(0,interrupt_chek.at(i));
        }
        else{
            break;
        }
    }
    for(int i = 0;i<interrupt.size();i++){
        if(interrupt.at(i)=='x'){
            interrupt.remove(i,1);
        }
    }
    //qDebug()<<interrupt;
    ui->label_11->setText("Конечное содержание страничных блоков: "+interrupt);
    QParallelAnimationGroup *an_group = new QParallelAnimationGroup();
    for (int i = 0;i<5;i++) {
            QPropertyAnimation *an = new QPropertyAnimation();
            an->setTargetObject(vec_page.at(i));
            an->setPropertyName("geometry");
            an->setEndValue(sourse_page->geometry());
            an->setDuration(time_animation);
            an_group->addAnimation(an);

    }
    an_group->start();
    if(quantity_bloc>5){
        connect(an_group, SIGNAL(finished()), this, SLOT(animation_more_bloks()));
        ui->pushButton_3->setEnabled(false);
        Dialog *dialog = new Dialog("При расчете с количеством страничных блоков больше 5,\nанимация перестановки воспроизводится не будет.",this);
        dialog->exec();
    }
    else
        connect(an_group, SIGNAL(finished()), this, SLOT(animation_start_blok()));

}


void Widget::on_pushButton_2_clicked()//открыть файл
{
    QString str1 = QFileDialog::getOpenFileName(this, "Открыть файл", "", "*.txt");
    QVector<int> str_bloks_1;
    QVector<int> appeal_1;
    int quantity_bloc_1 = 0;
    QFile file(str1);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString str="";
        int str_file = 0;
        while(!file.atEnd())
        {
            str=file.readLine();
            QStringList list = str.split(QRegExp("\\s+"),QString::SkipEmptyParts);
            for (int i = 0;i<list.size();i++) {
                bool ok;
                int number = list.at(i).toInt(&ok);
                if(ok){
                    if(str_file==0){
                        str_bloks_1.push_back(number);
                    }
                    if(str_file==2){
                        appeal_1.push_back(number);
                    }
                    if(str_file==3){
                        quantity_bloc_1 = number;
                    }
                }
                else{
                    Dialog *dialog = new Dialog("Файл содержит неправильный формат данных",this);
                    dialog->exec();
                    appeal_1.clear();
                    str_bloks_1.clear();
                    quantity_bloc_1 = 0;
                    file.close();
                    return;
                }
            }
            str_file++;
        }
        file.close();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        for (int i = 0;i<str_bloks_1.size();i++) {
            ui->lineEdit->setText(ui->lineEdit->text()+QString::number(str_bloks_1.at(i))+" ");
        }
        for (int i = 0;i<appeal_1.size();i++) {
            ui->lineEdit_2->setText(ui->lineEdit_2->text()+QString::number(appeal_1.at(i))+" ");
        }
        ui->lineEdit_3->setText(QString::number(quantity_bloc_1));

    }
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->label_14->setNum(value);
    time_animation = value*20;
}

void Widget::on_pushButton_3_clicked()//пауза
{
    if(ui->pushButton_3->text()=="Пауза"){
        ui->pushButton_3->setText("Продолжить");

        ui->pushButton_3->setEnabled(false);
        stop = !stop;
    }
    else{
        ui->pushButton_3->setText("Пауза");
        ui->pushButton_4->setEnabled(false);
        stop = !stop;
        step_animation();
    }

}

void Widget::color_text()
{
    QStringList list = ui->textEdit->toPlainText().split('\n');
    QTextCharFormat fmtback;
    fmtback.setForeground(Qt::black);
    fmtback.setFontWeight(QFont::Medium);
    QTextCursor cursorback(ui->textEdit->document());
    cursorback.setPosition(0, QTextCursor::MoveAnchor);
    cursorback.setPosition(ui->textEdit->toPlainText().length(), QTextCursor::KeepAnchor);
    cursorback.setCharFormat(fmtback);
    if(color_textEdit>=list.size()){
        return;
    }

    QTextCharFormat fmt;
    fmt.setForeground(QColor(53, 137, 193));//QColor(53, 137, 193)
    fmt.setFontWeight(QFont::DemiBold);
    QTextCursor cursor(ui->textEdit->document());
    int begin = 0;

    for(int i = 0; i<color_textEdit;i++){
        begin+=list.at(i).size()+1;//+1
    }

    cursor.setPosition(begin, QTextCursor::MoveAnchor);
    cursor.setPosition(begin+list.at(color_textEdit).length(), QTextCursor::KeepAnchor);
    cursor.setCharFormat(fmt);
    color_textEdit++;
}

void Widget::on_pushButton_4_clicked()//сбросить
{
    ui->label_11->clear();
    ui->pushButton_3->setText("Пауза");
    stop = false;
    color_textEdit = 0;
    ui->label_10->setText("-");
    inter = 0;
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->textEdit->clear();

    vec_rect.clear();
    vec_rect.push_back(QRect(60,230,91,121));
    vec_rect.push_back(QRect(190,230,91,121));
    vec_rect.push_back(QRect(320,230,91,121));
    vec_rect.push_back(QRect(450,230,91,121));
    vec_rect.push_back(QRect(580,230,91,121));

    while(vec_page.size()>0){
        Page *del_page = vec_page.back();
        vec_page.pop_back();
        delete  del_page;
    }
    for(int i = 0; i<5;i++){
        Page *pag = new Page("?","1",ui->groupBox);
        pag->setGeometry(vec_rect.at(i));
        pag->show();
        vec_page.push_back(pag);
    }
    delete sourse_page;
    sourse_page = new Page("?"," ",ui->groupBox);
    sourse_page->setGeometry(721,230,91,121);
    sourse_page->show();
}

void Widget::animation_start_blok()
{
    time_animation = ui->label_14->text().toInt()*20;
    QParallelAnimationGroup *an_group = new QParallelAnimationGroup();
    for (int i = 0;i<quantity_bloc;i++) {
        QPropertyAnimation *an = new QPropertyAnimation();
        if(i>=str_bloks.size()){
            vec_page[i]->num_l->setText("-");
            vec_page[i]->save_l->setText(" ");
        }
        else{
            vec_page[i]->num_l->setText(QString::number(str_bloks.at(i)));
            vec_page[i]->save_l->setText("1");
        }
        an->setTargetObject(vec_page.at(i));
        an->setPropertyName("geometry");
        an->setEndValue(vec_rect.at(i));
        an->setDuration(time_animation);
        an_group->addAnimation(an);
    }
    an_group->start();
    connect(an_group, SIGNAL(finished()), this, SLOT(step_animation()));
    sourse_page->num_l->setText(QString::number(appeal.front()));
    appeal.pop_front();

    for (int i = 0;i<5-quantity_bloc;i++) {
        Page *del_page = vec_page.back();
        vec_page.pop_back();
        vec_rect.pop_back();
        delete del_page;
    }
}

void Widget::step_animation()
{
    if(stop){
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        return;
    }
    if(sourse_page->num_l->text()=="?"){
        inter++;
        ui->label_10->setNum(inter);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(true);
        return;
    }
    color_text();
    bool interrupt = true;
    for (int i = 0;i<vec_page.size();i++) {
        if(vec_page.at(i)->num_l->text()==sourse_page->num_l->text()){
           inter--;
           interrupt = false;
           QPropertyAnimation *an = new QPropertyAnimation();
           an->setTargetObject(vec_page.at(i));
           vec_page.at(i)->setStyleSheet("QGroupBox{"
                                         "border: 3px solid;"
                                         "border-radius: 20px;"
                                         "border-color: rgb(53, 137, 193);"
                                         "background-color: rgb(194, 217, 232);"
                                         "}");
           an->setPropertyName("geometry");
           QRect rect = vec_rect.at(i);
           rect.setX(rect.x()-10);
           rect.setY(rect.y()-10);
           rect.setWidth(rect.width()+10);
           rect.setHeight(rect.height()+10);
           an->setKeyValueAt(0.5f,rect);
           an->setEndValue(vec_rect.at(i));
           an->setDuration(time_animation);
           an->start();
           connect(an, SIGNAL(finished()), this, SLOT(step_animation_color()));
           break;

        }
        if(vec_page.at(i)->num_l->text()=="-"){
           vec_page.at(i)->num_l->setText(sourse_page->num_l->text());
           vec_page.at(i)->save_l->setText("1");
           interrupt = false;
           QPropertyAnimation *an = new QPropertyAnimation();
           an->setTargetObject(vec_page.at(i));
           vec_page.at(i)->setStyleSheet("QGroupBox{"
                                         "border: 3px solid;"
                                         "border-radius: 20px;"
                                         "border-color: rgb(53, 137, 193);"
                                         "background-color: rgb(194, 217, 232);"
                                         "}");
           an->setPropertyName("geometry");
           QRect rect = vec_rect.at(i);
           rect.setX(rect.x()-10);
           rect.setY(rect.y()-10);
           rect.setWidth(rect.width()+10);
           rect.setHeight(rect.height()+10);
           an->setKeyValueAt(0.5f,rect);
           an->setEndValue(vec_rect.at(i));
           an->setDuration(time_animation);
           an->start();
           connect(an, SIGNAL(finished()), this, SLOT(step_animation_color()));
           break;
        }

    }
    if(interrupt){
        step_animation_while();
    }
}

void Widget::step_animation_color()
{
    for (int i = 0;i<vec_page.size();i++) {
        if(vec_page.at(i)->num_l->text()==sourse_page->num_l->text()){
           vec_page.at(i)->setStyleSheet("QGroupBox{"
                                         "border: 3px solid;"
                                         "border-radius: 20px;"
                                         "border-color: rgb(53, 137, 193);"
                                         "background-color: rgb(255, 255, 255);"
                                         "}");
           vec_page.at(i)->save_l->setText("1");
        }
    }
    if(appeal.size()!=0){
        sourse_page->num_l->setText(QString::number(appeal.front()));
        inter++;
        ui->label_10->setNum(inter);
        appeal.pop_front();
    }
    else{
        sourse_page->num_l->setText("?");
    }
    step_animation();
}

void Widget::step_animation_while()
{
    if(vec_page.at(0)->save_l->text()=="1"){
        vec_page.at(0)->save_l->setText("0");
        QParallelAnimationGroup *an_group = new QParallelAnimationGroup();
        for (int i = 0;i<vec_page.size();i++) {
            QPropertyAnimation *an = new QPropertyAnimation();
            an->setTargetObject(vec_page.at(i));
            an->setPropertyName("geometry");
            if(i==0){
                QRect rect = vec_rect.at(i);
                rect.setX(rect.x()+10);
                rect.setY(rect.y()+10);
                rect.setWidth(rect.width()-10);
                rect.setHeight(rect.height()-10);
                an->setKeyValueAt(0.1f,rect);
                QRect rect_2 = vec_rect.back();
                rect_2.setX(rect_2.x()+10);
                rect_2.setY(rect_2.y()+10);
                rect_2.setWidth(rect_2.width()-10);
                rect_2.setHeight(rect_2.height()-10);
                an->setKeyValueAt(0.9f,rect_2);
                an->setEndValue(vec_rect.back());
            }
            else{
              an->setEndValue(vec_rect.at(i-1));
            }
            an->setDuration(time_animation);
            an_group->addAnimation(an);
        }
        an_group->start();
        connect(an_group, SIGNAL(finished()), this, SLOT(step_animation_while()));
        vec_page.push_back(vec_page.at(0));
        vec_page.pop_front();
    }
    else{
        QParallelAnimationGroup *an_group = new QParallelAnimationGroup();
        for (int i = 0;i<vec_page.size();i++) {
            QPropertyAnimation *an = new QPropertyAnimation();
            an->setTargetObject(vec_page.at(i));
            an->setPropertyName("geometry");
            if(i==0){
                QRect rect = vec_rect.at(i);
                rect.setX(rect.x()+rect.width()/2);
                rect.setY(rect.y()+rect.height()/2);
                rect.setWidth(0);
                rect.setHeight(0);
                an->setEndValue(rect);
                an->setDuration(time_animation/2);
            }
            else{
              an->setEndValue(vec_rect.at(i-1));
              an->setDuration(time_animation);
            }

            an_group->addAnimation(an);
        }
        an_group->start();
        connect(an_group, SIGNAL(finished()), this, SLOT(step_animation_new_page()));
    }

}

void Widget::step_animation_new_page()
{
    vec_page.push_back(vec_page.at(0));
    vec_page.pop_front();
    vec_page.back()->num_l->setText(sourse_page->num_l->text());
    vec_page.back()->save_l->setText("1");
    QPropertyAnimation *an = new QPropertyAnimation();
    an->setTargetObject(vec_page.back());
    an->setPropertyName("geometry");
        an->setStartValue(sourse_page->geometry());
        an->setEndValue(vec_rect.back());
    an->setDuration(time_animation);
    an->start();
    if(appeal.size()!=0){
        sourse_page->num_l->setText(QString::number(appeal.front()));
        appeal.pop_front();
        inter++;
        ui->label_10->setNum(inter);
    }
    else{
        sourse_page->num_l->setText("?");
    }
    connect(an, SIGNAL(finished()), this, SLOT(step_animation()));
}

void Widget::animation_more_bloks()
{
    ui->pushButton_4->setEnabled(true);
    int p = 0;
    for (int i = 0;i<ui->textEdit->toPlainText().size();i++) {
        if(ui->textEdit->toPlainText().at(i)=="x"){
            p++;
        }
    }
    ui->label_10->setNum(p);
    QParallelAnimationGroup *an_group = new QParallelAnimationGroup();
    for (int i = 0;i<5;i++) {
            QPropertyAnimation *an = new QPropertyAnimation();
            an->setTargetObject(vec_page.at(i));
            an->setPropertyName("geometry");
            an->setEndValue(vec_rect.at(i));
            an->setDuration(time_animation);
            an_group->addAnimation(an);

    }
    an_group->start();//добавить прерывание;
}

void Widget::on_lineEdit_selectionChanged()
{

}
