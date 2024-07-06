#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "engine_mock.h"
#include "car.h"
#include <memory>

class EngineTest : public testing::Test
{
  public:
  EngineTest()
  {
    engine_mock_ = std::make_shared<testing::NiceMock<EngineMock>>();
    car_ = std::make_unique<Car>(engine_mock_);
  }

~EngineTest(){}
  void SetUp() override
  {}
  void TearDown() override
  {}

  protected:
  std::shared_ptr<testing::NiceMock<EngineMock>> engine_mock_;
  std::unique_ptr<Car> car_;

};

TEST_F(EngineTest, AbleToCallStart)
{
  EngineMock engine_mock;
  EXPECT_CALL(engine_mock, Start()).Times(::testing::AtLeast(1));
  engine_mock.Start();
}

TEST_F(EngineTest, ConstructionEngineinHeap)
{
  std::unique_ptr<EngineMock> engine_mock(new EngineMock());
}

TEST_F(EngineTest, InjectInsideCar)
{ 
  EXPECT_CALL(*engine_mock_, Start()).
  Times(::testing::AtLeast(1));

  car_->Drive();
}

TEST_F(EngineTest, NeverCallStartWhenCarStopIsCalled)
{ 
  EXPECT_CALL(*engine_mock_, Start()).
  Times(::testing::AtLeast(0));
  car_->Stop();
}
