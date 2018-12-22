//#include "TProc.h"
#include "C:\Users\1\Documents\Visual Studio 2015\Projects\mp2-lab4-queue\include\TProc.h"

TProc::TProc(double _q2, int _SizeOfQueue)
{
	q2 = _q2;
	ProcessorExpectationQueue = TQueue(_SizeOfQueue);
	isFree = true;
}

void TProc::EnqueueNewTask(int TaskId)
{
	if (!ProcessorExpectationQueue.IsFull())
	{
		ProcessorExpectationQueue.Put(TaskId);
	}
	else
		throw "ProcessorExpectationQueue was full during EnqueueNewTask";
}

void TProc::LoadProcessor()
{
	if (!ProcessorExpectationQueue.IsEmpty())
	{
		ProcessorExpectationQueue.Get();
		isFree = false;
	}
	else
		isFree = true;
		//throw "ProcessorExpectationQueue was empty during LoadProcessor";
}

bool TProc::IsProcessorExpectationQueueFull()
{
	return ProcessorExpectationQueue.IsFull();
}

bool TProc::IsProcessorExpectationQueueEmpty()
{
	return ProcessorExpectationQueue.IsEmpty();
}

bool TProc::IsProcessorFree()
{
	return isFree;
}

