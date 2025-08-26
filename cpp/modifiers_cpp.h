#pragma once
#include "core/unit.h"
#include <QVector>
#include <QMap>

namespace CppModifier
{
    inline const QVector<QString> accessModifierToString{
        "private", "protected", "public"
    };

    inline const QMap<Unit::Flags, QString> behaviorModifierToString{
        { 1u << 0, "static" },
        { 1u << 1, "virtual" },
        { 1u << 2, "const" }
    };

    enum AccessModifier {
        Private, Protected, Public
    };

    enum BehaviorModifier : Unit::Flags {
        Static = 1u << 0,
        Virtual = 1u << 1,
        Const = 1u << 2
    };
}
