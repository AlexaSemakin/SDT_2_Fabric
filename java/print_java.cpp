#include "java/print_java.h"

PrintOperatorJavaUnit::PrintOperatorJavaUnit(const QString &text)
    : _text{text} {}

QString PrintOperatorJavaUnit::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println(\"" + _text + "\");\n";
}
