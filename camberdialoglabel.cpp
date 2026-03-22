#include "camberdialoglabel.h"

CamberDialogLabel::CamberDialogLabel(QWidget *parent) : QLabel(parent) {}

void CamberDialogLabel::setData(camberAtHeight *c) {
    cambersInfo = c;
    repaint();
}


void CamberDialogLabel::paintEvent(QPaintEvent *) {
    QPainter painter( this );

    QRect vRect = painter.viewport();
    painter.eraseRect(vRect);

    CRect3d objRect;
    objRect.max = CPoint3d(0.22, 1);

    if ( wasResized )
    {
        CRect3d viewRect;
        viewRect.max = CPoint3d(vRect.width(), vRect.height());

        m_lRect = calcLRect(viewRect, objRect, objRect.center(), 0.8);
        wasResized = 0;
    }

    QPoint prev, next;
    unsigned int nbpoints = NUM_CAMBER_POINTS;

    real x, y; // z is horizontal and y is vertical upward

    real scale =  vRect.height() / m_lRect.height();

    // do a translation to have from z=0 to z=scale centered
    painter.translate( (m_lRect.width() / 2 - objRect.center().x()) * scale,
                      vRect.height() + (objRect.center().y() - m_lRect.height()/2) * scale );

    // flip coordinate system to have the y axis pointing up
    painter.scale(1,-1);

    // draw vertical line
    painter.setPen(Qt::black);
    QPoint bottomPoint = QPoint( 0 , int(0));
    QPoint topPoint = QPoint( 0 , int(scale));
    painter.drawLine(bottomPoint, topPoint);

    // draw base camber
    prev = QPoint( int(scale * cambersInfo[0].baseCamberMM/cambersInfo[0].sailHeight), 0 );
    painter.setPen(Qt::blue);

    for (unsigned i = 1; i < nbpoints; i++) {
        y = real(i) / (nbpoints);
        x = cambersInfo[i].baseCamberMM/cambersInfo[i].sailHeight;
        cout << "x = " << int(scale*x) << ", y = " << int(scale*y) << endl;
        next = QPoint( int(scale * x) , int(scale * y));
        painter.drawLine(prev, next);
        prev = next;
    }

    painter.drawLine(next, topPoint);

    // draw combined camber

    prev = QPoint( int(scale * cambersInfo[0].combinedCamberMM/cambersInfo[0].sailHeight), 0 );
    painter.setPen(Qt::red);

    for (unsigned i = 1; i < nbpoints; i++) {
        y = real(i) / (nbpoints);
        x = cambersInfo[i].combinedCamberMM/cambersInfo[i].sailHeight;
        cout << "x = " << int(scale*x) << ", y = " << int(scale*y) << endl;
        next = QPoint( int(scale * x) , int(scale * y));
        painter.drawLine(prev, next);
        prev = next;
    }

    painter.drawLine(next, topPoint);

}

void CamberDialogLabel::resizeEvent(QResizeEvent *) {
    wasResized = true;
}
