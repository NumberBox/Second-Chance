#ifndef LABEL_CLIC_H
#define LABEL_CLIC_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QString>

class Label_clic : public QLabel
{
    Q_OBJECT
public:
    explicit Label_clic(QWidget* parent = nullptr);
    ~Label_clic();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // LABEL_CLIC_H
