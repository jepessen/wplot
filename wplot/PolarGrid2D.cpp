#include "wplot/PolarGrid2D.h"
#include "wplot/Plot2D.h"
#include "wplot/PolarPlot2D.h"
#include "wplot/Private/LinearTicksCalculator.h"
#include <QPainter>
#include <QDebug>
#include <cmath>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// USING SECTION                                                             //
///////////////////////////////////////////////////////////////////////////////

using Private::LinearTicksCalculator;

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

PolarGrid2D::PolarGrid2D() :
	Layer2D(),
	m_upperLeftCorner(-1.0, 1.0),
	m_lowerRightCorner(1.0, -1.0),
	m_screenRadius(double()),
	m_primaryAngleStep(M_PI_2),
	m_secondaryAngleStep(M_PI_4),
	m_primaryRadiusStep(1.0),
	m_secondaryRadiusStep(0.5),
	m_primaryAngleColor(Qt::black),
	m_secondaryAngleColor(Qt::black),
	m_primaryRadiusColor(Qt::black),
	m_secondaryRadiusColor(Qt::black),
	m_boundaryColor(Qt::black),
	m_primaryAngleStyle(Qt::SolidLine),
	m_secondaryAngleStyle(Qt::DashLine),
	m_primaryRadiusStyle(Qt::SolidLine),
	m_secondaryRadiusStyle(Qt::DashLine),
	m_boundaryStyle(Qt::SolidLine),
	m_primaryAngleWidth(1.0),
	m_secondaryAngleWidth(1.0),
	m_primaryRadiusWidth(1.0),
	m_secondaryRadiusWidth(1.0),
	m_boundaryWidth(2.0),
	m_primaryAnglePen(),
	m_secondaryAnglePen(),
	m_primaryRadiusPen(),
	m_secondaryRadiusPen(),
	m_boundaryPen(),
	m_radiusLimits(double(), double())
{
	m_primaryAnglePen.setWidthF(m_primaryAngleWidth);
	m_primaryAnglePen.setStyle(m_primaryAngleStyle);
	m_primaryAnglePen.setColor(m_primaryAngleColor);

	m_secondaryAnglePen.setWidthF(m_secondaryAngleWidth);
	m_secondaryAnglePen.setStyle(m_secondaryAngleStyle);
	m_secondaryAnglePen.setColor(m_secondaryAngleColor);

	m_primaryRadiusPen.setWidthF(m_primaryRadiusWidth);
	m_primaryRadiusPen.setStyle(m_primaryRadiusStyle);
	m_primaryRadiusPen.setColor(m_primaryRadiusColor);

	m_secondaryRadiusPen.setWidthF(m_secondaryRadiusWidth);
	m_secondaryRadiusPen.setStyle(m_secondaryRadiusStyle);
	m_secondaryRadiusPen.setColor(m_secondaryRadiusColor);

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
void PolarGrid2D::setPrimaryAngleStep(const double &step) {
	m_primaryAngleStep = step;
}

/**
 * Set the step for secondary grid lines of the \f$X\f$ axis.
 *
 * @param[in] step Step.
 */
void PolarGrid2D::setSecondaryAngleStep(const double &step) {
	m_secondaryAngleStep = step;
}

/**
 * Set the step for primary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] step Step.
 */
void PolarGrid2D::setPrimaryRadiusStep(const double &step) {
	m_primaryRadiusStep = step;
}

/**
 * Set the step for secondary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] step Step.
 */
void PolarGrid2D::setSecondaryRadiusStep(const double &step) {
	m_secondaryRadiusStep = step;
}

/**
 * Set the color for primary grid lines of the \f$X\f$ axis.
 *
 * @param[in] color Color.
 */
void PolarGrid2D::setPrimaryAngleColor(const QColor &color) {
	m_primaryAngleColor = color;
	m_primaryAnglePen.setColor(color);
}

/**
 * Set the color for secondary grid lines of the \f$X\f$ axis.
 *
 * @param[in] color Color.
 */
void PolarGrid2D::setSecondaryAngleColor(const QColor &color) {
	m_secondaryAngleColor = color;
	m_secondaryAnglePen.setColor(color);
}

/**
 * Set the color for primary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] color Color.
 */
void PolarGrid2D::setPrimaryRadiusColor(const QColor &color) {
	m_primaryRadiusColor = color;
	m_primaryRadiusPen.setColor(color);
}

/**
 * Set the color for secondary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] color Color.
 */
void PolarGrid2D::setSecondaryRadiusColor(const QColor &color) {
	m_secondaryRadiusColor = color;
	m_secondaryRadiusPen.setColor(color);
}

/**
 * Set the color for primary grid lines in both axis.
 *
 * @param[in] color Color.
 */
void PolarGrid2D::setPrimaryColor(const QColor &color) {
	setPrimaryAngleColor(color);
	setPrimaryRadiusColor(color);
}

/**
 * Set the color for secondary grid lines in both axis.
 *
 * @param[in] color Color.
 */
void PolarGrid2D::setSecondaryColor(const QColor &color) {
	setSecondaryAngleColor(color);
	setSecondaryRadiusColor(color);
}

/**
 * Set the color for primary and secondary grid lines in both axis.
 *
 * @param[in] color Color.
 */
void PolarGrid2D::setGridColor(const QColor &color) {
	setPrimaryColor(color);
	setSecondaryColor(color);
}

/**
 * Set the color for boundary rectangle.
 *
 * @param[in] color Color.
 */
void PolarGrid2D::setBoundaryColor(const QColor &color) {
	m_boundaryColor = color;
	m_boundaryPen.setColor(color);
}

/**
 * Set the color for the entire grid.
 *
 * @param[in] color Color.
 */
void PolarGrid2D::setColor(const QColor &color) {
	setGridColor(color);
	setBoundaryColor(color);
}

/**
 * Set the style for primary grid lines of the \f$X\f$ axis.
 *
 * @param[in] style Style.
 */
void PolarGrid2D::setPrimaryAngleStyle(const Qt::PenStyle &style) {
	m_primaryAngleStyle = style;
	m_primaryAnglePen.setStyle(style);
}

/**
 * Set the style for secondary grid lines of the \f$X\f$ axis.
 *
 * @param[in] style Style.
 */
void PolarGrid2D::setSecondaryAngleStyle(const Qt::PenStyle &style) {
	m_secondaryAngleStyle = style;
	m_secondaryAnglePen.setStyle(style);
}

/**
 * Set the style for primary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] style Style.
 */
void PolarGrid2D::setPrimaryRadiusStyle(const Qt::PenStyle &style) {
	m_primaryRadiusStyle = style;
	m_primaryRadiusPen.setStyle(style);
}

/**
 * Set the style for secondary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] style Style.
 */
void PolarGrid2D::setSecondaryRadiusStyle(const Qt::PenStyle &style) {
	m_secondaryRadiusStyle = style;
	m_secondaryRadiusPen.setStyle(style);
}

/**
 * Set the style for primary lines.
 *
 * @param[in] style Style.
 */
void PolarGrid2D::setPrimaryStyle(const Qt::PenStyle &style) {
	setPrimaryAngleStyle(style);
	setPrimaryRadiusStyle(style);
}

/**
 * Set the style for secondary lines.
 *
 * @param[in] style Style.
 */
void PolarGrid2D::setSecondaryStyle(const Qt::PenStyle &style) {
	setSecondaryAngleStyle(style);
	setSecondaryRadiusStyle(style);
}

/**
 * Set the style for all grid lines.
 *
 * @param[in] style Style.
 */
void PolarGrid2D::setGridStyle(const Qt::PenStyle &style) {
	setPrimaryStyle(style);
	setSecondaryStyle(style);
}

/**
 * Set the style for boundary rectangle.
 *
 * @param[in] style Style.
 */
void PolarGrid2D::setBoundaryStyle(const Qt::PenStyle &style) {
	m_boundaryStyle = style;
	m_boundaryPen.setStyle(style);
}

/**
 * Set the style for entire grid.
 *
 * @param[in] style Style.
 */
void PolarGrid2D::setStyle(const Qt::PenStyle &style) {
	setGridStyle(style);
	setBoundaryStyle(style);
}

/**
 * Set the width in pixels for primary grid lines of the \f$X\f$ axis.
 *
 * @param[in] width Width.
 */
void PolarGrid2D::setPrimaryAngleWidth(const double &width) {
	m_primaryAngleWidth = width;
	m_primaryAnglePen.setWidthF(width);
}

/**
 * Set the width in pixels for secondary grid lines of the \f$X\f$ axis.
 *
 * @param[in] width Width.
 */
void PolarGrid2D::setSecondaryAngleWidth(const double &width) {
	m_secondaryAngleWidth = width;
	m_secondaryAnglePen.setWidthF(width);
}

/**
 * Set the width in pixels for primary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] width Width.
 */
void PolarGrid2D::setPrimaryRadiusWidth(const double &width) {
	m_primaryRadiusWidth = width;
	m_primaryRadiusPen.setWidthF(width);
}

/**
 * Set the width in pixels for secondary grid lines of the \f$Y\f$ axis.
 *
 * @param[in] width Width.
 */
void PolarGrid2D::setSecondaryRadiusWidth(const double &width) {
	m_secondaryRadiusWidth = width;
	m_secondaryRadiusPen.setWidthF(width);
}

/**
 * Set the width for primary lines in both axis.
 *
 * @param[in] width Width.
 */
void PolarGrid2D::setPrimaryWidth(const double &width) {
	setPrimaryAngleWidth(width);
	setPrimaryRadiusWidth(width);
}

/**
 * Set the width for secondary lines in both axis.
 *
 * @param[in] width Width.
 */
void PolarGrid2D::setSecondaryWidth(const double &width) {
	setSecondaryAngleWidth(width);
	setSecondaryRadiusWidth(width);
}

/**
 * Set the width for grid lines.
 *
 * @param[in] width Width.
 */
void PolarGrid2D::setGridWidth(const double &width) {
	setPrimaryWidth(width);
	setSecondaryWidth(width);
}

/**
 * Set the width in pixels for boundary rectangle.
 *
 * @param[in] width Width.
 */
void PolarGrid2D::setBoundaryWidth(const double &width) {
	m_boundaryWidth = width;
	m_boundaryPen.setWidthF(width);
}

/**
 * Set the width for the entire grid.
 *
 * @param[in] width Width.
 */
void PolarGrid2D::setWidth(const double &width) {
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
void PolarGrid2D::draw(Plot2D *plot) {
	initializeDrawing(plot);
	drawGridAngle(plot);
	drawGridRadius(plot);
	drawGridBoundary(plot);
}

void PolarGrid2D::drawLines(Plot2D *plot) {
	initializeDrawing(plot);
	drawGridAngle(plot);
	drawGridRadius(plot);
}

void PolarGrid2D::drawBoundary(Plot2D *plot) {
	initializeDrawing(plot);
	drawGridBoundary(plot);
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                           //
///////////////////////////////////////////////////////////////////////////////

void PolarGrid2D::initializeDrawing(Plot2D *plot) {
	PolarPlot2D *polarPlot = dynamic_cast<PolarPlot2D*>(plot);
	if (nullptr == polarPlot) {
		return;
	}
	m_radiusLimits = polarPlot->getRadiusLimits();
	const double screenSemiHeight = plot->height() * 0.5;
	const double screenSemiWidth = plot->width() * 0.5;
	m_screenCenter.setX(screenSemiWidth);
	m_screenCenter.setY(screenSemiHeight);
	const auto screenPadding = plot->getPixelPadding();
	const double screenHorizontalRadius = screenSemiWidth - std::max(screenPadding.left, screenPadding.right);
	const double screenVerticalRadius = screenSemiHeight - std::max(screenPadding.top, screenPadding.bottom);
	m_screenRadius = std::min(screenHorizontalRadius, screenVerticalRadius);
}

/**
 * Draw grid lines for \f$X\f$ axis.
 *
 * @param[inout] plot Plot.
 */
void PolarGrid2D::drawGridAngle(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	painter.setPen(m_secondaryAnglePen);
	for (double angle = 0.0; angle < M_PI * 2.0; angle += m_secondaryAngleStep) {
		const double x = m_screenRadius * sin(angle) + m_screenCenter.x();
		const double y = m_screenRadius * cos(angle) + m_screenCenter.y();
		painter.drawLine(m_screenCenter, QPointF(x, y));
	}
	painter.setPen(m_primaryAnglePen);
	for (double angle = 0.0; angle < M_PI * 2.0; angle += m_primaryAngleStep) {
		const double x = m_screenRadius * sin(angle) + m_screenCenter.x();
		const double y = m_screenRadius * cos(angle) + m_screenCenter.y();
		painter.drawLine(m_screenCenter, QPointF(x, y));
	}
}

/**
 * Draw grid lines for \f$Y\f$ axis.
 *
 * @param[inout] plot Plot.
 */
void PolarGrid2D::drawGridRadius(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	LinearTicksCalculator ticksCalculator;
	ticksCalculator.setStep(m_secondaryRadiusStep);
	ticksCalculator.setLimits(m_radiusLimits.first, m_radiusLimits.second);
	const auto secondaryTicks = ticksCalculator.getTicks();
	painter.setPen(m_secondaryRadiusPen);
	for (const auto& it : secondaryTicks) {
		const double multiplier = (it - m_radiusLimits.first) / (m_radiusLimits.second - m_radiusLimits.first);
		const double step = m_screenRadius * multiplier;
		painter.drawEllipse(m_screenCenter, step, step);
	}
	painter.setPen(m_primaryRadiusPen);
	ticksCalculator.setStep(m_primaryRadiusStep);
	const auto primaryTicks = ticksCalculator.getTicks();
	painter.setPen(m_primaryRadiusPen);
	for (const auto& it : primaryTicks) {
		const double multiplier = (it - m_radiusLimits.first) / (m_radiusLimits.second - m_radiusLimits.first);
		const double step = m_screenRadius * multiplier;
		painter.drawEllipse(m_screenCenter, step, step);
	}
}

/**
 * Draw grid lines for boundary rectangle.
 *
 * @param[inout] plot Plot.
 */
void PolarGrid2D::drawGridBoundary(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	const double screenSemiHeight = plot->height() * 0.5;
	const double screenSemiWidth = plot->width() * 0.5;
	const QPointF screenCenter(screenSemiWidth, screenSemiHeight);
	const auto screenPadding = plot->getPixelPadding();
	const double screenHorizontalRadius = screenSemiWidth - std::max(screenPadding.left, screenPadding.right);
	const double screenVerticalRadius = screenSemiHeight - std::max(screenPadding.top, screenPadding.bottom);
	const double screenRadius = std::min(screenHorizontalRadius, screenVerticalRadius);
	painter.setPen(m_boundaryPen);
	painter.drawEllipse(screenCenter, screenRadius, screenRadius);
}

} // namespace WPlot
