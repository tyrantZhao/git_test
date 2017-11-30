#ifndef __SINGLETON_H__
#define __SINGLETON_H__

namespace tyrant
{
    //use local static variable type, compling with std11
    class Singleton
    {
        public:
            Singleton(Singleton const&) = delete;
            Singleton& operator =(const Singleton&) = delete;
            ~Singleton() = default;

            //example
            void DoSomeThing();
            static Singleton& getInstance() {
                static Singleton inst;
                return inst;
            }

        private:
            Singleton() = default;
    };
}

#endif // __SINGLETON_H__
