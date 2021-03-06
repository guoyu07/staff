// This file generated by staff_codegen
// For more information please visit: http://code.google.com/p/staff/

#ifndef _foo_types_h_
#define _foo_types_h_

#include <string>
#include <list>
#include <staff/common/Optional.h>
#include <staff/common/WsdlTypes.h>
#include <staff/common/Abstract.h>
#include <staff/common/Nillable.h>
#include "foo_other_types.h"

// *interface.elementFormDefault: qualified
// *interface.targetNamespace: http://fooMethod


namespace ns_staff
{

  struct foo_struct;

  struct foo_struct
  {
    // *isAttribute: true
    staff::Optional< ::ns_staff::foo_type > attr1;
  };
}

#endif // _foo_types_h_

