#include "wplot/Plot.h"
#include <QPainter>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

Plot::Plot(QWidget *parent) :
	QWidget(parent),
	m_useAntialiasing(true),
	m_background(nullptr)
{}

void Plot::setBackground(const Background::Ptr &background) {
	if (background == nullptr) {
		return;
	}
	m_background = background;
}

/**
 * Specify if antialiasing must be used in drawing.
 *
 * @param flag true if antialiasing is desired.
 */
void Plot::setAntialiasingFlag(const bool &flag) {
	m_useAntialiasing = flag;
}

/**
 * Retrieve the antialiasing flag that specifies if antialiasing must
 * be applied.
 *
 * @return Flag.
 */
bool Plot::getAntialiasingFlag() const {
	return m_useAntialiasing;
}

/**
 * Set the plot padding.
 *
 * @param[in] padding Padding.
 */
void Plot::setPadding(const Padding &padding) {
	m_padding = padding;
}

/**
 * Set the plot padding.
 *
 * @param[in] padding Padding value.
 * @param[in] type Padding type.
 */
void Plot::setPadding(const double &padding, const Padding::Type &type) {
	m_padding.setPadding(padding, type);
}

/**
 * Retrieve padding values in pixels.
 *
 * @return Padding values.
 */
Padding::Values Plot::getPixelPadding() const {
	return m_padding.getPaddingValues(Padding::PIXELS);
}

/**
 * Initialize the painter.
 *
 * @param[in] painter Painter.
 */
void Plot::initializePainter(QPainter &painter) {
	if (true == m_useAntialiasing) {
		painter.setRenderHints(QPainter::Antialiasing, true);
	}
}

///////////////////////////////////////////////////////////////////////////////
// PROTECTED SECTION                                                         //
///////////////////////////////////////////////////////////////////////////////

/**
 * Perform drawing. All layers will be drawn starting from the one with the
 * lowest index.
 *
 * @param event Painting event.
 */
void Plot::paintEvent(QPaintEvent * /*event*/) {
	drawBackground();
}

/**
 * Draw the background if set.
 */
void Plot::drawBackground() {
	if (nullptr != m_background) {
		m_background->draw(this);
	}
}

} // namespace WPlot
