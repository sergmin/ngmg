#include "pch.h"
#include "CppUnitTest.h"
#include "..\MFCApplication1\Resource.h"
#include "..\MFCApplication1\MFCApplication1Dlg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodGetOne)
		{
			MyClass myClass;
			int result = myClass.add_f(2, 3);
			Assert::AreEqual(result, 8);
		}

		TEST_METHOD(TestMethodGetTwo)
		{
			MyClass myClass;
			int result = myClass.add_f(2, 3);
			Assert::AreEqual(result, 5);
		}
		/*
		TEST_METHOD(TestButton)
		{
			MyDialog ad;
			CString expectedMsg = _T("Кнопка нажата!");
		
			CString messageBoxText;
			messageBoxText.Format(_T("%s"), ad.m_lastMessage);
			Assert::AreEqual(expectedMsg, messageBoxText);
		}
		*/
	};
}
