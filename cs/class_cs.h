#pragma once
#include "core/unit.h"
#include <QVector>

class ClassCsUnit : public Unit
{
private:
    QString _name;
    QVector<QVector<QSharedPointer<Unit>>> _accessBlocks;
public:
    explicit ClassCsUnit(const QString &name);
    ~ClassCsUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags accessModifier) override;
    QString compile(unsigned int level = 0) const override;
};
