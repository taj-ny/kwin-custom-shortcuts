#pragma once

#include "gestures/holdgesture.h"
#include "gestures/pinchgesture.h"
#include "gestures/swipegesture.h"
#include <QObject>
#include <QPointF>

enum Axis
{
    Horizontal,
    Vertical,
    None
};

class GestureRecognizer : public QObject
{
    Q_OBJECT

public:
    bool holdGestureBegin(int fingerCount, std::chrono::microseconds time);
    bool holdGestureEnd(std::chrono::microseconds time);
    bool holdGestureCancelled();

    bool swipeGestureBegin(uint fingerCount);
    bool swipeGestureUpdate(const QPointF &delta);
    bool swipeGestureEnd(bool dontTriggerGestures = false, bool resetHasActiveTriggeredGesture = true);
    bool swipeGestureCancelled();

    bool pinchGestureBegin(uint fingerCount);
    bool pinchGestureUpdate(qreal scale, qreal angleDelta, const QPointF &delta);
    bool pinchGestureEnd();
    bool pinchGestureCancelled();

private:
    QList<std::shared_ptr<SwipeGesture>> m_activeSwipeGestures;
    bool m_hasActiveTriggeredSwipeGesture = false;

    QList<std::shared_ptr<PinchGesture>> m_activePinchGestures;

    QList<std::shared_ptr<HoldGesture>> m_activeHoldGestures;
    std::chrono::milliseconds m_holdGestureStart;

    uint m_currentFingerCount = 0;
    Axis m_currentSwipeAxis = Axis::None;
    QPointF m_currentDelta;
    qreal m_currentScale = 1;
};