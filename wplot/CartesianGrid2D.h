#ifndef WPLOT_CARTESIANGRID2D_H_
#define WPLOT_CARTESIANGRID2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Layer2D.h"
#include <QColor>
#include <QPen>
#include <memory>

namespace WPlot {

class WPLOTSHARED_EXPORT CartesianGrid2D : public Layer2D
{
public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<CartesianGrid2D> Ptr;

public:

	CartesianGrid2D();
	virtual ~CartesianGrid2D() = default;
	void setPrimaryXStep(const double &step);
	void setSecondaryXStep(const double &step);
	void setPrimaryYStep(const double &step);
	void setSecondaryYStep(const double &step);
	void setPrimaryStep(const double &step);
	void setSecondaryStep(const double &step);
	void setPrimaryXColor(const QColor &color);
	void setSecondaryXColor(const QColor &color);
	void setPrimaryYColor(const QColor &color);
	void setSecondaryYColor(const QColor &color);
	void setPrimaryColor(const QColor &color);
	void setSecondaryColor(const QColor &color);
	void setGridColor(const QColor &color);
	void setBoundaryColor(const QColor &color);
	void setColor(const QColor &color);
	void setPrimaryXStyle(const Qt::PenStyle &style);
	void setSecondaryXStyle(const Qt::PenStyle &style);
	void setPrimaryYStyle(const Qt::PenStyle &style);
	void setSecondaryYStyle(const Qt::PenStyle &style);
	void setPrimaryStyle(const Qt::PenStyle &style);
	void setSecondaryStyle(const Qt::PenStyle &style);
	void setGridStyle(const Qt::PenStyle &style);
	void setBoundaryStyle(const Qt::PenStyle &style);
	void setStyle(const Qt::PenStyle &style);
	void setPrimaryXWidth(const double &width);
	void setSecondaryXWidth(const double &width);
	void setPrimaryYWidth(const double &width);
	void setSecondaryYWidth(const double &width);
	void setPrimaryWidth(const double &width);
	void setSecondaryWidth(const double &width);
	void setGridWidth(const double &width);
	void setBoundaryWidth(const double &width);
	void setWidth(const double &width);

public:

	virtual void draw(Plot2D *plot) Q_DECL_OVERRIDE;
	virtual void drawLines(Plot2D *plot);
	virtual void drawBoundary(Plot2D *plot);

protected:

	QPointF m_upperLeftCorner;
	QPointF m_lowerRightCorner;
	double m_primaryXStep;
	double m_secondaryXStep;
	double m_primaryYStep;
	double m_secondaryYStep;
	QColor m_primaryXColor;
	QColor m_secondaryXColor;
	QColor m_primaryYColor;
	QColor m_secondaryYColor;
	QColor m_boundaryColor;
	Qt::PenStyle m_primaryXStyle;
	Qt::PenStyle m_secondaryXStyle;
	Qt::PenStyle m_primaryYStyle;
	Qt::PenStyle m_secondaryYStyle;
	Qt::PenStyle m_boundaryStyle;
	double m_primaryXWidth;
	double m_secondaryXWidth;
	double m_primaryYWidth;
	double m_secondaryYWidth;
	double m_boundaryWidth;
	QPen m_primaryXPen;
	QPen m_secondaryXPen;
	QPen m_primaryYPen;
	QPen m_secondaryYPen;
	QPen m_boundaryPen;

private:

	void drawGridX(Plot2D *plot);
	void drawGridY(Plot2D *plot);
	void drawGridBoundary(Plot2D *plot);
};

} // namespace WPlot

#endif // WPLOT_CARTESIANGRID2D_H_

/**
 * @class WPlot::CartesianGrid2D
 *
 * This class allows to draw a 2D grid inside the cartesian plot.
 *
 * The gris is used in order to give lines that allows the user to read graph
 * values more easily.
 *
 * For both \f$X\f$ and \f$Y\f$ axes is possibile to define the primary and
 * secondary step of grid lines, as well as style and colors.
 */
