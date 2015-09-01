#include "wplot/ScatterGraph2D.h"
#include "wplot/Plot2D.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

ScatterGraph2D::ScatterGraph2D() :
	ScalarGraph2D(),
	m_item(nullptr)
{}

/**
 * Set the item that will be used as point indicator.
 *
 * @param[in] item Item.
 */
void ScatterGraph2D::setItem(const Item2D::Ptr &item) {
	m_item = item;
	m_item->setPivotCoordinates(Item2D::COORDINATE_PLOT, Item2D::AXIS_BOTH);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void ScatterGraph2D::draw(Plot2D *plot) {
	m_item->setDrawingInPaddingArea(true);
	for (auto& it : m_data) {
		m_item->setPivot(it);
		m_item->draw(plot);
	}
}

} // namespace WPlot
