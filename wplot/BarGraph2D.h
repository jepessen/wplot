#ifndef WPLOT_BARGRAPH2D_H_
#define WPLOT_BARGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/ScalarGraph2D.h"
#include <QColor>
#include <QPen>
#include <QBrush>
#include <memory>

namespace WPlot {

class Plot2D;

class BarGraph2D : public ScalarGraph2D
{
public:

	/** Pointer to this class */
	typedef std::shared_ptr<BarGraph2D> Ptr;

	/**
	 * This enumerator allows to set the type of size of the bar.
	 * When a numeric value is set for length, it can be one of these.
	 */
	typedef enum {
		SIZE_PIXELS,  //!< Dimension is given in pixels.
		SIZE_PERCENT, //!< Dimension is give in percent space related to
									//!  adiacent points.
		SIZE_PLOT     //!< Dimension is given in plot coordinates.
	} SizeType;

public:

	BarGraph2D();
	virtual ~BarGraph2D() = default;
	void setLineColor(const QColor &color);
	void setFillColor(const QColor &color);
	void setLineWidth(const double &width);
	void setSpaceBetweenBars(const double &space, const SizeType &type);
	void setBarWidth(const double &width, const SizeType &type);

public:

	virtual void draw(Plot2D *plot);

private:

	typedef enum {
		LENGTH_SPACE,
		LENGTH_WIDTH
	} LengthType;

private:

	QColor m_lineColor;
	QColor m_fillColor;
	double m_lineWidth;
	double m_barLength;
	SizeType m_barSizeType;
	LengthType m_barLengthType;
	QPen m_pen;
	QBrush m_brush;
};

} // namespace WPlot

#endif // WPLOT_BARGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::BarGraph2D
 *
 * This class allows to draw a bar plot. A bar plot allows to draw a set of
 * values with bars.
 */
