#include "wplot/Layer.h"
#include "wplot/Plot.h"

namespace WPlot {

//////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                           //
//////////////////////////////////////////////////////////////////////////////

Layer::Layer()
{}

///////////////////////////////////////////////////////////////////////////////
// PROTECTED SECTION                                                         //
///////////////////////////////////////////////////////////////////////////////

/**
 * Initialize a painter. This should be called before drawing.
 *
 * @param[inout] painter Painter.
 * @param[in] plot Plot.
 */
void Layer::initPainter(QPainter &painter, Plot* plot) {
	if (true == plot->getAntialiasingFlag()) {
		painter.setRenderHint(QPainter::Antialiasing);
	}
}

} // namespace WPlot
