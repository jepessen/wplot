#ifndef WPLOT_LAYER_H_
#define WPLOT_LAYER_H_

#include "wplot/WPlotGlobal.h"
#include <QWidget>
#include <memory>

namespace WPlot {

class Plot;

class WPLOTSHARED_EXPORT Layer
{
public:

	/** Shared pointer to this class. */
	typedef std::shared_ptr<Layer> Ptr;

public:

	Layer();
	virtual ~Layer() = default;

protected:

	virtual void initPainter(QPainter &painter, Plot* plot);
};

} // namespace WPlot

#endif // WPLOT_LAYER_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Layer
 *
 * This class is a base class for all plot layers. A layer represent something
 * that can be drawn to the plot.
 */
