#pragma once
#include "core/unit.h"
#include <QVector>

class ClassJavaUnit : public Unit
{
private:
    QString _name;
    QVector<QVector<QSharedPointer<Unit>>> _accessBlocks;
public:
    explicit ClassJavaUnit(const QString &name);
    ~ClassJavaUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags accessModifier) override;
    QString compile(unsigned int level = 0) const override;
};
