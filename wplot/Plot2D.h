#ifndef WPLOT_PLOT2D_H_
#define WPLOT_PLOT2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Plot.h"
#include "wplot/Background.h"
#include "wplot/Axes2D.h"
#include "wplot/Item2D.h"
#include <QList>
#include <QPainter>
#include <QPointF>

namespace WPlot {

class WPLOTSHARED_EXPORT Plot2D : public Plot
{
	Q_OBJECT

public:

	Plot2D(QWidget *parent = 0);
	virtual ~Plot2D() = default;
	void addAxes(const Axes2D::Ptr &axes);
	void addAxes(const int &index, const Axes2D::Ptr &axes);
	void addItem(const Item2D::Ptr &item);
	void addItem(const int &index, const Item2D::Ptr &item);
	QPointF scalePoint(const QPointF &point) const;
	QPointF scalePoint(const double &x, const double &y) const;
	double scalePointX(const double &x) const;
	double scalePointY(const double &y) const;
	QPointF inverseScalePoint(const QPointF &point) const;
	QPointF inverseScalePoint(const double &x, const double &y) const;
	double inverseScalePointX(const double &x) const;
	double inverseScalePointY(const double &y) const;
	QPointF getUpperLeftCorner() const;
	QPointF getLowerRightCorner() const;

public:

	virtual QPointF getScreenOrigin() const;
	virtual double getScaleX() const;
	virtual double getScaleY() const;

protected:

	typedef QList<Item2D::Ptr> ItemList;
	typedef QList<Axes2D::Ptr> AxesList;

protected:

	void initPainterCoordinates();
	void drawAxes();
	void drawInsets();
	void drawItems();

protected:

	QPointF m_upperLeftCorner;
	QPointF m_lowerRightCorner;

private:

	AxesList m_axesList;
	ItemList m_itemList;
	double m_scaleX;
	double m_scaleY;
	double m_screenOriginX;
	double m_screenOriginY;
};

} // namespace WPlot

#endif // WPLOT_PLOT2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Plot2D
 *
 * This is the base class for plotting a 2D graph. The widget is drawn by a set
 * of Layer. Layers are ordered, and the one with lowest index is drawn at the
 * bottom.
 *
 * In order to add a layer we must to add it. It can be added with an index
 * associated that allows to define the drawing order.
 */
