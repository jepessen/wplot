#ifndef WPLOT_CARTESIANPLOT2D_H_
#define WPLOT_CARTESIANPLOT2D_H_

#include "wplot/WPlotGlobal.h"
#include <QPointF>
#include "wplot/Plot2D.h"
#include "wplot/CartesianGrid2D.h"
#include "wplot/CartesianGraph2D.h"

namespace WPlot {

class WPLOTSHARED_EXPORT CartesianPlot2D : public Plot2D {

	Q_OBJECT

public:

	explicit CartesianPlot2D(QWidget *parent = 0);
	virtual ~CartesianPlot2D() = default;
	void addGrid(const CartesianGrid2D::Ptr &grid);
	void addGrid(const int &index, const CartesianGrid2D::Ptr &grid);
	void addGraph(const CartesianGraph2D::Ptr &graph);
	void addGraph(const int &index, const CartesianGraph2D::Ptr &graph);
	void setPlotLimits(const QPointF &upperLeftCorner, const QPointF &lowerRightCorner);
	void setPlotLimits(const double &xMin, const double &xMax, const double &yMin, const double &yMax);

protected:

	virtual void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
	void drawGrids();
	void drawGraphs();
	void drawBoundaries();

private:

	typedef QList<CartesianGrid2D::Ptr> GridList;
	typedef QList<CartesianGraph2D::Ptr> GraphList;

private:

	GraphList m_graphList;
	GridList m_gridList;
};

} // namespace WPlot

#endif // !WPLOT_CARTESIANPLOT2D_H_
