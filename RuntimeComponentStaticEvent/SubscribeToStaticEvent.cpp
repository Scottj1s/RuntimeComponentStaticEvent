#include "pch.h"
#include "Class.h"

#if 1
//error C3779 : 'winrt::RuntimeComponentStaticEvent::Class::SomeEvent' : a function that returns 'auto' cannot be used before it is defined
#else
#include "Class.g.cpp"
//error LNK2005 : "public: __cdecl winrt::RuntimeComponentStaticEvent::Class::Class(void)" (? ? 0Class@RuntimeComponentStaticEvent@winrt@@QEAA@XZ) already defined in Class.obj
#endif

using namespace winrt;
using namespace Windows::Foundation;
using namespace RuntimeComponentStaticEvent;

void SubscribeToStaticEvent()
{
	auto revoker = Class::SomeEvent(auto_revoke, [](IInspectable const& , int32_t)
	{
	} );
}
