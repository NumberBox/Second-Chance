#ifndef PAGE_H
#define PAGE_H

#include <QGroupBox>
#include <QLabel>
#include <QString>

namespace Ui {
class Page;
}

class Page : public QGroupBox
{
    Q_OBJECT

public:
    explicit Page(QString, QString, QWidget *parent = nullptr);
    ~Page();
    QLabel * num_l;
    QLabel * save_l;

private:
    Ui::Page *ui;
};

#endif // PAGE_H
