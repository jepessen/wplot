#include "wplot/CartesianGrid2D.h"
#include "wplot/Plot2D.h"
#include "wplot/Private/LinearTicksCalculator.h"
#include <QPainter>
#include <QDebug>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// USING SECTION                                                             //
///////////////////////////////////////////////////////////////////////////////

using Private::LinearTicksCalculator;

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

CartesianGrid2D::CartesianGrid2D() :
	Layer2D(),
	m_upperLeftCorner(-1.0, 1.0),
	m_lowerRightCorner(1.0, -1.0),
	m_primaryXStep(1.0),
	m_secondaryXStep(0.5),
	m_primaryYStep(1.0),
	m_secondaryYStep(0.5),
	m_primaryXColor(Qt::black),
	m_secondaryXColor(Qt::black),
	m_primaryYColor(Qt::black),
	m_secondaryYColor(Qt::black),
	m_boundaryColor(Qt::black),
	m_primaryXStyle(Qt::SolidLine),
	m_secondaryXStyle(Qt::DashLine),
	m_primaryYStyle(Qt::SolidLine),
	m_secondaryYStyle(Qt::DashLine),
	m_boundaryStyle(Qt::SolidLine),
	m_primaryXWidth(1.0),
	m_secondaryXWidth(1.0),
	m_primaryYWidth(1.0),
	m_secondaryYWidth(1.0),
	m_boundaryWidth(2.0),
	m_primaryXPen(),
	m_secondaryXPen(),
	m_primaryYPen(),
	m_secondaryYPen(),
	m_boundaryPen()
{
	m_primaryXPen.setWidthF(m_primaryXWidth);
	m_primaryXPen.setStyle(m_primaryXStyle);
	m_primaryXPen.setColor(m_primaryXColor);

	m_secondaryXPen.setWidthF(m_secondaryXWidth);
	m_secondaryXPen.setStyle(m_secondaryXStyle);
	m_secondaryXPen.setColor(m_secondaryXColor);

	m_primaryYPen.setWidthF(m_primaryYWidth);
	m_primaryYPen.setStyle(m_primaryYStyle);
	m_primaryYPen.setColor(m_primaryYColor);

	m_secondaryYPen.setWidthF(m_secondaryYWidth);
	m_secondaryYPen.setStyle(m_secondaryYStyle);
	m_secondaryYPen.setColor(m_secondaryYColor);

	m_boundaryPen.setWidthF(m_boundaryWidth);
	m_boundaryPen.setStyle(m_boundaryStyle);
	m_boundaryPen.setColor(m_boundaryColor);
	m_boundaryPen.setJoinStyle(Qt::RoundJoin);
}

/**
 * Set the step for primary grid lines of the \f$X\f$ axis.
 *
 * @param[in] step Step.
 */
void CartesianGrid2D::setPrimaryXStep(const double &step) {
	m_primaryXStep = step;
}

/**
 * Set the step for secondary grid lines of the \f$X\f$ axis.
 *
 * @param[in] step Step.
 */
void CartesianGrid2D::setSecondaryXStep(const double &step) {
	m_secondaryXStep = step;
}

/**
 * Set the step for primary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] step Step.
 */
void CartesianGrid2D::setPrimaryYStep(const double &step) {
	m_primaryYStep = step;
}

/**
 * Set the step for secondary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] step Step.
 */
void CartesianGrid2D::setSecondaryYStep(const double &step) {
	m_secondaryYStep = step;
}

/**
 * Set the primay step for both axis.
 *
 * @param[in] step Step.
 */
void CartesianGrid2D::setPrimaryStep(const double &step) {
	setPrimaryXStep(step);
	setPrimaryYStep(step);
}

/**
 * Set the secondary step for both axis.
 *
 * @param[in] step Step.
 */
void CartesianGrid2D::setSecondaryStep(const double &step) {
	setSecondaryXStep(step);
	setSecondaryYStep(step);
}

/**
 * Set the color for primary grid lines of the \f$X\f$ axis.
 *
 * @param[in] color Color.
 */
void CartesianGrid2D::setPrimaryXColor(const QColor &color) {
	m_primaryXColor = color;
	m_primaryXPen.setColor(color);
}

/**
 * Set the color for secondary grid lines of the \f$X\f$ axis.
 *
 * @param[in] color Color.
 */
void CartesianGrid2D::setSecondaryXColor(const QColor &color) {
	m_secondaryXColor = color;
	m_secondaryXPen.setColor(color);
}

/**
 * Set the color for primary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] color Color.
 */
void CartesianGrid2D::setPrimaryYColor(const QColor &color) {
	m_primaryYColor = color;
	m_primaryYPen.setColor(color);
}

/**
 * Set the color for secondary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] color Color.
 */
void CartesianGrid2D::setSecondaryYColor(const QColor &color) {
	m_secondaryYColor = color;
	m_secondaryYPen.setColor(color);
}

/**
 * Set the color for primary grid lines in both axis.
 *
 * @param[in] color Color.
 */
void CartesianGrid2D::setPrimaryColor(const QColor &color) {
	setPrimaryXColor(color);
	setPrimaryYColor(color);
}

/**
 * Set the color for secondary grid lines in both axis.
 *
 * @param[in] color Color.
 */
void CartesianGrid2D::setSecondaryColor(const QColor &color) {
	setSecondaryXColor(color);
	setSecondaryYColor(color);
}

/**
 * Set the color for primary and secondary grid lines in both axis.
 *
 * @param[in] color Color.
 */
void CartesianGrid2D::setGridColor(const QColor &color) {
	setPrimaryColor(color);
	setSecondaryColor(color);
}

/**
 * Set the color for boundary rectangle.
 *
 * @param[in] color Color.
 */
void CartesianGrid2D::setBoundaryColor(const QColor &color) {
	m_boundaryColor = color;
	m_boundaryPen.setColor(color);
}

/**
 * Set the color for the entire grid.
 *
 * @param[in] color Color.
 */
void CartesianGrid2D::setColor(const QColor &color) {
	setGridColor(color);
	setBoundaryColor(color);
}

/**
 * Set the style for primary grid lines of the \f$X\f$ axis.
 *
 * @param[in] style Style.
 */
void CartesianGrid2D::setPrimaryXStyle(const Qt::PenStyle &style) {
	m_primaryXStyle = style;
	m_primaryXPen.setStyle(style);
}

/**
 * Set the style for secondary grid lines of the \f$X\f$ axis.
 *
 * @param[in] style Style.
 */
void CartesianGrid2D::setSecondaryXStyle(const Qt::PenStyle &style) {
	m_secondaryXStyle = style;
	m_secondaryXPen.setStyle(style);
}

/**
 * Set the style for primary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] style Style.
 */
void CartesianGrid2D::setPrimaryYStyle(const Qt::PenStyle &style) {
	m_primaryYStyle = style;
	m_primaryYPen.setStyle(style);
}

/**
 * Set the style for secondary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] style Style.
 */
void CartesianGrid2D::setSecondaryYStyle(const Qt::PenStyle &style) {
	m_secondaryYStyle = style;
	m_secondaryYPen.setStyle(style);
}

/**
 * Set the style for primary lines.
 *
 * @param[in] style Style.
 */
void CartesianGrid2D::setPrimaryStyle(const Qt::PenStyle &style) {
	setPrimaryXStyle(style);
	setPrimaryYStyle(style);
}

/**
 * Set the style for secondary lines.
 *
 * @param[in] style Style.
 */
void CartesianGrid2D::setSecondaryStyle(const Qt::PenStyle &style) {
	setSecondaryXStyle(style);
	setSecondaryYStyle(style);
}

/**
 * Set the style for all grid lines.
 *
 * @param[in] style Style.
 */
void CartesianGrid2D::setGridStyle(const Qt::PenStyle &style) {
	setPrimaryStyle(style);
	setSecondaryStyle(style);
}

/**
 * Set the style for boundary rectangle.
 *
 * @param[in] style Style.
 */
void CartesianGrid2D::setBoundaryStyle(const Qt::PenStyle &style) {
	m_boundaryStyle = style;
	m_boundaryPen.setStyle(style);
}

/**
 * Set the style for entire grid.
 *
 * @param[in] style Style.
 */
void CartesianGrid2D::setStyle(const Qt::PenStyle &style) {
	setGridStyle(style);
	setBoundaryStyle(style);
}

/**
 * Set the width in pixels for primary grid lines of the \f$X\f$ axis.
 *
 * @param[in] width Width.
 */
void CartesianGrid2D::setPrimaryXWidth(const double &width) {
	m_primaryXWidth = width;
	m_primaryXPen.setWidthF(width);
}

/**
 * Set the width in pixels for secondary grid lines of the \f$X\f$ axis.
 *
 * @param[in] width Width.
 */
void CartesianGrid2D::setSecondaryXWidth(const double &width) {
	m_secondaryXWidth = width;
	m_secondaryXPen.setWidthF(width);
}

/**
 * Set the width in pixels for primary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] width Width.
 */
void CartesianGrid2D::setPrimaryYWidth(const double &width) {
	m_primaryYWidth = width;
	m_primaryYPen.setWidthF(width);
}

/**
 * Set the width in pixels for secondary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] width Width.
 */
void CartesianGrid2D::setSecondaryYWidth(const double &width) {
	m_secondaryYWidth = width;
	m_secondaryYPen.setWidthF(width);
}

/**
 * Set the width for primary lines in both axis.
 *
 * @param[in] width Width.
 */
void CartesianGrid2D::setPrimaryWidth(const double &width) {
	setPrimaryXWidth(width);
	setPrimaryYWidth(width);
}

/**
 * Set the width for secondary lines in both axis.
 *
 * @param[in] width Width.
 */
void CartesianGrid2D::setSecondaryWidth(const double &width) {
	setSecondaryXWidth(width);
	setSecondaryYWidth(width);
}

/**
 * Set the width for grid lines.
 *
 * @param[in] width Width.
 */
void CartesianGrid2D::setGridWidth(const double &width) {
	setPrimaryWidth(width);
	setSecondaryWidth(width);
}

/**
 * Set the width in pixels for boundary rectangle.
 *
 * @param[in] width Width.
 */
void CartesianGrid2D::setBoundaryWidth(const double &width) {
	m_boundaryWidth = width;
	m_boundaryPen.setWidthF(width);
}

/**
 * Set the width for the entire grid.
 *
 * @param[in] width Width.
 */
void CartesianGrid2D::setWidth(const double &width) {
	setGridWidth(width);
	setBoundaryWidth(width);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw the grid.
 *
 * @param[inout] plot Plot.
 */
void CartesianGrid2D::draw(Plot2D *plot) {
	drawGridX(plot);
	drawGridY(plot);
	drawGridBoundary(plot);
}

void CartesianGrid2D::drawLines(Plot2D *plot) {
	drawGridX(plot);
	drawGridY(plot);
}

void CartesianGrid2D::drawBoundary(Plot2D *plot) {
	drawGridBoundary(plot);
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw grid lines for \f$X\f$ axis.
 *
 * @param[inout] plot Plot.
 */
void CartesianGrid2D::drawGridX(Plot2D *plot) {
	QPainter painter(plot);
	const auto upperLeftLimits = plot->getUpperLeftCorner();
	const auto lowerRightLimits = plot->getLowerRightCorner();
	const auto upperLeftCorner = plot->scalePoint(upperLeftLimits);
	const auto lowerRightCorner = plot->scalePoint(lowerRightLimits);
	painter.setPen(m_secondaryXPen);
	LinearTicksCalculator ticksCalculator;
	ticksCalculator.setStep(m_secondaryXStep);
	ticksCalculator.setLimits(upperLeftLimits.x(), lowerRightLimits.x());
	const auto secondaryTicks = ticksCalculator.getTicks();
	for (const auto& x : secondaryTicks) {
		const double scaledX = plot->scalePointX(x);
		painter.drawLine(scaledX, upperLeftCorner.y(), scaledX, lowerRightCorner.y());
	}
	painter.setPen(m_primaryXPen);
	ticksCalculator.setStep(m_primaryXStep);
	const auto primaryTicks = ticksCalculator.getTicks();
	for (const auto& x : primaryTicks) {
		const double scaledX = plot->scalePointX(x);
		painter.drawLine(scaledX, upperLeftCorner.y(), scaledX, lowerRightCorner.y());
	}
}

/**
 * Draw grid lines for \f$Y\f$ axis.
 *
 * @param[inout] plot Plot.
 */
void CartesianGrid2D::drawGridY(Plot2D *plot) {
	QPainter painter(plot);
	const auto upperLeftLimits = plot->getUpperLeftCorner();
	const auto lowerRightLimits = plot->getLowerRightCorner();
	const auto upperLeftCorner = plot->scalePoint(upperLeftLimits);
	const auto lowerRightCorner = plot->scalePoint(lowerRightLimits);
	painter.setPen(m_secondaryYPen);
	LinearTicksCalculator ticksCalculator;
	ticksCalculator.setStep(m_secondaryYStep);
	ticksCalculator.setLimits(lowerRightLimits.y(), upperLeftLimits.y());
	const auto secondaryTicks = ticksCalculator.getTicks();
	for (const auto& y : secondaryTicks) {
		const double scaledY = plot->scalePointY(y);
		painter.drawLine(upperLeftCorner.x(), scaledY, lowerRightCorner.x(), scaledY);
	}
	painter.setPen(m_primaryYPen);
	ticksCalculator.setStep(m_primaryYStep);
	const auto primaryTicks = ticksCalculator.getTicks();
	for (const auto& y : primaryTicks) {
		const double scaledY = plot->scalePointY(y);
		painter.drawLine(upperLeftCorner.x(), scaledY, lowerRightCorner.x(), scaledY);
	}
}

/**
 * Draw grid lines for boundary rectangle.
 *
 * @param[inout] plot Plot.
 */
void CartesianGrid2D::drawGridBoundary(Plot2D *plot) {
	QPainter painter(plot);
	painter.setPen(m_boundaryPen);
	auto upperLeftCorner = plot->scalePoint(plot->getUpperLeftCorner());
	auto lowerRightCorner = plot->scalePoint(plot->getLowerRightCorner());
	const double w = lowerRightCorner.x() - upperLeftCorner.x();
	const double h = upperLeftCorner.y() - lowerRightCorner.y();
	painter.drawRect(upperLeftCorner.x(), lowerRightCorner.y(), w, h);
}

} // namespace WPlot
