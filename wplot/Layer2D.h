#ifndef WPLOT_LAYER2D_H_
#define WPLOT_LAYER2D_H_

#include "wplot/Layer.h"
#include <memory>

namespace WPlot {

class Plot2D;

class Layer2D : public Layer
{
public:

	/** Shared pointer to this class. */
	typedef std::shared_ptr<Layer2D> Ptr;

public:

	Layer2D();
	virtual ~Layer2D() = default;

public:

	virtual void draw(Plot2D *plot) = 0;
};

} // namespace WPlot

#endif // WPLOT_LAYER2D_H_

/**
 * @class WPlot::Layer2D
 *
 * This class is a specialization of WPlot::Layer for layers that must be drawn
 * inside a Plot2D, so for bidimensional layers.
 */
