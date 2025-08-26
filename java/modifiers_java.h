#pragma once
#include "core/unit.h"
#include <QVector>
#include <QMap>

namespace JavaModifier
{
inline const QVector<QString> accessModifierToString{
    "private", "protected", "public"
};

inline const QMap<Unit::Flags, QString> behaviorModifierToString{
    // { 1u << 0, "static" },
    // { 1u << 1, "abstract" },
    { 1u << 0 /*2*/, "final" }
};

enum AccessModifier {
    Private, Protected, Public
};

enum BehaviorModifier : Unit::Flags {
    // Static   = 1u << 0,
    // Abstract = 1u << 1,
    Final    = 1u << 0 /*2*/
};
}
