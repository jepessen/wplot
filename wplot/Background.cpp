#include "wplot/Background.h"
#include "wplot/Plot.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

Background::Background() :
	Layer(),
	m_color(),
	m_gradient(),
	m_type(FLAT)
{}

/**
 * Set the color that must be used with flat color.
 *
 * @param[in] color Color.
 */
void Background::setColor(const QColor &color) {
	m_color = color;
	m_type = Background::FLAT;
}

/**
 * Set the gradient that must be used with gradient mode.
 *
 * @param[in] gradient Gradient.
 */
void Background::setGradient(const QGradient &gradient) {
	m_gradient = gradient;
	m_type = Background::GRADIENT;
}

/**
 * Fills the widget with the background.
 *
 * @param[inout] plot Plot that should be filled.
 */
void Background::draw(Plot *plot) {
	switch (m_type) {
	case FLAT : {
		drawFlatBackground(plot);
	} break;
	case GRADIENT : {
		drawGradientBackground(plot);
	} break;
	default : {
		drawFlatBackground(plot);
	}
	}
}

//////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                          //
//////////////////////////////////////////////////////////////////////////////

/**
 * Fills the widget with a flat background.
 *
 * @param[inout] plot Plot.
 */
void Background::drawFlatBackground(Plot *plot) {
	plot->setAutoFillBackground(true);
	QPalette plotPalette(plot->palette());
	plotPalette.setColor(QPalette::Background, m_color);
	plot->setPalette(plotPalette);
}

/**
 * Fills the widget with the gradient background.
 *
 * @param[inout] plot Plot.
 */
void Background::drawGradientBackground(Plot *plot) {
	QPalette plotPalette(plot->palette());
	plotPalette.setBrush(QPalette::Window, *(new QBrush(m_gradient)));
	plot->setPalette(plotPalette);
}

} // namespace WPlot

