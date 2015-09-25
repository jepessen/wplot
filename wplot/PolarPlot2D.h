#ifndef WPLOT_POLARPLOT2D_H_
#define WPLOT_POLARPLOT2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Plot2D.h"
#include "wplot/PolarGrid2D.h"
#include "wplot/PolarGraph2D.h"
#include "wplot/Background.h"

namespace WPlot {

class WPLOTSHARED_EXPORT PolarPlot2D : public Plot2D {

	Q_OBJECT

public:

	explicit PolarPlot2D(QWidget *parent = 0);
	virtual ~PolarPlot2D() = default;
	void setRadiusLimits(const double &rMin, const double &rMax);
	std::pair<double, double> getRadiusLimits() const;
	void setGraphBackground(const Background::Ptr &background);
	void addGrid(const PolarGrid2D::Ptr &grid);
	void addGrid(const int &index, const PolarGrid2D::Ptr &grid);
	void addGraph(const PolarGraph2D::Ptr &graph);
	void addGraph(const int &index, const PolarGraph2D::Ptr &graph);
	QPointF scalePolarPoint(const QPointF &point) const;
	QPointF scalePolarPoint(const double &angle, const double &radius) const;

protected:

	virtual void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
	void drawGraphBackground();
	void drawGrids();
	void drawGraphs();
	void drawBoundaries();
	void updateScreenData();

private:

	typedef QList<PolarGrid2D::Ptr> GridList;
	typedef QList<PolarGraph2D::Ptr> GraphList;

private:

	double m_minRadius;
	double m_maxRadius;
	double m_screenRadius;
	GridList m_gridList;
	GraphList m_graphList;
	QPointF m_screenCenter;
	Background::Ptr m_graphBackground;
};

} // namespace WPlot

#endif // !WPLOT_POLARPLOT2D_H_
