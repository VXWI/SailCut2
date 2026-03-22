#ifndef BATTENINFODIALOG_H
#define BATTENINFODIALOG_H

#include <QDialog>
#include "sailcpp/battengroup.h"

namespace Ui {
class CBattenInfoDialog;
}

class CBattenInfoDialog : public QDialog
{
    Q_OBJECT
    
public:
    CBattenInfoDialog(QWidget *, CBattenGroup &);
    explicit CBattenInfoDialog(QWidget *parent = 0);
    ~CBattenInfoDialog();
    
private:
    Ui::CBattenInfoDialog *ui;
};

#endif // BATTENINFODIALOG_H
