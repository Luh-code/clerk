#include "postprocessor_operations.hpp"

namespace Clerk
{
  void TextInsertionPPO::proc(std::ostringstream& buf)
  {
    buf << message;
  }
}
