#include "wplot/LineGraph2D.h"
#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

LineGraph2D::LineGraph2D() :
	ScalarGraph2D(),
	m_lineColor(Qt::black),
	m_lineWidth(1.0)
{
	m_pen.setColor(m_lineColor);
	m_pen.setWidthF(m_lineWidth);
}

/**
 * Set the color of the line.
 *
 * @param[in] color Color.
 */
void LineGraph2D::setLineColor(const QColor &color) {
	m_lineColor = color;
	m_pen.setColor(color);
}

/**
 * Set the width of the line in pixels.
 *
 * @param[in] width Width.
 */
void LineGraph2D::setLineWidth(const double &width) {
	m_lineWidth = width;
	m_pen.setWidthF(width);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw the graph into specified plot.
 *
 * @param[inout] plot Plot.
 */
void LineGraph2D::draw(Plot2D *plot) {
	QPolygonF points;
	QPainter painter(plot);
	plot->initializePainter(painter);
	painter.setPen(m_pen);
	for (auto& it : m_data) {
		points.append(plot->scalePoint(it));
	}
	painter.drawPolyline(points);
}

} // namespace WPlot
