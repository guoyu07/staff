// This file generated by staff_codegen
// For more information please visit: http://code.google.com/p/staff/
// Client skeleton

#include <memory>
#include <iomanip>
#include <rise/common/Log.h>
#include <staff/utils/ByteArray.h>
#include <staff/utils/HexBinary.h>
#include <staff/utils/Base64Binary.h>
#include <staff/common/Exception.h>
#include <staff/client/ServiceFactory.h>
#include "KeyGenerator.h"

// callbacks

void OutputData(const staff::ByteArray& rByteArray)
{
  // output buffer to screen
  const staff::byte* pData = rByteArray.GetData();  // here is binary data
  unsigned long ulDataSize = rByteArray.GetSize();  // binary data size

  // output printable chars
  std::cout << "printable chars: [";
  for (unsigned long ulPos = 0; ulPos < ulDataSize; ++ulPos, ++pData)
  {
    std::cout << ((*pData >= ' ' && *pData <= '~') ? *pData : '.' );
  }
  std::cout << "]" << std::endl;

  // output as 0xXX hex
  pData = rByteArray.GetData();
  std::cout << "hex data: [ " << std::setfill('0') << std::hex;
  for (unsigned long ulPos = 0; ulPos < ulDataSize; ++ulPos, ++pData)
  {
    std::cout << "0x" << std::setw(2) << (static_cast<short>(*pData) & 0xff) << " ";
  }
  std::cout << "]" << std::dec << std::endl;
}

int main(int nArgs, const char* paszArgs[])
{
  try
  {
    std::auto_ptr< ::samples::binarydata::KeyGenerator > pKeyGenerator(::staff::CServiceFactory::Inst().GetService< ::samples::binarydata::KeyGenerator >());

    RISE_ASSERTS(pKeyGenerator.get(), "Cannot get client for service samples.binarydata.KeyGenerator!");

    // Invoke Your service here:


    staff::hexBinary tHexKey = pKeyGenerator->GenerateHexKey(0x12345678);
    rise::LogInfo() << "Generated HexKey: " << tHexKey.ToString();
    rise::LogInfo() << "HexKey is valid: " << pKeyGenerator->ValidateHexKey(tHexKey);

    // do some actions with binary data here
    rise::LogInfo() << "dump of HexKey:";
    OutputData(tHexKey.GetBytes());

    // do the same with base64
    staff::base64Binary tBase64Key = pKeyGenerator->GenerateBase64Key(0x12345678);
    rise::LogInfo() << "GenerateBase64Key result: " << tBase64Key.ToString();
    rise::LogInfo() << "Base64Key is valid: " << pKeyGenerator->ValidateBase64Key(tBase64Key);

    // do some actions with binary data here
    rise::LogInfo() << "dump of Base64Key:";
    OutputData(tBase64Key.GetBytes());

  }
  RISE_CATCH_ALL

  return 0;
}

