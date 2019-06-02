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

#include <iostream>
#include <chrono>
#include <thread>

#include "UIDGenerator.h"

int main(int argc, char* argv[])
{
	std::shared_ptr<Util::UIDGenerator> uidgen = Util::UIDGenerator::GetInstance();
	uidgen->SetRange(10000, 99999);

	std::thread thr1{ [] {
		std::shared_ptr<Util::UIDGenerator> uidgen = Util::UIDGenerator::GetInstance(); 
		for (size_t i = 0; i < 10; i++)
		{
			std::cout << "Thread1 : " << uidgen->GetNewUID() << std::endl;
		}
	} };

	std::thread thr2{ [] {
		std::shared_ptr<Util::UIDGenerator> uidgen = Util::UIDGenerator::GetInstance();
		for (size_t i = 0; i < 10; i++)
		{
			std::cout << "Thread2 : " << uidgen->GetNewUID() << std::endl;
		}
	} };

	thr1.join();
	thr2.join();

	return 0;
}
