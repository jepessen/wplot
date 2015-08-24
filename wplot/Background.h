#ifndef WPLOT_BACKGROUND_H_
#define WPLOT_BACKGROUND_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Layer.h"
#include <QColor>
#include <QGradient>
#include <memory>

namespace WPlot {

class Plot;

class WPLOTSHARED_EXPORT Background : public Layer
{
public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<Background> Ptr;

public:

	Background();
	virtual ~Background() = default;
	void setColor(const QColor &color);
	void setGradient(const QGradient &gradient);

public:

	virtual void draw(Plot *plot);

private:

	void drawFlatBackground(Plot *plot);
	void drawGradientBackground(Plot *plot);

private:

	/** Background type */
	typedef enum {
		FLAT,    //!< Flat color is used.
		GRADIENT //!< Gradient is used.
	} Type;
	
private:

	QColor m_color;
	QGradient m_gradient;
	Type m_type;
};

} // namespace WPlot

#endif // WPLOT_BACKGROUND_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Background
 *
 * This class specify the background that must be added to the plot.
 * It's possible to set the background as color or as gradient. It's possibile
 * to define both of them, and then use it in a Plot.
 *
 * @note This class will fill the entire widget, so it should be used in a plot
 *       with the lowest index.
 */
