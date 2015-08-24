#include "wplot/Padding.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

Padding::Padding() :
	m_leftPadding(double()),
	m_rightPadding(double()),
	m_bottomPadding(double()),
	m_topPadding(double()),
	m_width(double()),
	m_height(double()),
	m_leftType(PIXELS),
	m_rightType(PIXELS),
	m_bottomType(PIXELS),
	m_topType(PIXELS)
{}

Padding::Padding(const double &size, const Type &type) :
	m_leftPadding(size),
	m_rightPadding(size),
	m_bottomPadding(size),
	m_topPadding(size),
	m_width(double()),
	m_height(double()),
	m_leftType(type),
	m_rightType(type),
	m_bottomType(type),
	m_topType(type)
{}

Padding::Padding(const double &leftSize, const double &rightSize, const double &bottomSize, const double &topSize, const Type &type) :
	m_leftPadding(leftSize),
	m_rightPadding(rightSize),
	m_bottomPadding(bottomSize),
	m_topPadding(topSize),
	m_width(double()),
	m_height(double()),
	m_leftType(type),
	m_rightType(type),
	m_bottomType(type),
	m_topType(type)
{}

/**
 * Set plot widget dimensions in pixels.
 *
 * @param[in] width Width.
 * @param[in] height Height.
 */
void Padding::setSize(const double &width, const double &height) {
	m_width = width;
	m_height = height;
}

/**
 * Set the same padding for all four borders.
 *
 * @param[in] size Size.
 * @param[in] type Padding type.
 */
void Padding::setPadding(const double &size, const Type &type) {
	setLeftPadding(size, type);
	setRightPadding(size, type);
	setBottomPadding(size, type);
	setTopPadding(size, type);
}

/**
 * Set the padding for left border.
 *
 * @param[in] size Size of the padding.
 * @param[in] type Padding type.
 */
void Padding::setLeftPadding(const double &size, const Type &type) {
	m_leftPadding = size;
	m_leftType = type;
}

/**
 * Set the padding for right border.
 *
 * @param[in] size Size of the padding.
 * @param[in] type Padding type.
 */
void Padding::setRightPadding(const double &size, const Type &type) {
	m_rightPadding = size;
	m_rightType = type;
}

/**
 * Set the padding for bottom border.
 *
 * @param[in] size Size of the padding.
 * @param[in] type Padding type.
 */
void Padding::setBottomPadding(const double &size, const Type &type) {
	m_bottomPadding = size;
	m_bottomType = type;
}

/**
 * Set the padding for top border.
 *
 * @param[in] size Size of the padding.
 * @param[in] type Padding type.
 */
void Padding::setTopPadding(const double &size, const Type &type) {
	m_topPadding = size;
	m_topType = type;
}

/**
 * Retrieve the value for left padding.
 *
 * @param[in] type Coordinate type in which padding must be returned.
 *
 * @return Padding value.
 */
double Padding::getLeftPadding(const Type &type) const {
	if (PERCENT == type) {
		return getPercentPadding(m_leftPadding, m_leftType, m_width);
	}
	return getPixelPadding(m_leftPadding, m_leftType, m_width);
}

/**
 * Retrieve the value for right padding.
 *
 * @param[in] type Coordinate type in which padding must be returned.
 *
 * @return Padding value.
 */
double Padding::getRightPadding(const Type &type) const {
	if (PERCENT == type) {
		return getPercentPadding(m_rightPadding, m_rightType, m_width);
	}
	return getPixelPadding(m_rightPadding, m_rightType, m_width);
}

/**
 * Retrieve the value for bottom padding.
 *
 * @param[in] type Coordinate type in which padding must be returned.
 *
 * @return Padding value.
 */
double Padding::getBottomPadding(const Type &type) const {
	if (PERCENT == type) {
		return getPercentPadding(m_bottomPadding, m_bottomType, m_height);
	}
	return getPixelPadding(m_bottomPadding, m_bottomType, m_height);
}

/**
 * Retrieve the value for top padding.
 *
 * @param[in] type Coordinate type in which padding must be returned.
 *
 * @return Padding value.
 */
double Padding::getTopPadding(const Type &type) const {
	if (PERCENT == type) {
		return getPercentPadding(m_topPadding, m_topType, m_height);
	}
	return getPixelPadding(m_topPadding, m_topType, m_height);
}

/**
 * Retrieve the padding value for all borders.
 *
 * @param[in] type Coordinate type in which padding must be returned.
 *
 * @return Padding values.
 */
Padding::Values Padding::getPaddingValues(const Type &type) const {
	Values values;
	values.left = getLeftPadding(type);
	values.right = getRightPadding(type);
	values.bottom = getBottomPadding(type);
	values.top = getTopPadding(type);
	return values;
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
 * Retrieve the padding in pixel coordinates.
 *
 * @param[in] size Padding value.
 * @param[in] type Padding type.
 * @param[in] dimension Widget dimension.
 *
 * @return Padding in pixel coordinate.
 */
double Padding::getPixelPadding(const double &size, const Type &type, const double &dimension) const {
	if (type == PIXELS) {
		return size;
	}
	return dimension * 0.01 * size;
}

/**
 * Retrieve the padding in percent coordinates.
 *
 * @param[in] size Padding value.
 * @param[in] type Padding type.
 * @param[in] dimension Widget dimension.
 *
 * @return Padding in percent coordinate.
 */
double Padding::getPercentPadding(const double &size, const Type &type, const double &dimension) const {
	if (type == PERCENT) {
		return size;
	}
	return size / dimension * 100.0;
}

} // namespace WPlot
