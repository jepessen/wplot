#ifndef WPLOT_PADDING_H_
#define WPLOT_PADDING_H_

namespace WPlot {

class Padding {

public:

	/**
	 * This enumerator specifies the unit of measure of padding values.
	 */
	typedef enum {
		PIXELS, //!< Values are given in pixels.
		PERCENT //!< Values are given in percent related to plot dimensions.
	} Type;

	/**
	 * Struct that contain values of padding in all directions.
	 */
	typedef struct {
		double left;
		double right;
		double bottom;
		double top;
	} Values;

public:
	Padding();
	Padding(const double &size, const Type &type);
	Padding(const double &leftSize, const double &rightSize, const double &bottomSize, const double &topSize, const Type &type);
	virtual ~Padding() = default;
	void setSize(const double &width, const double &height);
	void setPadding(const double &size, const Type &type);
	void setLeftPadding(const double &size, const Type &type);
	void setRightPadding(const double &size, const Type &type);
	void setBottomPadding(const double &size, const Type &type);
	void setTopPadding(const double &size, const Type &type);
	double getLeftPadding(const Type &type) const;
	double getRightPadding(const Type &type) const;
	double getBottomPadding(const Type &type) const;
	double getTopPadding(const Type &type) const;
	Values getPaddingValues(const Type &type) const;

private:

	double getPixelPadding(const double &size, const Type &type, const double &dimension) const;
	double getPercentPadding(const double &size, const Type &type, const double &dimension) const;

private:

	double m_leftPadding;
	double m_rightPadding;
	double m_bottomPadding;
	double m_topPadding;
	double m_width;
	double m_height;
	Type m_leftType;
	Type m_rightType;
	Type m_bottomType;
	Type m_topType;
};

} // namespace WPlot

#endif // WPLOT_PADDING_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Padding
 *
 * This class allows to set and specify padding for a plot. The padding is the
 * space between the widget border and the region in which the plot is drawn.
 *
 * Padding can be set for every direction (top, botto, left, right) and is
 * possible to set different unit measure.
 */
