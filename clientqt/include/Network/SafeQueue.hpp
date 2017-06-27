//
//-----------------------------------------------------------------------------
//Filename:    SafeQueue.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/22/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_SAFEQUEUE_HPP
#define CLIENTQT_SAFEQUEUE_HPP


#include <queue>
#include <mutex>
#include <condition_variable>

namespace zappy {
    template <class T>
    class SafeQueue
    {
    public:
        SafeQueue(void)
                : q()
                , m()
                , c()
        {}

        ~SafeQueue(void)
        {}

        void enqueue(T t)
        {
            std::lock_guard<std::mutex> lock(m);
            q.push(t);
            c.notify_one();
        }

        T dequeue(void)
        {
            std::unique_lock<std::mutex> lock(m);
            while(q.empty())
            {
                c.wait(lock);
            }
            T val = q.front();
            q.pop();
            return val;
        }

        /**
         * Dequeue without wait lock size
         * @param vector
         * @return void
         */
        void dequeueWoWait(std::vector<T> & vector) {
            std::unique_lock<std::mutex> lock(m);
            while (!q.empty())
            {
                T val = q.front();
                vector.push_back(val);
                q.pop();
            }
        }

        size_t size() const {
            std::lock_guard<std::mutex> lock(m);
            return q.size();
        }

    private:
        std::queue<T> q;
        mutable std::mutex m;
        std::condition_variable c;
    };
}

#endif //CLIENTQT_SAFEQUEUE_HPP
