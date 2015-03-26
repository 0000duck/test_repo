#ifndef ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_SERVICE_TYPE_SUPPORT_H_
#define ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_SERVICE_TYPE_SUPPORT_H_

#include "rosidl_generator_c/service_type_support.h"

typedef struct service_type_support_callbacks_t
{
  const char * package_name;
  const char * service_name;
  // Function to create a requester
  void* (*create_requester)(void * participant, const char * service_name,
                            void **reader);
  // Function to create a responder
  void* (*create_responder)(void * participant, const char * service_name,
                          void **reader);
  // Function to send ROS requests
  int64_t (*send_request)(void * requester, const void * ros_request);
  // Function to read a ROS request from the wire
  bool (*take_request)(void * responder, void * ros_request_header, void * ros_request);
  // Function to send ROS responses
  void (*send_response)(void * responder, const void * ros_request_header, const void * ros_response);
  // Function to read a ROS response from the wire
  bool (*take_response)(void * requester, void * ros_request_header, void * ros_response);
  // De-allocatea a requester
  void (*destroy_requester)(void *untyped_requester);
  // De-allocatea a responder
  void (*destroy_responder)(void *untyped_requester);
} service_type_support_callbacks_t;

#endif  /* ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_SERVICE_TYPE_SUPPORT_H_ */
