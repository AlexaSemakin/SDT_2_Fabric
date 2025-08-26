#pragma once
#include "core/unit.h"

class PrintOperatorJavaUnit : public Unit
{
private:
    QString _text;
public:
    explicit PrintOperatorJavaUnit(const QString &text);
    QString compile(unsigned int level = 0) const override;
};
