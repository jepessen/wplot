#include "wplot/Rectangle.h"
#include "wplot/Plot2D.h"

namespace WPlot {

Rectangle::Rectangle() :
	Item2D(),
	m_pivotPosition(PIVOT_BOTTOM_LEFT),
	m_dimensions(1.0, 1.0),
	m_fillColor(Qt::white),
	m_lineColor(Qt::black),
	m_lineStyle(Qt::SolidLine),
	m_lineWidth(1.0)
{
	m_pen.setColor(m_lineColor);
	m_pen.setWidthF(m_lineWidth);
	m_pen.setStyle(m_lineStyle);
	m_brush.setColor(m_fillColor);
	m_brush.setStyle(Qt::SolidPattern);
}

void Rectangle::setDimensions(const QPointF &dimensions) {
	m_dimensions.setWidth(dimensions.x());
	m_dimensions.setHeight(dimensions.y());
}

void Rectangle::setDimensions(const QSizeF &dimensions) {
	m_dimensions = dimensions;
}

void Rectangle::setDimensions(const double &width, const double &height) {
	m_dimensions.setWidth(width);
	m_dimensions.setHeight(height);
}

void Rectangle::setPivotPosition(const PivotPosition &position) {
	m_pivotPosition = position;
}

void Rectangle::setLineColor(const QColor &color) {
	m_lineColor = color;
	m_pen.setColor(color);
}

void Rectangle::setFillColor(const QColor &color) {
	m_fillColor = color;
	m_brush.setColor(color);
}

void Rectangle::setLineWidth(const double &width) {
	m_lineWidth = width;
	m_pen.setWidthF(width);
}

void Rectangle::setLineStyle(const Qt::PenStyle &style) {
	m_lineStyle = style;
	m_pen.setStyle(style);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void Rectangle::draw(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	painter.setPen(m_pen);
	painter.setBrush(m_brush);
	const QPointF topLeftPivot = getTopLeftPivot(plot);
	const auto dimensions = getScaledDimensions(m_dimensions, plot);
	const QRectF rect(topLeftPivot, QSizeF(dimensions.x(), dimensions.y()));
	painter.drawRect(rect);
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                           //
///////////////////////////////////////////////////////////////////////////////

QPointF Rectangle::getTopLeftPivot(Plot2D *plot) const {
	QPointF pivot(getScaledPosition(m_pivot, plot));
	const double width = getScaledDimensionX(m_dimensions.width(), plot);
	const double height = getScaledDimensionY(m_dimensions.height(), plot);
	switch (m_pivotPosition) {
	case PIVOT_BOTTOM_LEFT : {
	} break;
	case PIVOT_BOTTOM_CENTER : {
		pivot.setX(pivot.x() - 0.5 * width);
	} break;
	case PIVOT_BOTTOM_RIGHT : {
		pivot.setX(pivot.x() - width);
	} break;
	case PIVOT_MIDDLE_LEFT : {
		pivot.setY(pivot.y() - 0.5 * height);
	} break;
	case PIVOT_MIDDLE_CENTER : {
		pivot.setX(pivot.x() - 0.5 * width);
		pivot.setY(pivot.y() - 0.5 * height);
	} break;
	case PIVOT_MIDDLE_RIGHT : {
		pivot.setX(pivot.x() - width);
		pivot.setY(pivot.y() - 0.5 * height);
	} break;
	case PIVOT_TOP_LEFT : {
		pivot.setY(pivot.y() - height);
	} break;
	case PIVOT_TOP_CENTER : {
		pivot.setX(pivot.x() - 0.5 * width);
		pivot.setY(pivot.y() - height);
	} break;
	case PIVOT_TOP_RIGHT : {
		pivot.setX(pivot.x() - width);
		pivot.setY(pivot.y() - height);
	}
	}
	return pivot;
}

} // namespace WPlot
