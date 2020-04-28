#include "demo_library.h"

#include <iostream>

void hello() {
    std::cout << "Hello, young Padawan!" << std::endl;
}

JNIEXPORT void JNICALL Java_demo_NativeDemo_helloNative
        (JNIEnv *, jobject) {

    hello();
}
