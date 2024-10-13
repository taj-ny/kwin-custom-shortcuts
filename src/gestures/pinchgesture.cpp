#include "pinchgesture.h"

PinchGesture::PinchGesture(InputDeviceType device, bool triggerWhenThresholdReached, uint minimumFingers, uint maximumFingers, KWin::PinchDirection direction, qreal threshold)
    : Gesture(device, triggerWhenThresholdReached, minimumFingers, maximumFingers),
      m_direction(direction), m_threshold(threshold)
{
}

bool PinchGesture::thresholdReached(const qreal &scale) const
{
    return m_direction == KWin::PinchDirection::Expanding
       ? scale >= m_threshold
       : scale <= m_threshold;
}