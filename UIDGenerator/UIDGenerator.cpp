#include "UIDGenerator.h"

std::mutex mutexUIDGenerator;
static std::shared_ptr<Util::UIDGenerator> instancePointer;

std::shared_ptr<Util::UIDGenerator> Util::UIDGenerator::GetInstance(void)
{
	std::lock_guard<std::mutex> mutex{ mutexUIDGenerator };
	if (instancePointer == nullptr)
	{
		srand(time(0));
		instancePointer = std::make_shared<UIDGenerator>();
	}
	return instancePointer;
}

const unsigned long Util::UIDGenerator::GetNewUID(void)
{
	if (existID.size() >= (distribution->max() - distribution->min()))
		throw std::runtime_error("UID Generator ran out of ids.");
	std::lock_guard<std::mutex> mutex{ mutexUIDGenerator };
	unsigned long newUID{ 0 };
	do { newUID = distribution->operator()(engine); } while (existID.find(newUID) != existID.end());
	existID.insert(newUID);
	return newUID;
}

void Util::UIDGenerator::SetRange(const unsigned long _min, const unsigned long _max)
{
	std::unique_ptr<std::uniform_int_distribution<unsigned long>> tempDistribution = std::make_unique<std::uniform_int_distribution<unsigned long>>(_min, _max);
	this->distribution.swap(tempDistribution);
	tempDistribution.release();
}


