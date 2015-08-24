#ifndef WPLOT_LINEGRAPH2D_H_
#define WPLOT_LINEGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/ScalarGraph2D.h"
#include <QColor>
#include <QPen>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT LineGraph2D : public ScalarGraph2D
{
public:

	typedef std::shared_ptr<LineGraph2D> Ptr;

public:

	LineGraph2D();
	virtual ~LineGraph2D() = default;
	void setLineColor(const QColor &color);
	void setLineWidth(const double &width);

public:

	virtual void draw(Plot2D *plot);

private:

	QColor m_lineColor;
	double m_lineWidth;
	QPen m_pen;
};

} // namesapce WPlot

#endif // WPLOT_LINEGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::LineGraph2D
 *
 * This class allows to specify a line graph. In a line graph we have many
 * scalar values that are joined by segments. It's possibile to specify the
 * style of the segments.
 */
