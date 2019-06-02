#include "UIDGen.h"

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
	do {
		do {
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


