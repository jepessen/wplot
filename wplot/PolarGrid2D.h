#ifndef WPLOT_POLARGRID2D_H_
#define WPLOT_POLARGRID2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Layer2D.h"
#include <QColor>
#include <QPen>
#include <memory>

namespace WPlot {

class WPLOTSHARED_EXPORT PolarGrid2D : public Layer2D
{
public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<PolarGrid2D> Ptr;

public:

	PolarGrid2D();
	virtual ~PolarGrid2D() = default;
	void setPrimaryAngleStep(const double &step);
	void setSecondaryAngleStep(const double &step);
	void setPrimaryRadiusStep(const double &step);
	void setSecondaryRadiusStep(const double &step);
	void setPrimaryAngleColor(const QColor &color);
	void setSecondaryAngleColor(const QColor &color);
	void setPrimaryRadiusColor(const QColor &color);
	void setSecondaryRadiusColor(const QColor &color);
	void setPrimaryColor(const QColor &color);
	void setSecondaryColor(const QColor &color);
	void setGridColor(const QColor &color);
	void setBoundaryColor(const QColor &color);
	void setColor(const QColor &color);
	void setPrimaryAngleStyle(const Qt::PenStyle &style);
	void setSecondaryAngleStyle(const Qt::PenStyle &style);
	void setPrimaryRadiusStyle(const Qt::PenStyle &style);
	void setSecondaryRadiusStyle(const Qt::PenStyle &style);
	void setPrimaryStyle(const Qt::PenStyle &style);
	void setSecondaryStyle(const Qt::PenStyle &style);
	void setGridStyle(const Qt::PenStyle &style);
	void setBoundaryStyle(const Qt::PenStyle &style);
	void setStyle(const Qt::PenStyle &style);
	void setPrimaryAngleWidth(const double &width);
	void setSecondaryAngleWidth(const double &width);
	void setPrimaryRadiusWidth(const double &width);
	void setSecondaryRadiusWidth(const double &width);
	void setPrimaryWidth(const double &width);
	void setSecondaryWidth(const double &width);
	void setGridWidth(const double &width);
	void setBoundaryWidth(const double &width);
	void setWidth(const double &width);

public:

	virtual void draw(Plot2D *plot) Q_DECL_OVERRIDE;
	virtual void drawLines(Plot2D *plot);
	virtual void drawBoundary(Plot2D *plot);

private:

	void initializeDrawing(Plot2D *plot);
	void drawGridAngle(Plot2D *plot);
	void drawGridRadius(Plot2D *plot);
	void drawGridBoundary(Plot2D *plot);

private:

	QPointF m_upperLeftCorner;
	QPointF m_lowerRightCorner;
	QPointF m_screenCenter;
	double m_screenRadius;
	double m_primaryAngleStep;
	double m_secondaryAngleStep;
	double m_primaryRadiusStep;
	double m_secondaryRadiusStep;
	QColor m_primaryAngleColor;
	QColor m_secondaryAngleColor;
	QColor m_primaryRadiusColor;
	QColor m_secondaryRadiusColor;
	QColor m_boundaryColor;
	Qt::PenStyle m_primaryAngleStyle;
	Qt::PenStyle m_secondaryAngleStyle;
	Qt::PenStyle m_primaryRadiusStyle;
	Qt::PenStyle m_secondaryRadiusStyle;
	Qt::PenStyle m_boundaryStyle;
	double m_primaryAngleWidth;
	double m_secondaryAngleWidth;
	double m_primaryRadiusWidth;
	double m_secondaryRadiusWidth;
	double m_boundaryWidth;
	QPen m_primaryAnglePen;
	QPen m_secondaryAnglePen;
	QPen m_primaryRadiusPen;
	QPen m_secondaryRadiusPen;
	QPen m_boundaryPen;
	std::pair<double, double> m_radiusLimits;
};

} // namespace WPlot

#endif // WPLOT_POLARGRID2D_H_

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
