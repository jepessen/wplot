#include "wplot/CandleStick2D.h"
#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

CandleStick2D::CandleStick2D() :
	FinancialItem2D(),
	m_lineWidth(1.0),
	m_barWidth(10.0),
	m_lineColor(Qt::black),
	m_positiveColor(Qt::white),
	m_negativeColor(Qt::black),
	m_lineStyle(Qt::SolidLine)
{
	m_pen.setColor(m_lineColor);
	m_pen.setWidthF(m_lineWidth);
	m_pen.setStyle(m_lineStyle);
	m_brush.setStyle(Qt::SolidPattern);
}

void CandleStick2D::setBarPositiveColor(const QColor &color) {
	m_positiveColor = color;
}

void CandleStick2D::setBarNegativeColor(const QColor &color) {
	m_negativeColor = color;
}

void CandleStick2D::setBarColor(const QColor &positive, const QColor &negative) {
	setBarPositiveColor(positive);
	setBarNegativeColor(negative);
}

void CandleStick2D::setLineColor(const QColor &color) {
	m_lineColor = color;
	m_pen.setColor(color);
}

void CandleStick2D::setLineWidth(const double &width) {
	m_lineWidth = width;
	m_pen.setWidthF(width);
}

void CandleStick2D::setLineStyle(const Qt::PenStyle &style) {
	m_lineStyle = style;
	m_pen.setStyle(style);
}

void CandleStick2D::setBarWidth(const double &width) {
	m_barWidth = width;
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw the circle in specified plot.
 *
 * @param[in] plot Plot where circle must be drawn.
 */
void CandleStick2D::draw(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	limitPainterInPaddingArea(painter, plot);
	double rectTop;
	double rectBottom;
	painter.setPen(m_pen);
	if (m_values.getClose() > m_values.getOpen()) {
		m_brush.setColor(m_positiveColor);
		rectTop = getScaledPositionY(m_values.getClose(), plot);
		rectBottom = getScaledPositionY(m_values.getOpen(), plot);
	} else {
		m_brush.setColor(m_negativeColor);
		rectTop = getScaledPositionY(m_values.getOpen(), plot);
		rectBottom = getScaledPositionY(m_values.getClose(), plot);
	}
	painter.setBrush(m_brush);
	const double barWidth = getScaledDimensionX(m_barWidth, plot);
	const QPointF highPoint = getScaledPosition(m_xValue, m_values.getHigh(), plot);
	const QPointF lowPoint = getScaledPosition(m_xValue, m_values.getLow(), plot);
	const double rectLeft = getScaledPositionX(m_xValue, plot) - 0.5 * barWidth;
	const QRectF rect(rectLeft, rectTop, barWidth, rectBottom - rectTop);
	painter.drawLine(highPoint, lowPoint);
	painter.drawRect(rect);
}

} // namespace WPlot
