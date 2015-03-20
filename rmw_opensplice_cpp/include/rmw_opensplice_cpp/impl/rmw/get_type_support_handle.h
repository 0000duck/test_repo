
#ifndef __rmw__get_type_support_handle__h__
#define __rmw__get_type_support_handle__h__

#include "rosidl_typesupport_opensplice_cpp/MessageTypeSupport.h"

extern "C" {
  extern const char * opensplice_cpp_identifier;
}

namespace rmw
{
template<typename T>
const rosidl_message_type_support_t * get_type_support_handle()
{
  return rmw_opensplice_cpp::get_type_support_handle<T>();
}

}  // namespace rmw

#endif  // __rmw__get_type_support_handle__h__
