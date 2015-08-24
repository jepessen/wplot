#include "wplot/Item2D.h"
#include "wplot/Plot2D.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

Item2D::Item2D() :
	Layer2D(),
	m_positionAxisType(AXIS_BOTH),
	m_dimensionsAxisType(AXIS_BOTH),
	m_positionCoordinateType(COORDINATE_WIDGET),
	m_dimensionsCoordinateType(COORDINATE_WIDGET)
{}

/**
 * Set the coordinate system for both axes.
 *
 * @param[in] type Coordiante type.
 * @param[in] axisType Axis type.
 */
void Item2D::setCoordinates(const Item2D::CoordinateType &type, const Item2D::AxisType &axisType) {
	setPivotCoordinates(type, axisType);
	setDimensionCoordinates(type, axisType);
}

/**
 * Set the coordinate sistem for item position.
 *
 * @param[in] type Coordiante type.
 * @param[in] axisType Axis type.
 */
void Item2D::setPivotCoordinates(const Item2D::CoordinateType &type, const Item2D::AxisType &axisType) {
	m_positionCoordinateType = type;
	m_positionAxisType = axisType;
}

/**
 * Set the coordinate sistem for item dimensions.
 *
 * @param[in] type Coordiante type.
 * @param[in] axisType Axis type.
 */
void Item2D::setDimensionCoordinates(const Item2D::CoordinateType &type, const Item2D::AxisType &axisType) {
	m_dimensionsCoordinateType = type;
	m_dimensionsAxisType = axisType;
}

/**
 * Set the item pivot. This is used in order to place the item inside the plot.
 *
 * @param[in] pivot Pivot coordinates.
 */
void Item2D::setPivot(const QPointF &pivot) {
	m_pivot = pivot;
}

/**
 * Set the item pivot. This is used in order to place the item inside the plot.
 *
 * @param[in] x \f$X\f$ coordinate.
 * @param[in] y \f$Y\f$ coordinate.
 */
void Item2D::setPivot(const double &x, const double &y) {
	m_pivot.setX(x);
	m_pivot.setY(y);
}

/**
 * Retrieve the position in scaled coordinates, that are widget ones.
 *
 * @param[in] coords Coordinates in specified system.
 * @param[in] plot Plot.
 *
 * @return Coordinates in widget system.
 */
QPointF Item2D::getScaledPosition(const QPointF &coords, const Plot2D *plot) const {
	return getScaledPosition(coords.x(), coords.y(), plot);
}

/**
 * Retrieve the position in scaled coordinates, that are widget ones.
 *
 * @param[in] x \f$X\f$ coordinate.
 * @param[in] y \f$Y\f$ coordinate.
 * @param[in] plot Plot.
 *
 * @return Coordinates in widget system.
 */
QPointF Item2D::getScaledPosition(const double &x, const double &y, const Plot2D *plot) const {
	return QPointF(getScaledPositionX(x, plot), getScaledPositionY(y, plot));
}

/**
 * Retrieve the \f$X\f$ coordinate in scaled coordinates, that are widget ones.
 *
 * @param[in] x \f$X\f$ coordinate.
 * @param[in] plot Plot.
 *
 * @return Coordinates in widget system.
 */
double Item2D::getScaledPositionX(const double &x, const Plot2D *plot) const {
	switch(m_positionCoordinateType) {
	case COORDINATE_PLOT : {
		return m_positionAxisType == AXIS_Y ? plot->scalePointY(x) : plot->scalePointX(x);
	} break;
	case COORDINATE_SCALED : {
		const int dim = m_positionAxisType == AXIS_Y ? plot->height() : plot->width();
		return static_cast<double>(dim) * x;
	} break;
	case COORDINATE_WIDGET :
	default : {
		return x;
	}
	}
	return double();
}

/**
 * Retrieve the \f$Y\f$ coordinate in scaled coordinates, that are widget ones.
 *
 * @param[in] y \f$Y\f$ coordinate.
 * @param[in] plot Plot.
 *
 * @return Coordinates in widget system.
 */
double Item2D::getScaledPositionY(const double &y, const Plot2D *plot) const {
	switch(m_positionCoordinateType) {
	case COORDINATE_PLOT : {
		return m_positionAxisType == AXIS_X ? plot->scalePointX(y) : plot->scalePointY(y);
	} break;
	case COORDINATE_SCALED : {
		const int dim = m_positionAxisType == AXIS_X ? plot->width() : plot->height();
		return static_cast<double>(dim) * y;
	} break;
	case COORDINATE_WIDGET :
	default : {
		return y;
	}
	}
	return double();
}

/**
 * Retrieve the dimensions in scaled coordinates, that are widget ones.
 *
 * @param[in] dimensions Dimensions in specified system.
 * @param[in] plot Plot.
 *
 * @return Dimensions in widget system.
 */
QPointF Item2D::getScaledDimensions(const QPointF &dimensions, const Plot2D *plot) const {
	return getScaledDimensions(dimensions.x(), dimensions.y(), plot);
}

/**
 * Retrieve the dimensions in scaled coordinates, that are widget ones.
 *
 * @param[in] dimensions Dimensions in specified system.
 * @param[in] plot Plot.
 *
 * @return Dimensions in widget system.
 */
QPointF Item2D::getScaledDimensions(const QSizeF &dimensions, const Plot2D *plot) const {
	return getScaledDimensions(dimensions.width(), dimensions.height(), plot);
}

/**
 * Retrieve the dimensions in scaled coordinates, that are widget ones.
 *
 * @param[in] x \f$X\f$ dimension.
 * @param[in] y \f$Y\f$ dimension.
 * @param[in] plot Plot.
 *
 * @return Dimensions in widget system.
 */
QPointF Item2D::getScaledDimensions(const double &x, const double &y, const Plot2D *plot) const {
	return QPointF(getScaledDimensionX(x, plot), getScaledDimensionY(y, plot));
}

/**
 * Retrieve the \f$X\f$ dimension in scaled coordinates, that are widget ones.
 *
 * @param[in] x \f$X\f$ dimension.
 * @param[in] plot Plot.
 *
 * @return Dimension.
 */
double Item2D::getScaledDimensionX(const double &x, const Plot2D *plot) const {
	switch(m_dimensionsCoordinateType) {
	case COORDINATE_PLOT : {
		const auto origin = plot->getScreenOrigin();
		return m_dimensionsAxisType == AXIS_Y ? plot->scalePointY(x) - origin.y() : plot->scalePointX(x) - origin.x();
	} break;
	case COORDINATE_SCALED : {
		const int dim = m_dimensionsAxisType == AXIS_Y ? plot->height() : plot->width();
		return static_cast<double>(dim) * x;
	} break;
	case COORDINATE_WIDGET :
	default : {
		return x;
	}
	}
	return double();
}

/**
 * Retrieve the \f$Y\f$ dimension in scaled coordinates, that are widget ones.
 *
 * @param[in] y \f$Y\f$ dimension.
 * @param[in] plot Plot.
 *
 * @return Dimension.
 */
double Item2D::getScaledDimensionY(const double &y, const Plot2D *plot) const {
	switch(m_dimensionsCoordinateType) {
	case COORDINATE_PLOT : {
		const auto origin = plot->getScreenOrigin();
		return m_dimensionsAxisType == AXIS_X ? plot->scalePointX(y) - origin.x() : plot->scalePointY(y) - origin.y();
	} break;
	case COORDINATE_SCALED : {
		const int dim = m_dimensionsAxisType == AXIS_X ? plot->width() : plot->height();
		return static_cast<double>(dim) * y;
	} break;
	case COORDINATE_WIDGET :
	default : {
		return y;
	}
	}
	return double();
}

} // namespace WPlot
