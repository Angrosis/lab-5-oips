#include "pch.h"
#include "CppUnitTest.h"
#include" C:\Users\Angrosis\Desktop\Новая папка\Lab 5 IPZ\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(Calculateequalszero) // Проверка при х = 0
		{
			double actual = calculate(0, 5);
			Assert::AreEqual(-0.0, actual);
		}
		TEST_METHOD(CalculateMoreZero) // Проверка при х > 0
		{
			double actual = calculate(6, 5);
			Assert::AreEqual(-336.0, actual);
		}
		TEST_METHOD(CalculateLessZero) // Проверка при х < 0
		{
			double actual = calculate(-6, 5);
			Assert::AreEqual(-2, int(actual));
		}
		TEST_METHOD(RUINA) // Специально заваленый тестик
		{
			double actual = calculate(-6, 5);
			Assert::AreEqual(-3, int(actual));
		}
	};
	TEST_CLASS(checkValidParams_Tests)
	{
	public:
		TEST_METHOD(checkValidParams1) {
			int n = 0.5;
			try
			{
				checkValidParams(n);
				Assert::Fail;
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(checkValidParams2) {
			int n = 1;
			try
			{
				checkValidParams(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}
