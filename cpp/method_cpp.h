#pragma once
#include "core/unit.h"
#include <QVector>

class MethodCppUnit : public Unit
{
private:
    QString _name;
    QString _returnType;
    Flags _flags;
    QVector<QSharedPointer<Unit>> _units;
public:
    MethodCppUnit(const QString &name, const QString &returnType = "void", Flags flags = 0);
    ~MethodCppUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags flags = 0) override;
    QString compile(unsigned int level = 0) const override;
};