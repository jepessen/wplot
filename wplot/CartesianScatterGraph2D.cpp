#include "wplot/CartesianScatterGraph2D.h"
#include "wplot/Plot2D.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

CartesianScatterGraph2D::CartesianScatterGraph2D() :
	CartesianScalarGraph2D(),
	m_item(nullptr)
{}

/**
 * Set the item that will be used as point indicator.
 *
 * @param[in] item Item.
 */
void CartesianScatterGraph2D::setItem(const Item2D::Ptr &item) {
	m_item = item;
	m_item->setPivotCoordinates(Item2D::COORDINATE_PLOT, Item2D::AXIS_BOTH);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void CartesianScatterGraph2D::draw(Plot2D *plot) {
	m_item->setDrawingInPaddingArea(true);
	for (auto& it : m_data) {
		m_item->setPivot(it);
		if (true == m_colorFunctionDefined) {
			m_item->setColor(m_colorFunction(it));
		}
		m_item->draw(plot);
	}
}

} // namespace WPlot
