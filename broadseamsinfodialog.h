#ifndef BROADSEAMSINFODIALOG_H
#define BROADSEAMSINFODIALOG_H

#include <QDialog>
#include "geocpp/vector.h" // needed for typedef of real
#include "sailcpp/broadseamsStruct.h"

namespace Ui {
class BroadseamsInfoDialog;
}

class BroadseamsInfoDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BroadseamsInfoDialog(QWidget *parent = 0);
    BroadseamsInfoDialog(QWidget *, vector<broadseamInfo> );
    ~BroadseamsInfoDialog();
    
private:
    Ui::BroadseamsInfoDialog *ui;
};

#endif // BROADSEAMSINFODIALOG_H
