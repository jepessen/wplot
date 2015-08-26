#include "wplot/Arrow2D.h"
#include "wplot/Plot2D.h"
#include <QTransform>
#include <cmath>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

Arrow2D::Arrow2D() :
	Item2D(),
	m_finalPoint(),
	m_lineWidth(1.0),
	m_arrowLineWidth(1.0),
	m_arrowWidth(1.0),
	m_arrowLength(1.0),
	m_lineColor(Qt::black),
	m_arrowLineColor(Qt::black),
	m_arrowFillColor(Qt::white),
	m_lineStyle(Qt::SolidLine),
	m_arrowLineStyle(Qt::SolidLine) {
	m_linePen.setColor(m_lineColor);
	m_linePen.setWidthF(m_lineWidth);
	m_linePen.setStyle(m_lineStyle);
	m_arrowLinePen.setColor(m_arrowLineColor);
	m_arrowLinePen.setWidthF(m_arrowWidth);
	m_arrowLinePen.setStyle(m_arrowLineStyle);
	m_arrowBrush.setColor(m_arrowFillColor);
	m_arrowBrush.setStyle(Qt::SolidPattern);
}

void Arrow2D::setFinalPoint(const QPointF &point) {
	m_finalPoint = point;
}

void Arrow2D::setFinalPoint(const double &x, const double &y) {
	m_finalPoint.setX(x);
	m_finalPoint.setY(y);
}

void Arrow2D::setLine(const QPointF &initialPoint, const QPointF &finalPoint) {
	setPivot(initialPoint);
	setFinalPoint(finalPoint);
}

void Arrow2D::setLine(const double &x1, const double &y1, const double &x2, const double &y2) {
	setPivot(x1, y1);
	setFinalPoint(x2, y2);
}

void Arrow2D::setLineColor(const QColor &color) {
	m_lineColor = color;
	m_linePen.setColor(color);
}

void Arrow2D::setLineWidth(const double &width) {
	m_lineWidth = width;
	m_linePen.setWidthF(width);
}

void Arrow2D::setLineStyle(const Qt::PenStyle &style) {
	m_lineStyle = style;
	m_linePen.setStyle(style);
}

void Arrow2D::setArrowFillColor(const QColor &color) {
	m_arrowFillColor = color;
	m_arrowBrush.setColor(color);
}

void Arrow2D::setArrowLineColor(const QColor &color) {
	m_arrowLineColor = color;
	m_arrowLinePen.setColor(color);
}

void Arrow2D::setArrowLineWidth(const double &width) {
	m_arrowLineWidth = width;
	m_arrowLinePen.setWidthF(width);
}

void Arrow2D::setArrowLineStyle(const Qt::PenStyle &style) {
	m_arrowLineStyle = style;
	m_arrowLinePen.setStyle(style);
}

void Arrow2D::setArrowLength(const double &length) {
	m_arrowLength = length;
}

void Arrow2D::setArrowWidth(const double &width) {
	m_arrowWidth = width;
}

void Arrow2D::setArrowDimensions(const double &width, const double &length) {
	m_arrowLength = length;
	m_arrowWidth = width;
}

double Arrow2D::getArrowLength() const {
	return m_arrowLength;
}

double Arrow2D::getArrowWidth() const {
	return m_arrowWidth;
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void Arrow2D::draw(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	limitPainterInPaddingArea(painter, plot);
	drawLine(painter, plot);
	drawArrow(painter, plot);
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                           //
///////////////////////////////////////////////////////////////////////////////

void Arrow2D::drawLine(QPainter &painter, Plot2D *plot) {
	const auto initialPoint = getScaledPosition(m_pivot, plot);
	const auto finalPoint = getScaledPosition(m_finalPoint, plot);
	painter.setPen(m_linePen);
	painter.drawLine(initialPoint, finalPoint);
}

void Arrow2D::drawArrow(QPainter &painter, Plot2D *plot){
	painter.setPen(m_arrowLinePen);
	painter.setBrush(m_arrowBrush);
	const auto initialPoint = getScaledPosition(m_pivot, plot);
	const auto finalPoint = getScaledPosition(m_finalPoint, plot);
	const double angle = atan2(finalPoint.y() - initialPoint.y(), finalPoint.x() - initialPoint.x());
	const double arrowLength = getScaledDimensionX(m_arrowLength, plot);
	const double arrowWidth = getScaledDimensionX(m_arrowWidth, plot);
	const QPointF p1(-m_arrowLength + finalPoint.x(), -m_arrowWidth * 0.5 + finalPoint.y());
	const QPointF p2(-m_arrowLength + finalPoint.x(), m_arrowWidth * 0.5 + finalPoint.y());
	QPolygonF arrow;
	arrow << finalPoint << p1 << p2;
	QTransform transform;
	transform.rotateRadians(angle);
	const QPolygonF rotatedArrow = transform.map(arrow);
	const auto deltaPosition = arrow.front() -  rotatedArrow.front();
	QTransform translateTransform;
	translateTransform.translate(deltaPosition.x(), deltaPosition.y());
	const QPolygonF rotoTranslatedArros = translateTransform.map(rotatedArrow);
	painter.drawPolygon(rotoTranslatedArros);
}

} // namespace WPlot
