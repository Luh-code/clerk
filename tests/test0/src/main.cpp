#include "Clerk/clerk.hpp"

#include <stdio.h>

int main()
{
  std::ostringstream buf {};
  Clerk::process(buf, "Hello ", "World", '!');
  printf("%s\n", buf.str().c_str());
}
