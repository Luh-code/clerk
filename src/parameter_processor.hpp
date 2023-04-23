#ifndef __CLERK_PARAMETER_PROCESSOR_HPP__
#define __CLERK_PARAMETER_PROCESSOR_HPP__

#include <string>
#include <string.h>
#include <sstream>
#include <array>
#include <vector>

#include "postprocessor_operations.hpp"

namespace Clerk
{
  class ParameterProcessor
  {
    static inline void variadicUnpack(std::ostringstream& buf) {}

    template<typename T, typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, const T arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, void* arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, int8_t* arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, const int8_t* arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, int32_t arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, uint32_t arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, int64_t arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, uint64_t arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, float arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::ostringstream& buf, double arg, Args&&... args)
    {
      buf << arg;
      variadicUnpack(buf, args...);
    }

    template<typename... Args>
    static inline void process(std::ostringstream& buf, Args&&... args)
    {
      variadicUnpack(buf, args...);
    }
  };

  class PostProcessor
  {
  public:
    std::vector<PPOPointerBase>& operations;

    inline PostProcessor(std::vector<PPOPointerBase>& ops)
      : operations(ops)
    {}

    inline void process(std::ostringstream& buf)
    {
      for (auto op : operations)
      {
        static_cast<PPOPointer>(op)(buf);
      }
      for (size_t i = 0; i < operations.size(); ++i) {
        operations[i](buf);
      }
    }
  };
}

#endif /* end of include guard: __CLERK_PARAMETER_PROCESSOR_HPP__ */
