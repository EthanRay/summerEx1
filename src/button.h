
#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>
//! [0]
class Button : public QToolButton
{
    Q_OBJECT

public:
     Button(const QString &text, QWidget *parent = 0);

    QSize sizeHint() const Q_DECL_OVERRIDE;

	/*
	The QSize class defines the size of a two-dimensional object using integer point precision. 

	*/
};
//! [0]

#endif
