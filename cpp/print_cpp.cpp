#include "cpp/print_cpp.h"

PrintOperatorCppUnit::PrintOperatorCppUnit(const QString &text)
    : _text{text} {}

QString PrintOperatorCppUnit::compile(unsigned int level) const
{
    return generateShift(level) + "std::cout << \"" + _text + "\";\n";
}
