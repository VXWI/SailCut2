#ifndef CAMBERDIALOGLABEL_H
#define CAMBERDIALOGLABEL_H

#include <QLabel>
#include <QPainter>
#include "sailcpp/camberStruct.h"
#include <geocpp/geocpp.h>
#include "sailcpp/sailcalc.h"

class CamberDialogLabel : public QLabel
{
public:
    CamberDialogLabel(QWidget *);
    void setData(camberAtHeight *cambers);

protected:
    void paintEvent( QPaintEvent *);
    void resizeEvent( QResizeEvent * );

private:
    camberAtHeight *cambersInfo;

    /** The logical viewport */
    CRect3d m_lRect;

    /** Has the area been resized since last redraw */
    bool wasResized;

};

#endif // CAMBERDIALOGLABEL_H
