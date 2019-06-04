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

#pragma once

#include <random>
#include <set>
#include <mutex>

// Utilality Namespace
namespace Util
{
	// Unique ID Generator Class
	// Based on the idea of singleton mode, the UID generator is designed to be singleton and safe in multithreaded situation. 
	// Use smart pointers to ensure no memory leaks. 
	// Use std::set to ensure that the ID sequence is unique.
	class UIDGenerator
	{
	public:
		static std::shared_ptr<Util::UIDGenerator> GetInstance(void);

	public:
		const unsigned long GetNewUID(void);
		void SetRange(const unsigned long _min, const unsigned long _max);

		// Private constructor
		UIDGenerator(void);
		// No copy constructor
		UIDGenerator(const UIDGenerator& _uidgen) = delete;
		// No assign operation
		UIDGenerator& operator = (const UIDGenerator& _uidgen) = delete;

	private:
		std::set<unsigned long> existID;
		std::default_random_engine engine;
		std::unique_ptr<std::uniform_int_distribution<unsigned long>> distribution;
	};
}
