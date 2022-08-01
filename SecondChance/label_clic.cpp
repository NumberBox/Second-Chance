#include "label_clic.h"

Label_clic::Label_clic(QWidget* parent)
    : QLabel(parent)
{
}

Label_clic::~Label_clic()
{
}

void Label_clic::mousePressEvent(QMouseEvent* )
{
    emit clicked();
}
