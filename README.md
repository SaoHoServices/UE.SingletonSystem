# UE.SingletonSystem
Unreal Engine SingletonSystem Plugin Documentation
  
For example (C++):  
  
// Get Singleton Pointer, Return Object Type  
USingletonSystem::Get().GetSingleton(USingletonClass::StaticClass());  
  
// Get Singleton Pointer  
USingletonSystem::Get().GetPtr<USingletonClass>();  
  
// Get Singleton Referenced  
USingletonSystem::Get().GetRef<USingletonClass>();  
  
// Release Singleton Object  
USingletonSystem::Get().Release<USingletonClass>();  
USingletonSystem::Get().Release(USingletonClass::StaticClass());  
