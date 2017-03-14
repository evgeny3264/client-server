#include "stdafx.h"
#include "CppUnitTest.h"
#include "view.h"
#include "priorityqueue.h"
#include "client.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		View v = View(1);
		TEST_METHOD(TestClientId)
		{			
			PriorityQueue pq(v);
			Client client(pq);
			Assert::AreEqual(client.GetId(), static_cast<unsigned long>(1));
		}
		//(0 - highest priority)
		TEST_METHOD(TestQueue)
		{
			PriorityQueue pq(v);
			TDATA tdRequest{};
			tdRequest.cPriority =120;
			tdRequest.dwClientId =1;
			TDATA tdRequest2{};
			tdRequest2.cPriority = 150;
			tdRequest2.dwClientId = 2;
			pq.Add(tdRequest);		
			pq.Add(tdRequest2);
			TDATA tdRequestTop{};
			bool res = pq.Get(tdRequestTop);
			Assert::IsTrue(res);
			Assert::AreEqual(tdRequestTop.dwClientId, static_cast<unsigned long>(1));
		}

	};
}