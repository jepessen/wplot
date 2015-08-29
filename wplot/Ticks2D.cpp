#include "wplot/Ticks2D.h"
#include "wplot/Plot2D.h"
#include "wplot/Private/LinearTicksCalculator.h"
#include <QDateTime>
#include <QTime>
#include <QFontMetrics>
#include <cmath>
#include <iostream>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// USING SECTION                                                             //
///////////////////////////////////////////////////////////////////////////////

using Private::LinearTicksCalculator;

///////////////////////////////////////////////////////////////////////////////
// STATIC DECLARATION SECTION                                                //
///////////////////////////////////////////////////////////////////////////////

namespace {
	const double defaultPrimaryStep(1.0);
	const double defaultSecondaryStep(0.5);
	const double defaultWidth(1.0);
	const double defaultLabelDistance(2.0);
}

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

Ticks2D::Ticks2D() :
	Layer2D(),
	m_axisXPrimaryStep(defaultPrimaryStep),
	m_axisXSecondaryStep(defaultSecondaryStep),
	m_axisYPrimaryStep(defaultPrimaryStep),
	m_axisYSecondaryStep(defaultSecondaryStep),
	m_axisXWidth(defaultWidth),
	m_axisYWidth(defaultWidth),
	m_axisXPrimaryTickLength(5.0),
	m_axisXSecondaryTickLength(2.0),
	m_axisYPrimaryTickLength(5.0),
	m_axisYSecondaryTickLength(2.0),
	m_axisXPrimaryTickWidth(defaultWidth),
	m_axisXSecondaryTickWidth(defaultWidth),
	m_axisYPrimaryTickWidth(defaultWidth),
	m_axisYSecondaryTickWidth(defaultWidth),
	m_axisXLabelDistance(defaultLabelDistance),
	m_axisYLabelDistance(defaultLabelDistance),
	m_axisXPrimaryTickStyle(Qt::SolidLine),
	m_axisXSecondaryTickStyle(Qt::SolidLine),
	m_axisYPrimaryTickStyle(Qt::SolidLine),
	m_axisYSecondaryTickStyle(Qt::SolidLine),
	m_axisXPrimaryTickColor(Qt::black),
	m_axisXSecondaryTickColor(Qt::black),
	m_axisYPrimaryTickColor(Qt::black),
	m_axisYSecondaryTickColor(Qt::black),
	m_axisXFont(),
	m_axisYFont(),
	m_axisXFormatType(FORMAT_FLOAT),
	m_axisYFormatType(FORMAT_FLOAT),
	m_labelEnabled(false),
	m_origin() {
	m_axisXPrimaryTickPen.setStyle(m_axisXPrimaryTickStyle);
	m_axisXPrimaryTickPen.setColor(m_axisXPrimaryTickColor);
	m_axisXPrimaryTickPen.setWidthF(m_axisXPrimaryTickWidth);
	m_axisXSecondaryTickPen.setStyle(m_axisXSecondaryTickStyle);
	m_axisXSecondaryTickPen.setColor(m_axisXSecondaryTickColor);
	m_axisXSecondaryTickPen.setWidthF(m_axisXSecondaryTickWidth);
	m_axisYPrimaryTickPen.setStyle(m_axisYPrimaryTickStyle);
	m_axisYPrimaryTickPen.setColor(m_axisYPrimaryTickColor);
	m_axisYPrimaryTickPen.setWidthF(m_axisYPrimaryTickWidth);
	m_axisYSecondaryTickPen.setStyle(m_axisYSecondaryTickStyle);
	m_axisYSecondaryTickPen.setColor(m_axisYSecondaryTickColor);
	m_axisYSecondaryTickPen.setWidthF(m_axisYSecondaryTickWidth);
	m_axisXFont.setPixelSize(10);
	m_axisYFont.setPixelSize(10);
	m_axisXTextOptions.setAlignment(Qt::AlignHCenter);
	m_axisYTextOptions.setAlignment(Qt::AlignRight);
}

void Ticks2D::setXPrimaryStep(const double &step) {
	m_axisXPrimaryStep = step;
}

void Ticks2D::setXSecondaryStep(const double &step) {
	m_axisXSecondaryStep = step;
}

void Ticks2D::setYPrimaryStep(const double &step) {
	m_axisYPrimaryStep = step;
}

void Ticks2D::setYSecondaryStep(const double &step) {
	m_axisYSecondaryStep = step;
}

void Ticks2D::setPrimaryStep(const double &step) {
	setXPrimaryStep(step);
	setYPrimaryStep(step);
}

void Ticks2D::setSecondaryStep(const double &step) {
	setXSecondaryStep(step);
	setYSecondaryStep(step);
}

void Ticks2D::setXPrimaryTickLength(const double &length) {
	m_axisXPrimaryTickLength = length;
}

void Ticks2D::setXSecondaryTickLength(const double &length) {
	m_axisXSecondaryTickLength = length;
}

void Ticks2D::setPrimaryTickLength(const double &length) {
	setXPrimaryTickLength(length);
	setYPrimaryTickLength(length);
}

void Ticks2D::setYPrimaryTickLength(const double &length) {
	m_axisYPrimaryTickLength = length;
}

void Ticks2D::setYSecondaryTickLength(const double &length) {
	m_axisYSecondaryTickLength = length;
}

void Ticks2D::setSecondaryTickLength(const double &length) {
	setXSecondaryTickLength(length);
	setYSecondaryTickLength(length);
}

void Ticks2D::setXPrimaryTickWidth(const double &width) {
	m_axisXPrimaryTickWidth = width;
	m_axisXPrimaryTickPen.setWidthF(width);
}

void Ticks2D::setXSecondaryTickWidth(const double &width) {
	m_axisXSecondaryTickWidth = width;
	m_axisXSecondaryTickPen.setWidthF(width);
}

void Ticks2D::setXTickWidth(const double &width) {
	setXPrimaryTickWidth(width);
	setXSecondaryTickWidth(width);
}

void Ticks2D::setYPrimaryTickWidth(const double &width) {
	m_axisYPrimaryTickWidth = width;
	m_axisYPrimaryTickPen.setWidthF(width);
}

void Ticks2D::setYSecondaryTickWidth(const double &width) {
	m_axisYSecondaryTickWidth = width;
	m_axisYSecondaryTickPen.setWidthF(width);
}

void Ticks2D::setYTickWidth(const double &width) {
	setYPrimaryTickWidth(width);
	setYSecondaryTickWidth(width);
}

void Ticks2D::setPrimaryTickWidth(const double &width) {
	setXPrimaryTickWidth(width);
	setYPrimaryTickWidth(width);
}

void Ticks2D::setSecondaryTickWidth(const double &width) {
	setXSecondaryTickWidth(width);
	setYSecondaryTickWidth(width);
}

void Ticks2D::setTickWidth(const double &width) {
	setPrimaryTickWidth(width);
	setSecondaryTickWidth(width);
}

void Ticks2D::setXPrimaryTickColor(const QColor &color) {
	m_axisXPrimaryTickColor = color;
	m_axisXPrimaryTickPen.setColor(color);
}

void Ticks2D::setYPrimaryTickColor(const QColor &color) {
	m_axisYPrimaryTickColor = color;
	m_axisYPrimaryTickPen.setColor(color);
}

void Ticks2D::setPrimaryTickColor(const QColor &color) {
	setXPrimaryTickColor(color);
	setXPrimaryTickColor(color);
}

void Ticks2D::setXSecondaryTickColor(const QColor &color) {
	m_axisXSecondaryTickColor = color;
	m_axisXSecondaryTickPen.setColor(color);
}

void Ticks2D::setYSecondaryTickColor(const QColor &color) {
	m_axisYSecondaryTickColor = color;
	m_axisYSecondaryTickPen.setColor(color);
}

void Ticks2D::setSecondaryTickColor(const QColor &color) {
	setXSecondaryTickColor(color);
	setYSecondaryTickColor(color);
}

void Ticks2D::setXPrimaryTickStyle(const Qt::PenStyle &style) {
	m_axisXPrimaryTickStyle = style;
	m_axisXPrimaryTickPen.setStyle(style);
}

void Ticks2D::setYPrimaryTickStyle(const Qt::PenStyle &style) {
	m_axisYPrimaryTickStyle = style;
	m_axisYPrimaryTickPen.setStyle(style);
}

void Ticks2D::setPrimaryTickStyle(const Qt::PenStyle &style) {
	setXPrimaryTickStyle(style);
	setYPrimaryTickStyle(style);
}

void Ticks2D::setXSecondaryTickStyle(const Qt::PenStyle &style) {
	m_axisXSecondaryTickStyle = style;
	m_axisXSecondaryTickPen.setStyle(style);
}

void Ticks2D::setYSecondaryTickStyle(const Qt::PenStyle &style) {
	m_axisYSecondaryTickStyle = style;
	m_axisYSecondaryTickPen.setStyle(style);
}

void Ticks2D::setSecondaryTickStyle(const Qt::PenStyle &style) {
	setXSecondaryTickStyle(style);
	setYSecondaryTickStyle(style);
}

void Ticks2D::setXTickStyle(const Qt::PenStyle &style) {
	setXPrimaryTickStyle(style);
	setXSecondaryTickStyle(style);
}

void Ticks2D::setYTickStyle(const Qt::PenStyle &style) {
	setYPrimaryTickStyle(style);
	setYSecondaryTickStyle(style);
}

void Ticks2D::setTickStyle(const Qt::PenStyle &style) {
	setYTickStyle(style);
	setXTickStyle(style);
}

void Ticks2D::setXLabelFormatType(const FormatType &type) {
	m_axisXFormatType = type;
}

void Ticks2D::setYLabelFormatType(const FormatType &type) {
	m_axisYFormatType = type;
}

void Ticks2D::Ticks2D::setLabelFormatType(const FormatType &type) {
	setXLabelFormatType(type);
	setYLabelFormatType(type);
}

void Ticks2D::setXLabelFont(const QFont &font) {
	m_axisXFont = font;
}

void Ticks2D::setYLabelFont(const QFont &font) {
	m_axisYFont = font;
}

void Ticks2D::setLabelFont(const QFont &font) {
	setXLabelFont(font);
	setYLabelFont(font);
}

void Ticks2D::setXLabelDistanceFromAxis(const double &distance) {
	m_axisXLabelDistance = distance;
}

void Ticks2D::setYLabelDistanceFromAxis(const double &distance) {
	m_axisYLabelDistance = distance;
}

void Ticks2D::setLabelDistanceFromAxis(const double &distance) {
	setXLabelDistanceFromAxis(distance);
	setYLabelDistanceFromAxis(distance);
}

void Ticks2D::setEnableLabels(const bool &flag) {
	m_labelEnabled = flag;
}

void Ticks2D::setOrigin(const QPointF &origin) {
	m_origin = origin;
}

void Ticks2D::setOrigin(const double &x, const double &y) {
	m_origin.setX(x);
	m_origin.setY(y);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void Ticks2D::draw(Plot2D *plot) {
	drawAxisXTicks(plot);
	drawAxisYTicks(plot);
	if (true == m_labelEnabled) {
		drawAxisXLabels(plot);
		drawAxisYLabels(plot);
	}
}

///////////////////////////////////////////////////////////////////////////////
// PRIVATE SECTION                                                           //
///////////////////////////////////////////////////////////////////////////////

void Ticks2D::drawAxisXTicks(Plot2D *plot) {
	QPainter painter(plot);
	const auto upperLeftLimits = plot->getUpperLeftCorner();
	const auto lowerRightLimits = plot->getLowerRightCorner();
	const auto upperLeftCorner = plot->scalePoint(upperLeftLimits);
	const auto lowerRightCorner = plot->scalePoint(lowerRightLimits);
	const auto axisOrigin = plot->scalePoint(m_origin);
	painter.setPen(m_axisXSecondaryTickPen);
	LinearTicksCalculator ticksCalculator;
	ticksCalculator.setStep(m_axisXSecondaryStep);
	ticksCalculator.setLimits(upperLeftLimits.x(), lowerRightLimits.x());
	const auto secondaryTicks = ticksCalculator.getTicks();
	for (const auto& x : secondaryTicks) {
		const double scaledX = plot->scalePointX(x);
		painter.drawLine(scaledX, axisOrigin.y(), scaledX, axisOrigin.y() - m_axisXSecondaryTickLength);
	}
	painter.setPen(m_axisXPrimaryTickPen);
	ticksCalculator.setStep(m_axisXPrimaryStep);
	const auto primaryTicks = ticksCalculator.getTicks();
	for (const auto& x : primaryTicks) {
		const double scaledX = plot->scalePointX(x);
		painter.drawLine(scaledX, axisOrigin.y(), scaledX, axisOrigin.y() - m_axisXPrimaryTickLength);
	}
}

void Ticks2D::drawAxisYTicks(Plot2D *plot) {
	QPainter painter(plot);
	const auto upperLeftLimits = plot->getUpperLeftCorner();
	const auto lowerRightLimits = plot->getLowerRightCorner();
	const auto upperLeftCorner = plot->scalePoint(upperLeftLimits);
	const auto lowerRightCorner = plot->scalePoint(lowerRightLimits);
	const auto axisOrigin = plot->scalePoint(m_origin);
	painter.setPen(m_axisYSecondaryTickPen);
	LinearTicksCalculator ticksCalculator;
	ticksCalculator.setStep(m_axisYSecondaryStep);
	ticksCalculator.setLimits(lowerRightLimits.y(), upperLeftLimits.y());
	const auto secondaryTicks = ticksCalculator.getTicks();
	for (const auto& y : secondaryTicks) {
		const double scaledY = plot->scalePointY(y);
		painter.drawLine(axisOrigin.x(), scaledY, axisOrigin.x() + m_axisYSecondaryTickLength, scaledY);
	}
	painter.setPen(m_axisYPrimaryTickPen);
	ticksCalculator.setStep(m_axisYPrimaryStep);
	const auto primaryTicks = ticksCalculator.getTicks();
	for (const auto& y : primaryTicks) {
		const double scaledY = plot->scalePointY(y);
		painter.drawLine(axisOrigin.x(), scaledY, axisOrigin.x() + m_axisYPrimaryTickLength, scaledY);
	}
}

void Ticks2D::drawAxisXLabels(Plot2D *plot) {
	QPainter painter(plot);
	QFontMetrics fontMetrics(m_axisXFont);
	painter.setFont(m_axisXFont);
	const auto upperLeftLimits = plot->getUpperLeftCorner();
	const auto lowerRightLimits = plot->getLowerRightCorner();
	const auto upperLeftCorner = plot->scalePoint(upperLeftLimits);
	const auto lowerRightCorner = plot->scalePoint(lowerRightLimits);
	const auto axisOrigin = plot->scalePoint(m_origin);
	painter.setPen(m_axisXSecondaryTickPen);
	LinearTicksCalculator ticksCalculator;
	ticksCalculator.setStep(m_axisXSecondaryStep);
	ticksCalculator.setLimits(upperLeftLimits.x(), lowerRightLimits.x());
	QRectF rect;
	const auto secondaryTicks = ticksCalculator.getTicks();
	for (const auto& x : secondaryTicks) {
		const double scaledX = plot->scalePointX(x);
		const QString labelText(getLabelText(x));
		auto s = fontMetrics.size(Qt::TextSingleLine, labelText);
		rect.setLeft(scaledX - s.width() * 0.5);
		rect.setTop(axisOrigin.y() + m_axisXLabelDistance);
		rect.setWidth(s.width());
		rect.setHeight(s.height());
		painter.drawText(rect, labelText, m_axisXTextOptions);
	}
	painter.setPen(m_axisXPrimaryTickPen);
	ticksCalculator.setStep(m_axisXPrimaryStep);
	const auto primaryTicks = ticksCalculator.getTicks();
	for (const auto& x : primaryTicks) {
		const double scaledX = plot->scalePointX(x);
		const QString labelText(getLabelText(x));
		auto s = fontMetrics.size(Qt::TextSingleLine, labelText);
		rect.setLeft(scaledX - s.width() * 0.5);
		rect.setTop(axisOrigin.y() + m_axisXLabelDistance);
		rect.setWidth(s.width());
		rect.setHeight(s.height());
		painter.drawText(rect, labelText, m_axisXTextOptions);
	}
}

void Ticks2D::drawAxisYLabels(Plot2D *plot) {
	QPainter painter(plot);
	QFontMetrics fontMetrics(m_axisYFont);
	painter.setFont(m_axisYFont);
	const auto upperLeftLimits = plot->getUpperLeftCorner();
	const auto lowerRightLimits = plot->getLowerRightCorner();
	const auto upperLeftCorner = plot->scalePoint(upperLeftLimits);
	const auto lowerRightCorner = plot->scalePoint(lowerRightLimits);
	const auto axisOrigin = plot->scalePoint(m_origin);
	painter.setPen(m_axisYSecondaryTickPen);
	LinearTicksCalculator ticksCalculator;
	ticksCalculator.setStep(m_axisYSecondaryStep);
	ticksCalculator.setLimits(lowerRightLimits.y(), upperLeftLimits.y());
	const auto secondaryTicks = ticksCalculator.getTicks();
	QRectF rect;
	for (const auto& y : secondaryTicks) {
		const double scaledY = plot->scalePointY(y);
		const QString labelText(getLabelText(y));
		auto s = fontMetrics.size(Qt::TextSingleLine, labelText);
		rect.setLeft(axisOrigin.x() - s.width() - 5 - m_axisYLabelDistance);
		rect.setTop(scaledY - s.height() * 0.5);
		rect.setWidth(s.width() + 5);
		rect.setHeight(s.height());
		painter.drawText(rect, labelText, m_axisYTextOptions);
	}
	painter.setPen(m_axisYPrimaryTickPen);
	ticksCalculator.setStep(m_axisYPrimaryStep);
	const auto primaryTicks = ticksCalculator.getTicks();
	for (const auto& y : primaryTicks) {
		const double scaledY = plot->scalePointY(y);
		const QString labelText(getLabelText(y));
		auto s = fontMetrics.size(Qt::TextSingleLine, labelText);
		rect.setLeft(axisOrigin.x() - s.width() - 5 - m_axisYLabelDistance);
		rect.setTop(scaledY - s.height() * 0.5);
		rect.setWidth(s.width() + 5);
		rect.setHeight(s.height());
		painter.drawText(rect, labelText, m_axisYTextOptions);
	}
}

QString Ticks2D::getLabelText(const double &value) const {
	switch (m_axisYFormatType) {
		case FORMAT_INTEGER : {
			return QString::number(static_cast<int>(value));
		} break;
		case FORMAT_FLOAT : {
			return QString::number(value, 'g', 2);
		} break;
		case FORMAT_DATE : {
			QDateTime dateTime = QDateTime::fromTime_t(static_cast<uint>(value));
			return dateTime.toString("dd.MM.yyyy");
		} break;
		case FORMAT_TIME : {
			QTime time = QTime::fromMSecsSinceStartOfDay(static_cast<int>(value) * 1000);
			return time.toString("hh:mm:ss");
		} break;
		case FORMAT_DATETIME : {
			QDateTime dateTime = QDateTime::fromTime_t(static_cast<uint>(value));
			return dateTime.toString("dd.MM.yyyy hh:mm:ss");
		} break;
	}
	return QString::number(value);
}

} // namespace WPlot
