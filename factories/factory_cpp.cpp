#include "factories/factory_cpp.h"
#include "cpp/class_cpp.h"
#include "cpp/method_cpp.h"
#include "cpp/print_cpp.h"

QSharedPointer<Unit> CppConstructionFactory::createClass(const QString &name) const
{
    return QSharedPointer<Unit>{ new ClassCppUnit(name) };
}

QSharedPointer<Unit> CppConstructionFactory::createMethod(const QString &name, const QString &returnType, Unit::Flags flags) const
{
    return QSharedPointer<Unit>{ new MethodCppUnit(name, returnType, flags) };
}

QSharedPointer<Unit> CppConstructionFactory::createStatement(const QString &text) const
{
    return QSharedPointer<Unit>{ new PrintOperatorCppUnit(text) };
}
