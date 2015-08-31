#ifndef WPLOT_AXES2D_H_
#define WPLOT_AXES2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Layer2D.h"
#include "wplot/Arrow2D.h"
#include "wplot/Ticks2D.h"
#include <QColor>
#include <QPen>
#include <memory>

namespace WPlot {

class WPLOTSHARED_EXPORT Axes2D : public Layer2D
{
public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<Axes2D> Ptr;

public:

	Axes2D();
	virtual ~Axes2D() = default;
	void setTicks(const Ticks2D::Ptr &ticks);
	void setAxisXColor(const QColor &color);
	void setAxisYColor(const QColor &color);
	void setAxesColor(const QColor &color);
	void setAxisXStyle(const Qt::PenStyle &style);
	void setAxisYStyle(const Qt::PenStyle &style);
	void setAxesStyle(const Qt::PenStyle &style);
	void setAxisXWidth(const double &width);
	void setAxisYWidth(const double &width);
	void setAxesWidth(const double &width);
	void setAxisXArrowWidth(const double &width);
	void setAxisYArrowWidth(const double &width);
	void setAxesArrowWidth(const double &width);
	void setAxisXArrowLength(const double &length);
	void setAxisYArrowLength(const double &length);
	void setAxesArrowLength(const double &length);
	void setAxisXArrowDimensions(const double &width, const double &length);
	void setAxisYArrowDimensions(const double &width, const double &length);
	void setAxesArrowDimensions(const double &width, const double &length);
	void setOrigin(const QPointF &origin);
	void setOrigin(const double &x, const double &y);

public:

	virtual void draw(Plot2D *plot) Q_DECL_OVERRIDE;

private:

	void drawAxes(Plot2D *plot);
	void drawTicks(Plot2D *plot);

private:

	double m_axisXWidth;
	double m_axisYWidth;
	QColor m_axisXColor;
	QColor m_axisYColor;
	Qt::PenStyle m_axisXStyle;
	Qt::PenStyle m_axisYStyle;
	QPen m_axisXPen;
	QPen m_axisYPen;
	Arrow2D m_axisX;
	Arrow2D m_axisY;
	QPointF m_origin;
	Ticks2D::Ptr m_ticks;
};

} // namespace WPlot

#endif // WPLOT_AXES2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Axes2D
 *
 * This class allow to draw axes in a 2D plot.
 *
 * Axes are plotted along @f$X@f$ and @f$Y@f$ axes and the origin can be set:
 * it can be something different than origin @f$\left(0,0\right)@f$. It's
 * possible to set properties for both axis or specify different ones for
 * @f$X@f$ and @f$Y@f$ directions.
 *
 * Axes are plot along all drawing area, that's the entire widget without
 * padding borders.
 *
 * @image html axes.svg "Axes in a plot."
 */
