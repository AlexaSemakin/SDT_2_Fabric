#pragma once
#include "core/unit.h"
#include <QVector>
#include <QMap>

namespace CsModifier
{
    inline const QVector<QString> accessModifierToString{
        "private", "private protected", "protected",
        "internal", "protected internal", "public"
    };

    inline const QMap<Unit::Flags, QString> behaviorModifierToString{
        { 1u << 0, "static" },
        { 1u << 1, "virtual" }
        // { 1u << 2, "abstract" }
    };

    enum AccessModifier {
        Private, PrivateProtected, Protected,
        Internal, ProtectedInternal, Public
    };

    enum BehaviorModifier : Unit::Flags {
        Static = 1u << 0,
        Virtual = 1u << 1
        // Abstract = 1u << 2
    };
}
