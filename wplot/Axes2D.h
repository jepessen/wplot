#ifndef WPLOT_AXES2D_H_
#define WPLOT_AXES2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Layer2D.h"
#include "wplot/Arrow2D.h"
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
	void setPrimaryXStep(const double &step);
	void setSecondaryXStep(const double &step);
	void setPrimaryYStep(const double &step);
	void setSecondaryYStep(const double &step);
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

	double m_axisXPrimaryStep;
	double m_axisXSecondaryStep;
	double m_axisYPrimaryStep;
	double m_axisYSecondaryStep;
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
};

} // namespace WPlot

#endif // WPLOT_AXES2D_H_

/**
 * @class WPlot::Axes2D
 *
 * This class allows to draw a 2D Axes inside the plot.
 */
