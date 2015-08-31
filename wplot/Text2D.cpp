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

/**
 * Set the text.
 *
 * @param[in] text Text.
 */
void Text2D::setText(const QString &text) {
	m_text = text;
}

/**
 * Set the text font.
 *
 * @param[in] font Font.
 */
void Text2D::setFont(const QFont &font) {
	m_font = font;
}

/**
 * Set the size of the font.
 *
 * @param[in] size Size.
 */
void Text2D::setFontSize(const double &size) {
	m_fontSize = size;
}

/**
 * Set the color of the font.
 *
 * @para[in] color Color.
 */
void Text2D::setColor(const QColor &color) {
	m_color = color;
	m_pen.setColor(color);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw the text.
 *
 * @param[inout] plot Plot where text must be plotted.
 */
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
