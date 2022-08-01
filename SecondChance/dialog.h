#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QString str = "",QWidget *parent = nullptr);
    ~Dialog();

    QPixmap lab_move;
    QPixmap lab_move_clic;
    QPixmap close;
    QPixmap close_clic;

    QLabel *lab;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
