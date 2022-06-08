#pragma once

#include "Class.g.h"

namespace winrt::RuntimeComponentStaticEvent::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
        static winrt::event_token SomeEvent(winrt::Windows::Foundation::EventHandler<int32_t> const& handler);
        static void SomeEvent(winrt::event_token const& token) noexcept;
    };
}

namespace winrt::RuntimeComponentStaticEvent::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
