#include "pch.h"
#include "Class.h"
#include "Class.g.cpp"

using namespace winrt;
using namespace Windows::Foundation;

void SubscribeToStaticEvent();

namespace winrt::RuntimeComponentStaticEvent::implementation
{
    int32_t Class::MyProperty()
    {
        SubscribeToStaticEvent();
        return 42;
    }

    void Class::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    static winrt::event<EventHandler<int32_t>> _changed {};

    winrt::event_token Class::SomeEvent(winrt::Windows::Foundation::EventHandler<int32_t> const& handler)
    {
        return _changed.add(handler);
    }

    void Class::SomeEvent(winrt::event_token const& token) noexcept
    {
        _changed.remove(token);
    }
}
