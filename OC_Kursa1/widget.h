#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <Windows.h>
#include "page.h"
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QPoint dragPosition;
    QPoint stat_size_pos;
    QPixmap lab_move;
    QPixmap lab_move_clic;
    QPixmap close;
    QPixmap close_clic;
    QPixmap hide;
    QPixmap hide_clic;
    QPixmap vopros;
    QPixmap vopros_clic;

    QVector<int> str_bloks;
    QVector<int> appeal;
    int quantity_bloc = 0;

    QVector<Page*> vec_page;
    QVector<QRect> vec_rect;

    Page *sourse_page;

    QTimer *timer;
    int time_animation = 1000;
    int inter = 0;

    bool stop = false;


    int color_textEdit = 0;

    typedef char*(*Func_library)(int*, int*, int, int, int, int*);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void help_on();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_3_clicked();
    void color_text();

    void on_pushButton_4_clicked();

    void animation_start_blok();
    void step_animation();
    void step_animation_color();
    void step_animation_while();
    void step_animation_new_page();

    void animation_more_bloks();



    void on_lineEdit_selectionChanged();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
