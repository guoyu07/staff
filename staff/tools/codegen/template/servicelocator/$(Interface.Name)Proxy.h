// This file generated by staff_codegen
// DO NOT EDIT

#ifndef _$(Interface.Name)Proxy_h_
#define _$(Interface.Name)Proxy_h_

#include <staff/common/WsdlTypes.h>
#include "$(Interface.FileName)"

namespace staff { class CService; }

#foreach $(Interface.Classes)
$(Class.OpeningNs)
class $(Class.Name)Proxy: public $(Class.Name)
{
public:
  $(Class.Name)Proxy(staff::CService* pService, const rise::CString& sID);
  void SetService(staff::CService* pService);
#foreach $(Class.Members)
  $(Member.Return) $(Member.Name)($(Member.Params))$(Member.Const);
#end

private:
  mutable staff::CService* m_pService;
  const rise::CString m_sID;
};
$(Class.EndingNs)

#end
#endif
