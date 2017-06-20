//
//-----------------------------------------------------------------------------
//Filename:    Singleton.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_SINGLETON_HPP
#define CLIENTQT_SINGLETON_HPP

namespace zappy {
    template <class T>
    class Singleton {
    private:
        static T* _instance;
    public:
        static T* create_instance(T * instance) {
            _instance = instance;
        }

        static T*get_instance_ptr() {
            if (_instance == nullptr)
                _instance = new T;
            return _instance;
        }

        static T&get_instance() {
            return _instance;
        }

        static void destroy_instance() {
            delete _instance;
            _instance = nullptr;
        }
    };

    template <class T> T* Singleton<T>::_instance = nullptr;
};


#endif //CLIENTQT_SINGLETON_HPP
