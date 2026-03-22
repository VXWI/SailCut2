#include <stdio.h>
#include "broadseamsinfodialog.h"
#include "ui_broadseamsinfodialog.h"

BroadseamsInfoDialog::BroadseamsInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BroadseamsInfoDialog)
{
    ui->setupUi(this);
}

BroadseamsInfoDialog::BroadseamsInfoDialog(QWidget *parent, vector<broadseamInfo> bsArray) :
    QDialog(parent),
    ui(new Ui::BroadseamsInfoDialog)
{
    ui->setupUi(this);

    QString txt = "";

    if (bsArray.size() > 0) {
        char buffer[200];

        real total = 0;

        txt += "Broadseams:\n\n";
        txt += "Panel No.| Index    | Amount    | Percentage\n";
        txt += "         |          |           |\n";
        for (int i=bsArray.size()-1; i>=0; i--) {
            sprintf(buffer, "   %2d     %4d         %7.2f     %6.2f\n",
                    bsArray[i].panelNo, bsArray[i].index, bsArray[i].delta, bsArray[i].percentage);
            txt += QString::fromUtf8(buffer);
            total += bsArray[i].delta;
        }
        sprintf(buffer, "\nTotal Broadseaming = %.2f\n", total);
        txt += QString::fromUtf8(buffer);
    } else {
        txt += "No Broadseam data available";
    }

    ui->textEdit->setText(txt);
    ui->textEdit->setReadOnly(true);

}

BroadseamsInfoDialog::~BroadseamsInfoDialog()
{
    delete ui;
}
