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

void ScatterGraph2D::setItem(const Item2D::Ptr &item) {
	m_item = item;
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void ScatterGraph2D::draw(Plot2D *plot) {
	for (auto& it : m_data) {
		m_item->setPivot(it);
		m_item->draw(plot);
	}
}

} // namespace WPlot
