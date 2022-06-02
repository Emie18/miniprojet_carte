/*----------------------------
    fichier MinieVue.h
    contient la class MinieVue
	et ses fonctions membres
	Auteurs : Emilie Le Rouzic
    &   Maryline Le Bot
------------------------------*/

#ifndef MINIEVUE_H
#define MINIEVUE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

#include "Scene.h"

class MinieVue : public QGraphicsView
{
	Q_OBJECT
public:
	MinieVue(ScenePlan *scene, QWidget *w) : QGraphicsView(scene, w)
	{
		Q_UNUSED(scene);
		// inversion des y
		scale(1, -1);
	}
	~MinieVue() {}
public slots:
	void trace_viewport(QRectF rect_viewport)
	{
		cadre = rect_viewport;
		viewport()->update();
	}

private:
	void drawForeground(QPainter *painter, const QRectF &) override
	{
		painter->setPen(QPen(Qt::black, 0));
		painter->drawRect(cadre);
	}
	// Gestionnaires d'évènements

	// Fit de la vue sur les limites de la scène
	void resizeEvent(QResizeEvent *) override
	{
		if (this->transform().m11() == 1)
		{
			this->fitInView(sceneRect(), Qt::KeepAspectRatio);
		}
	}

private:
	QRectF cadre;
};

#endif