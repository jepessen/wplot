#ifndef WPLOT_PLOT2D_H_
#define WPLOT_PLOT2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Plot.h"
#include "wplot/Graph.h"
#include "wplot/Background.h"
#include "wplot/Grid2D.h"
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

	/** Coordinate type used for the layer. */
	typedef enum {
		COORDINATE_WINDOW,
		/**
		 * Coordinates goes from (0, 0) corresponding to upper left corner of
		 * the widget, to (1, 1) corresponding to lower right corner of the widget.
		 */
		COORDINATE_WINDOW_NORMALIZED
	} CoordinateType;

public:

	Plot2D(QWidget *parent = 0);
	virtual ~Plot2D() = default;
	void setPlotLimits(const QPointF &upperLeftCorner, const QPointF &lowerRightCorner);
	void setPlotLimits(const double &xMin, const double &xMax, const double &yMin, const double &yMax);
	QPointF getUpperLeftCorner() const;
	QPointF getLowerRightCorner() const;
	void addGrid(const Grid2D::Ptr &grid);
	void addGrid(const int &index, const Grid2D::Ptr &grid);
	void addAxes(const Axes2D::Ptr &axes);
	void addAxes(const int &index, const Axes2D::Ptr &axes);
	void addGraph(const Graph::Ptr &graph);
	void addGraph(const int &index, const Graph::Ptr &graph);
	void addItem(const Item2D::Ptr &item);
	void addItem(const int &index, const Item2D::Ptr &item);
	void setCoordinateType(const CoordinateType &type);
	CoordinateType getCoordinateType() const;
	QPointF scalePoint(const QPointF &point) const;
	QPointF scalePoint(const double &x, const double &y) const;
	double scalePointX(const double &x) const;
	double scalePointY(const double &y) const;

public:

	virtual QPointF getScreenOrigin() const;
	virtual double getScaleX() const;
	virtual double getScaleY() const;

protected:

	typedef QList<Graph::Ptr> GraphList;
	typedef QList<Grid2D::Ptr> GridList;
	typedef QList<Item2D::Ptr> ItemList;
	typedef QList<Axes2D::Ptr> AxesList;

protected:

	virtual void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
	void drawGrids();
	void drawAxes();
	void drawBoundaries();
	void drawGraphs();
	void drawInsets();
	void drawItems();

private:

	void initPainterCoordinates();

private:

	GraphList m_graphList;
	AxesList m_axesList;
	GridList m_gridList;
	ItemList m_itemList;
	CoordinateType m_coordinateType;
	QPointF m_upperLeftCorner;
	QPointF m_lowerRightCorner;
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
