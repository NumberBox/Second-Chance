#ifndef OC_KYRSA_DYNAMIC_LIB_H
#define OC_KYRSA_DYNAMIC_LIB_H

#include "OC_Kyrsa_dynamic_lib_global.h"

#include <QDialog>

class OC_KYRSA_DYNAMIC_LIB_EXPORT OC_Kyrsa_dynamic_lib : public QDialog
{
public:
    explicit OC_Kyrsa_dynamic_lib(QWidget* parent = nullptr);
    //OC_Kyrsa_dynamic_lib();
    static int slot_lib(int, int);
};

#endif // OC_KYRSA_DYNAMIC_LIB_H
