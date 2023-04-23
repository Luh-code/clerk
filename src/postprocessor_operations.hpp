#ifndef __CLERK_POSTPROCESSOR_OPERATIONS_HPP__
#define __CLERK_POSTPROCESSOR_OPERATIONS_HPP__

#include <sstream>

namespace Clerk
{
  // using PostProcessingOperation = void (*)(std::ostringstream&);
  // using PPOperation = PostProcessingOperation;

  typedef class PostProcessingOperationPointerBase {} PPOPointerBase;
  template<class C, void(C::*F)(std::ostringstream&)>
  class PostProcessingOperationPointer : public PPOPointerBase
  {
  private:
    C* obj;
  public:
    inline PostProcessingOperationPointer(C* obj) : obj(obj) { }

    inline void operator()(std::ostringstream& buf)
    {
      obj->F(buf);
    }
    inline void call(std::ostringstream& buf)
    {
      this->operation()(buf);
    }
  };
  template<class C, void(C::*F)(std::ostringstream&)>
  using PPOPointer = PostProcessingOperationPointer<C, F>;

  typedef struct TextInsertionPPO
  {
  public:
    const char* message;
  public:
    inline TextInsertionPPO(std::string message)
      : message(message.c_str())
    { }
    inline TextInsertionPPO(const char* message)
      : message(message)
    { }

    inline PPOPointerBase getOperation()
    {
      return PPOPointer<TextInsertionPPO, &proc>{this};
    }

    void proc(std::ostringstream& buf);
  } TextInsertionPPO;

  // typedef class PostProcessorOperation
  // {
  // public:
  //   virtual void proc(std::ostringstream& buf) = 0;
  // } PPOperation;
  //
  // class TextInsertionPPO : public PPOperation
  // {
  // public:
  //   std::string message;
  // public:
  //   inline TextInsertionPPO(std::string message)
  //     : message(message)
  //   { }
  //   inline TextInsertionPPO(const char* message)
  //     : message(message)
  //   { }
  //
  //   virtual void proc(std::ostringstream& buf) override;
  // };
}

#endif /* end of include guard: __CLERK_POSTPROCESSOR_OPERATIONS_HPP__ */
