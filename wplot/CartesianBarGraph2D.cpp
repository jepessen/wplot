#include "wplot/CartesianBarGraph2D.h"
#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

CartesianBarGraph2D::CartesianBarGraph2D() :
	CartesianScalarGraph2D(),
	m_lineColor(Qt::black),
	m_fillColor(Qt::white),
	m_lineWidth(1.0),
	m_barWidth(1.0),
	m_lineStyle(Qt::SolidLine),
	m_bottomLineEnabled(false)
{
	m_pen.setColor(m_lineColor);
	m_pen.setWidthF(m_lineWidth);
	m_brush.setColor(m_fillColor);
	m_brush.setStyle(Qt::SolidPattern);
}

/**
 * Set color for bar border lines.
 *
 * @param[in] color Color.
 */
void CartesianBarGraph2D::setBarLineColor(const QColor &color) {
	m_lineColor = color;
	m_pen.setColor(color);
}

/**
 * Set bar border lines width.
 *
 * @param[in] width Width.
 */
void CartesianBarGraph2D::setBarLineWidth(const double &width) {
	m_lineWidth = width;
	m_pen.setWidthF(width);
}

/**
 * Set style for bar border lines.
 *
 * @param[in] style Style.
 */
void CartesianBarGraph2D::setBarLineStyle(const Qt::PenStyle &style) {
	m_lineStyle = style;
	m_pen.setStyle(style);
}

/**
 * Set bar color.
 *
 * @param[in] color Color.
 */
void CartesianBarGraph2D::setBarColor(const QColor &color) {
	m_fillColor = color;
	m_brush.setColor(color);
}

/**
 * Set the flag that enable bottom line drawing. The bottom line is the one
 * that lies in X axis. This line has the same style of other lines so it
 * can be useful sometime to hide it.
 *
 * @param[in] enable Enabling flag.
 */
void CartesianBarGraph2D::enableBottomBarLine(const bool &enable) {
	m_bottomLineEnabled = enable;
}

/**
 * Set bar width.
 *
 * @param[in] width Width.
 */
void CartesianBarGraph2D::setBarWidth(const double &width) {
	m_barWidth = width;
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw the graph into specified plot.
 *
 * @param[inout] plot Plot.
 */
void CartesianBarGraph2D::draw(Plot2D *plot) {
	QPolygonF points;
	QPainter painter(plot);
	plot->initializePainter(painter);
	setDrawingInPaddingArea(true);
	limitPainterInPaddingArea(painter, plot);
	const auto origin = plot->getScreenOrigin();
	painter.setPen(m_pen);
	painter.setBrush(m_brush);
	for (int i = 0; i < m_data.size(); i++) {
		const QPointF data = plot->scalePoint(m_data.at(i));
		const QPointF topLeft(data.x() - 0.5 * m_barWidth, data.y());
		const QPointF bottomRight(data.x() + 0.5 * m_barWidth, origin.y());
		const QRectF rect(topLeft, bottomRight);
		if (true == m_bottomLineEnabled) {
			painter.drawRect(rect);
		} else {
			QPolygonF line;
			line << QPointF(topLeft.x(), bottomRight.y()) << topLeft << QPointF(bottomRight.x(), topLeft.y()) << bottomRight;
			if (true == m_colorFunctionDefined) {
				m_brush.setColor(m_colorFunction(m_data.at(i)));
			}
			painter.fillRect(rect, m_brush);
			painter.drawPolyline(line);
		}
	}
}

} // namespace WPlot
