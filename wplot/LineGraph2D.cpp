#include "wplot/LineGraph2D.h"
#include "wplot/Plot2D.h"
#include <QPainter>
#include <QImage>

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
	m_colorFunctionDefined = false;
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
 *
 * @internal It's not possible do define
 */
void LineGraph2D::draw(Plot2D *plot) {
	if (false == m_colorFunctionDefined) {
		drawSolidColorLine(plot);
	} else {
		drawGradientLine(plot);
	}
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                           //
///////////////////////////////////////////////////////////////////////////////

void LineGraph2D::drawSolidColorLine(Plot2D *plot) {
	if (m_data.size() < 2) {
		return;
	}
	QPolygonF points;
	QPainter painter(plot);
	plot->initializePainter(painter);
	painter.setPen(m_pen);
	for (const auto& it : m_data) {
		points.append(plot->scalePoint(it));
	}
	painter.drawPolyline(points);
}

void LineGraph2D::drawGradientLine(Plot2D *plot) {
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
		points.append(plot->scalePoint(it));
	}
	painter.drawPolyline(points);
	//Draw gradient
	painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
	// For every line segment draw the corresponding gradient region
	const int size = m_data.size();
	for (int i = 1; i < size; i++) {
		const auto firstCorner = plot->scalePoint(m_data.at(i-1));
		const auto secondCorner = plot->scalePoint(m_data.at(i));
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
				QRgb color = m_colorFunction(colorPoint).rgba();
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

} // namespace WPlot
