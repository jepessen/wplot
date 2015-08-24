#ifndef WPLOT_PLOT_H_
#define WPLOT_PLOT_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Layer.h"
#include "wplot/Background.h"
#include "wplot/Padding.h"
#include <QWidget>
#include <QPainter>

namespace WPlot {

class WPLOTSHARED_EXPORT Plot : public QWidget
{
	Q_OBJECT

public:
	Plot(QWidget *parent = 0);
	virtual ~Plot() = default;

	void setBackground(const Background::Ptr &background);
	void setAntialiasingFlag(const bool &flag);
	bool getAntialiasingFlag() const;
	void setPadding(const Padding &padding);
	void setPadding(const double &padding, const Padding::Type &type);
	Padding::Values getPixelPadding() const;

public:

	virtual QPointF getScreenOrigin() const = 0;
	virtual double getScaleX() const = 0;
	virtual double getScaleY() const = 0;
	virtual void initializePainter(QPainter &painter);

protected:

	virtual void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
	void drawBackground();

protected:

	bool m_useAntialiasing;
	Background::Ptr m_background;
	Padding m_padding;
};

} // namespace WPlot

#endif // WPLOT_PLOT_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Plot
 *
 * This is the base class for plotting. This specify a widget in which graphs
 * and items can be drawn.
 */
