#include <iostream>
#include "IllegalCommand.h"

IllegalCommand::IllegalCommand() { m_error = "Error: IllegalCommand!"; }
std::string IllegalCommand::getError() const { return m_error; };