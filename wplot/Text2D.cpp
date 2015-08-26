#include "wplot/Text2D.h"
#include "wplot/Plot2D.h"

namespace WPlot {

Text2D::Text2D() :
	Item2D(),
	m_fontSize(10.0),
	m_font(),
	m_color(Qt::black),
	m_text()
{
	m_pen.setColor(m_color);
}

void Text2D::setText(const QString &text) {
	m_text = text;
}

void Text2D::setFont(const QFont &font) {
	m_font = font;
}

void Text2D::setFontSize(const double &size) {
	m_fontSize = size;
}

void Text2D::setColor(const QColor &color) {
	m_color = color;
	m_pen.setColor(color);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void Text2D::draw(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	limitPainterInPaddingArea(painter, plot);
	const QPointF pivot = getScaledPosition(m_pivot, plot);
	m_font.setPixelSize(m_fontSize);
	painter.setPen(m_pen);
	painter.setFont(m_font);
	painter.drawText(pivot, m_text);
}

} // namespace WPlot
