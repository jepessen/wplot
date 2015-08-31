#ifndef WPLOT_ITEM2D_H_
#define WPLOT_ITEM2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Layer2D.h"
#include <QPointF>
#include <QSizeF>
#include <memory>

namespace WPlot {

class WPLOTSHARED_EXPORT Item2D : public Layer2D
{
public:

	/** Pointer to this class. */
	typedef std::shared_ptr<Item2D> Ptr;

	/** Type of coordinate that can be used. */
	typedef enum {
		COORDINATE_WIDGET, //!< Original widget coordinates.
		COORDINATE_PLOT,   //!< Plot coordinates.
		COORDINATE_SCALED  //!< Scaled coordinates (from 0 to 1).
	} CoordinateType;

	/**
	 * Axis direction for coordinate type.
	 */
	typedef enum {
		AXIS_X,   //!< Scaling of X axis for both coordinates.
		AXIS_Y,   //!< Scaling of Y axis for both coordinates.
		AXIS_BOTH //!< Every axis is indipendently scaled.
	} AxisType;

public:

	Item2D();
	virtual ~Item2D() = default;
	void setCoordinates(const CoordinateType &type, const AxisType &axisType);
	void setPivotCoordinates(const CoordinateType &type, const AxisType &axisType);
	void setDimensionCoordinates(const CoordinateType &type, const AxisType &axisType);
	void setPivot(const QPointF &pivot);
	void setPivot(const double &x, const double &y);
	QPointF getScaledPosition(const QPointF &coords, const Plot2D *plot) const;
	QPointF getScaledPosition(const double &x, const double &y, const Plot2D *plot) const;
	double getScaledPositionX(const double &x, const Plot2D *plot) const;
	double getScaledPositionY(const double &y, const Plot2D *plot) const;
	QPointF getScaledDimensions(const QPointF &dimensions, const Plot2D *plot) const;
	QPointF getScaledDimensions(const QSizeF &dimensions, const Plot2D *plot) const;
	QPointF getScaledDimensions(const double &x, const double &y, const Plot2D *plot) const;
	double getScaledDimensionX(const double &x, const Plot2D *plot) const;
	double getScaledDimensionY(const double &y, const Plot2D *plot) const;

protected:

	AxisType m_positionAxisType;
	AxisType m_dimensionsAxisType;
	CoordinateType m_positionCoordinateType;
	CoordinateType m_dimensionsCoordinateType;
	QPointF m_pivot;
};

} // namespace WPlot

#endif // WPLOT_ITEM2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Item2D
 *
 * This class is a base class for all items that can be drawn to plot. It
 * contains helper methods that allows to take easily into account different
 * coordinate systems. A coordinate system can be set for its position and its
 * dimension, and these can be different. I.e. Is possible to set the plot
 * coordinate system for position and the widget coordinate system for dimension
 * in order to give more flexibility in drawing.
 */
