// Unique ID Generator
// Celestial Tech
// Copyright (c) 2019 Celestial Tech All rights reserved.
//
// The MIT License (MIT)
// Copyright (c) 2019 Celestial Tech
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this softwareand associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright noticeand this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "UIDGenerator.h"

std::mutex mutexUIDGenerator;
static std::shared_ptr<Util::UIDGenerator> instancePointer;

std::shared_ptr<Util::UIDGenerator> Util::UIDGenerator::GetInstance(void)
{
	std::lock_guard<std::mutex> mutex{ mutexUIDGenerator };
	if (instancePointer == nullptr)
	{
		srand(time(0));
		instancePointer = std::make_unique<Util::UIDGenerator>();
	}
	return instancePointer;
}

const long Util::UIDGenerator::GetNewUID(void)
{
	if (existID.size() >= (high - low))
		throw std::runtime_error("UID Generator ran out of ids.");
	std::lock_guard<std::mutex> mutex{ mutexUIDGenerator };
	long newUID{ 0 };
	do
	{
		do
		{
			newUID = low + (float)rand() / RAND_MAX * (high - low);
		} while (newUID<low || newUID> high);
	} while (existID.find(newUID) != existID.end());
	existID.insert(newUID);
	return newUID;
}

void Util::UIDGenerator::SetRange(const long low, const long high)
{
	this->low = low;
	this->high = high;
}


