#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "..\ConsoleApplication1\Kinematics.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestKinematics
{
    TEST_CLASS(KinematicsTests)
    {
    public:
        // ==========================================
        // 1. ПОЗИТИВНЫЕ ТЕСТЫ
        // ==========================================

        BEGIN_TEST_METHOD_ATTRIBUTE(Positive_Velocity_ValidValues)
            TEST_METHOD_ATTRIBUTE(L"Category", L"Positive")
            END_TEST_METHOD_ATTRIBUTE()
            TEST_METHOD(Positive_Velocity_ValidValues)
        {
            // Arrange
            double distance = 150.0;
            double time = 3.0;
            double expected = 50.0;

            // Act
            double actual = Kinematics::velocity(distance, time);

            // Assert
            Assert::AreEqual(expected, actual, 0.0001);
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(Positive_Acceleration_ValidValues)
            TEST_METHOD_ATTRIBUTE(L"Category", L"Positive")
            END_TEST_METHOD_ATTRIBUTE()
            TEST_METHOD(Positive_Acceleration_ValidValues)
        {
            // Arrange
            double v0 = 10.0;
            double v1 = 30.0;
            double time = 4.0;
            double expected = 5.0;

            // Act
            double actual = Kinematics::acceleration(v0, v1, time);

            // Assert
            Assert::AreEqual(expected, actual, 0.0001);
        }

        // ==========================================
        // 2. НЕГАТИВНЫЕ ТЕСТЫ
        // ==========================================

        BEGIN_TEST_METHOD_ATTRIBUTE(Negative_Velocity_ZeroTime_ThrowsException)
            TEST_METHOD_ATTRIBUTE(L"Category", L"Negative")
            END_TEST_METHOD_ATTRIBUTE()
            TEST_METHOD(Negative_Velocity_ZeroTime_ThrowsException)
        {
            // Arrange
            double distance = 100.0;
            double invalidTime = 0.0;

            // Act
            auto action = [distance, invalidTime]() {
                Kinematics::velocity(distance, invalidTime);
                };

            // Assert
            Assert::ExpectException<std::invalid_argument>(action);
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(Negative_Time_ZeroVelocity_ThrowsException)
            TEST_METHOD_ATTRIBUTE(L"Category", L"Negative")
            END_TEST_METHOD_ATTRIBUTE()
            TEST_METHOD(Negative_Time_ZeroVelocity_ThrowsException)
        {
            // Arrange
            double distance = 100.0;
            double invalidVelocity = 0.0;

            // Act
            auto action = [distance, invalidVelocity]() {
                Kinematics::time(distance, invalidVelocity);
                };

            // Assert
            Assert::ExpectException<std::invalid_argument>(action);
        }
    };
}