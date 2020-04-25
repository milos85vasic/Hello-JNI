package demo

class NativeDemo {

    init {
        System.loadLibrary("Demo")
    }

    external fun hello()
}
