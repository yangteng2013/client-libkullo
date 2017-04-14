// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from event.djinni

#include "Event.h"  // my header
#include "EventType.h"
#include "jni/support-lib/jni/Marshal.hpp"

namespace JNI { namespace Kullo { namespace Api {

Event::Event() = default;

Event::~Event() = default;

auto Event::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<Event>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::JNI::Kullo::Api::EventType::fromCpp(jniEnv, c.event)),
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.conversationId)),
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.messageId)),
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.attachmentId)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto Event::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<Event>::get();
    return {::JNI::Kullo::Api::EventType::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_event)),
            ::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_conversationId)),
            ::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_messageId)),
            ::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_attachmentId))};
}

} } }  // namespace JNI::Kullo::Api
