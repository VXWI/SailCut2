#ifndef CAMBERINFODIALOG_H
#define CAMBERINFODIALOG_H

#include <QDialog>
#include "geocpp/vector.h" // needed for typedef of real
#include "sailcpp/camberStruct.h"

namespace Ui {
class CamberInfoDialog;
}

class CamberInfoDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CamberInfoDialog(QWidget *parent = 0);
    CamberInfoDialog(QWidget *, camberAtHeight *);
    ~CamberInfoDialog();
    
private:
    Ui::CamberInfoDialog *ui;
};

#endif // CAMBERINFODIALOG_H
