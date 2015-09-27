#include "wplot/PolarLineGraph2D.h"
#include "wplot/Plot2D.h"
#include "wplot/PolarPlot2D.h"
#include <QPainter>
#include <QImage>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

PolarLineGraph2D::PolarLineGraph2D() :
	PolarScalarGraph2D(),
	m_lineColor(Qt::black),
	m_fillColor(0, 0, 0, 0),
	m_lineWidth(1.0),
	m_fillColorYCoordinate(0.0)
{
	m_pen.setColor(m_lineColor);
	m_pen.setWidthF(m_lineWidth);
}

/**
 * Set the color of the line.
 *
 * @param[in] color Color.
 */
void PolarLineGraph2D::setLineColor(const QColor &color) {
	m_lineColor = color;
	m_pen.setColor(color);
	m_colorFunctionDefined = false;
}

void PolarLineGraph2D::setLineStyle(const Qt::PenStyle &style) {
	m_style = style;
	m_pen.setStyle(style);
}

/**
 * Set the color for filling.
 *
 * @param[in] color Color.
 */
void PolarLineGraph2D::setFillColor(const QColor &color) {
	m_fillColor = color;
}

/**
 * Set the coordinate that must be used in order to create the filling.
 *
 * @param[in] coordinate Coordinate.
 */
void PolarLineGraph2D::setFillYCoordinate(const double &coordinate) {
	m_fillColorYCoordinate = coordinate;
}

/**
 * Set the width of the line in pixels.
 *
 * @param[in] width Width.
 */
void PolarLineGraph2D::setLineWidth(const double &width) {
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
 *
 * @internal It's not possible do define
 */
void PolarLineGraph2D::draw(Plot2D *plot) {
	if (m_fillColor.alpha() != 0) {
		drawFilling(plot);
	}
	if (false == m_colorFunctionDefined) {
		drawSolidColorLine(plot);
	} else {
		drawGradientLine(plot);
	}
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                           //
///////////////////////////////////////////////////////////////////////////////

void PolarLineGraph2D::drawSolidColorLine(Plot2D *plot) {
	PolarPlot2D *polarPlot = dynamic_cast<PolarPlot2D*>(plot);
	if (nullptr == polarPlot) {
		return;
	}
	if (m_data.size() < 2) {
		return;
	}
	QPolygonF points;
	QPainter painter(plot);
	plot->initializePainter(painter);
	painter.setPen(m_pen);
	for (const auto& it : m_data) {
		points.append(polarPlot->scalePolarPoint(it));
	}
	painter.drawPolyline(points);
}

void PolarLineGraph2D::drawGradientLine(Plot2D *plot) {
	PolarPlot2D *polarPlot = dynamic_cast<PolarPlot2D*>(plot);
	if (nullptr == polarPlot) {
		return;
	}
	if (m_data.size() < 2) {
		return;
	}
	QImage image(plot->size(), QImage::Format_ARGB32_Premultiplied);
	QPolygonF points;
	QPainter painter(&image);
	plot->initializePainter(painter);
	m_pen.setColor(Qt::white);
	painter.setCompositionMode(QPainter::CompositionMode_Source);
	painter.setPen(m_pen);
	for (auto& it : m_data) {
		points.append(polarPlot->scalePolarPoint(it));
	}
	painter.drawPolyline(points);
	//Draw gradient
	painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
	// For every line segment draw the corresponding gradient region
	const int size = m_data.size();
	for (int i = 1; i < size; i++) {
		const auto firstCorner = polarPlot->scalePolarPoint(m_data.at(i-1));
		const auto secondCorner = polarPlot->scalePolarPoint(m_data.at(i));
		const int xMin = std::min(firstCorner.x(), secondCorner.x()) - 2.0 * m_lineWidth;
		const int xMax = std::max(firstCorner.x(), secondCorner.x()) + 2.0 * m_lineWidth;
		const int yMin = std::min(firstCorner.y(), secondCorner.y()) - 2.0 * m_lineWidth;
		const int yMax = std::max(firstCorner.y(), secondCorner.y()) + 2.0 * m_lineWidth;
		const QPoint topLeftCorner(xMin, yMin);
		const QPoint bottomRightCorner(xMax, yMax);
		QImage gradientImage(xMax - xMin, yMax - yMin, QImage::Format_ARGB32);
		int lineNumber = 0;
		int columnNumber = 0;
		for (int y = yMin; y < yMax; y++) {
			QRgb *colorLine = reinterpret_cast<QRgb*>(gradientImage.scanLine(lineNumber));
			for (int x = xMin; x < xMax; x++) {
				const QPointF colorPoint(plot->inverseScalePoint(x, y));
				QRgb color = m_colorFunction(colorPoint.x(), colorPoint.y()).rgba();
				colorLine[columnNumber] = color;
				columnNumber++;
			}
			lineNumber++;
			columnNumber = 0;
		}
		painter.drawImage(QRect(topLeftCorner, bottomRightCorner), gradientImage);
	}

	QPainter plotPainter(plot);
	plot->initializePainter(plotPainter);
	plotPainter.drawImage(0, 0, image);
}

void PolarLineGraph2D::drawFilling(Plot2D *plot) {
	PolarPlot2D *polarPlot = dynamic_cast<PolarPlot2D*>(plot);
	if (nullptr == polarPlot) {
		return;
	}
	if (m_data.size() < 2) {
		return;
	}
	QPainter painter(plot);
	QPen pen;
	QPolygonF polygon;
	QBrush brush;
	brush.setColor(m_fillColor);
	brush.setStyle(Qt::SolidPattern);
	painter.setBrush(brush);
	pen.setBrush(brush);
	painter.setPen(pen);
	for (const auto& it : m_data) {
		polygon << polarPlot->scalePolarPoint(it);
	}
	polygon << polarPlot->scalePolarPoint(m_data.back().x(), m_fillColorYCoordinate);
	polygon << polarPlot->scalePolarPoint(m_data.front().x(), m_fillColorYCoordinate);
	painter.drawPolygon(polygon);

}

} // namespace WPlot
