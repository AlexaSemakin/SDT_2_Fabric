#pragma once
#include "core/unit.h"

class PrintOperatorCppUnit : public Unit
{
private:
    QString _text;
public:
    explicit PrintOperatorCppUnit(const QString &text);
    QString compile(unsigned int level = 0) const override;
};
