#include <iostream>
#include "OffTheField.h"

OffTheField::OffTheField() { m_error = "Error: OffTheField!"; }

std::string OffTheField::getError() const{ return m_error; };