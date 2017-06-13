//
// Thread.h
//
// Copyright (c) 2017 Jiawei Feng
//

#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <functional>
#include <string>
#include "Noncopyable.h"

namespace Xgeer {
    using std::string;
    class Thread : Noncopyable {
    public:
        typedef std::function<void ()> ThreadFunc;

        explicit Thread(const ThreadFunc&, const string &name = string());

        ~Thread();

        void start();
        int join();

        bool started() const { return started_; }
        pid_t tid() const { return tid_; }
        const string& name() const { return name_; }

        void run(); // FIXME: should be private
    private:
        void setDefaultName();

        bool started_;
        bool joined_;
        pthread_t pthreadId_;
        pid_t tid_;
        ThreadFunc func_;
        string name_;
    };
}

#endif