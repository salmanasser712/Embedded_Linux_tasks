#include <gmock/gmock.h> 
#include "IEngine.h"

struct EngineMock : IEngine
{
  MOCK_METHOD(void, Start, (), (override));
  MOCK_METHOD(void, Stop, (), (override));
};
