# Unique ID Generator
A Unique ID Generator in C++.

## Intro
&emsp;&emsp;Based on the idea of singleton mode, the UID generator is designed to be singleton and safe in multithreaded situation. 
Use smart pointers to ensure no memory leaks. 
Use std::set to ensure that the ID sequence is unique.

## Sample code
Simple scenario
```cpp
std::shared_ptr<Util::UIDGenerator> uidgen = Util::UIDGenerator::GetInstance();
uidgen->SetRange(10000, 99999);

std::cout << "New UID : " << uidgen->GetNewUID() << std::endl;
```

Multithread scenario
```cpp
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
```
## About
<p>It`s welcomed for anyone to contribute to this project. Feel free to upload your code and pull a request. More than anything, please share your idea and give me some precious advices. </p>
<img src="https://github.com/CelestialTS/CTHackFramework/blob/master/res/logo.png" alt="Celestial Tech" width=400 height="=100">
<p>For more please check out website: <a href="http://www.tianshicangxie.com">Celestial Tech</a></p>
<p>Copyright © 2019 Celestial Tech</p>
