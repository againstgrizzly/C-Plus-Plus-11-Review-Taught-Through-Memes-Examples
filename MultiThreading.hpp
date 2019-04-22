#include <thread>
#include <chrono>

class MultiThreading
{
  public:
    MultiThreading()
    {
        // Believe it or not prior to C++11, C++
        // did not support multithreading in the language
        // nor the standard library. In the past, you needed
        // to use a third party library (such as boost) or rely
        // on platform specific APIs (PThreads, Windows Threads).
        // Gross! Luckily, the future is now. C++11 has
        // extensive support for multithreading

        // The BEST C++11 concurrency tutorial online 
        // https://www.youtube.com/watch?v=LL8wkskDlbs&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M

        // To run on a separate thread, the std::thread class is used
        // When a function pointer, function object, or lambda expression is passed
        // into the constructor of std::thread, the thread is executed

        auto myFunction = [](const std::string &inFunctionName, const int inSleepAmountMilliseconds) {
            for (int i = 0; i < 10; ++i)
            {
                std::cout << inFunctionName << ": " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(inSleepAmountMilliseconds));
            }
        };

        std::thread myThread(myFunction, "My Function", 5); // Launch on new thread
        myThread.join();                                    // Wait until thread completes

        // Lambdas can be directly launched on a new thread
        std::thread lambdaThread([]() {
            std::cout << "Launch lambda on new thread" << std::endl;
        });
        lambdaThread.join();

        // Parameters are passed-by-value into new threads. To pass by reference,
        // use a pointer or use std::ref
        std::string anotherFunction("Another Function");
        std::thread myRefThread(myFunction, std::ref(anotherFunction), 5);
        myRefThread.join();

        // To prevent data races, you can also use std::move to physically
        // move the memory use by your param to the new thread. This is both safe and efficient.

        // If you wish to let a thread complete without blocking the main thread
        // , you can use "detach" myThread.detach();

        // Always make sure to either join or detach your threads before
        // they go out of scope

        /************************************************************************************/
        /****************************** Returning from Threads ******************************/
        /************************************************************************************/
    }
};