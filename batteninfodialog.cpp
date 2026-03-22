#include "batteninfodialog.h"
#include "ui_batteninfodialog.h"

CBattenInfoDialog::CBattenInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CBattenInfoDialog)
{
    ui->setupUi(this);
}

CBattenInfoDialog::CBattenInfoDialog(QWidget *parent, CBattenGroup &battenGroup)
    : QDialog(parent),
      ui(new Ui::CBattenInfoDialog) {
    ui->setupUi(this);
    setModal(true);
    QString txt = "";

    for (unsigned int i=0; i<battenGroup.numBattens(); i++) {
        CBatten& b = (const_cast<CBattenGroup&>(battenGroup)).getBatten(i);

        txt += "Batten No. " + QString::number(i, 10) + "\n";
        txt += "    Batten Id = " + QString::fromStdString(b.name)+ "\n";
        txt += "    Leech Position = " + QString::number(b.percentHeight)+ "%\n";
        txt += "    Angle = " + QString::number(b.angle)+ " degrees\n";
        txt += "    Inward Offset = " + QString::number(b.inwardOffset) + "mm\n";
        txt += "    Length = " + QString::number(b.battenLength)+ "\n";

        txt += "    distanceToClew = " + QString::number(b.distanceToClew)+ "\n";
        txt += "    distanceToHead = " + QString::number(b.distanceToHead)+ "\n";
        txt += "    distanceToLowerBatten = " + QString::number(b.distanceToLowerBatten)+ "\n";
        txt += "    distanceToHigherBatten = " + QString::number(b.distanceToHigherBatten)+ "\n";
        txt += "    distanceToTopOfPanel = " + QString::number(b.distanceToTopOfPanel)+ "\n";
        txt += "    distanceToBottomOfPanel = " + QString::number(b.distanceToBottomOfPanel)+ "\n";

        txt += "    roundDepth = " + QString::number(b.roundDepth)+ "\n";
        if (b.fullLength) {
            txt += "    distanceLuffToHead = " + QString::number(b.distanceLuffToHead)+ "\n";
        }
        txt += "\n";
    }
    ui->textEdit->setText(txt);
    ui->textEdit->setReadOnly(true);
}

CBattenInfoDialog::~CBattenInfoDialog()
{
    delete ui;
}
