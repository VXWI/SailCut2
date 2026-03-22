#include <stdio.h>
#include "camberinfodialog.h"
#include "ui_camberinfodialog.h"

CamberInfoDialog::CamberInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CamberInfoDialog)
{
    ui->setupUi(this);
}

CamberInfoDialog::CamberInfoDialog(QWidget *parent, camberAtHeight *camberArray) :
    QDialog(parent),
    ui(new Ui::CamberInfoDialog)
{
    ui->setupUi(this);
    ui->label->setData(camberArray);

    QString txt = "";

    if (camberArray != NULL) {
        char buffer[300];

        txt += "Cambers:\n\n";
        txt += "% Height |   Arc | Chord | Max Depth | Base Camber | Combined Camber\n";
        txt += "         |       |       |  Position |  %      mm  |   %      mm\n";
        for (int i=NUM_CAMBER_POINTS-1; i>=0; i--) {
            sprintf(buffer, "   %5.2f  %6d   %6d     %6d   %5.2f %4d     %5.2f %4d\n",
                    camberArray[i].height*100.0, int(camberArray[i].arcLength), int(camberArray[i].chordLength), int(camberArray[i].maxPos),
                    camberArray[i].baseCamber,camberArray[i].baseCamberMM,
                    camberArray[i].combinedCamber, camberArray[i].combinedCamberMM);
            txt += QString::fromUtf8(buffer);
        }
    } else {
        txt += "No Camber data available";
    }

    ui->textEdit->setText(txt);
    ui->textEdit->setReadOnly(true);

}

CamberInfoDialog::~CamberInfoDialog()
{
    delete ui;
}
