// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from api.djinni

#pragma once

#include <memory>

namespace Kullo { namespace Api {

class Task;

class TaskRunner {
public:
    virtual ~TaskRunner() {}

    /**
     * Runs the given task asynchronously (simplest case: in a new thread)
     * and returns immediately.
     */
    virtual void runTaskAsync(const std::shared_ptr<Task> & task) = 0;
};

} }  // namespace Kullo::Api