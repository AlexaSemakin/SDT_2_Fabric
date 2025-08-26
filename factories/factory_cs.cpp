#include "factories/factory_cs.h"
#include "cs/class_cs.h"
#include "cs/method_cs.h"
#include "cs/print_cs.h"

QSharedPointer<Unit> CsConstructionFactory::createClass(const QString &name) const
{
    return QSharedPointer<Unit>{ new ClassCsUnit(name) };
}

QSharedPointer<Unit> CsConstructionFactory::createMethod(const QString &name, const QString &returnType, Unit::Flags flags) const
{
    return QSharedPointer<Unit>{ new MethodCsUnit(name, returnType, flags) };
}

QSharedPointer<Unit> CsConstructionFactory::createStatement(const QString &text) const
{
    return QSharedPointer<Unit>{ new PrintOperatorCsUnit(text) };
}
