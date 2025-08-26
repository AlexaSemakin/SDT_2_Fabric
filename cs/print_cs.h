#pragma once
#include "core/unit.h"

class PrintOperatorCsUnit : public Unit
{
private:
    QString _text;
public:
    explicit PrintOperatorCsUnit(const QString &text);
    QString compile(unsigned int level = 0) const override;
};
