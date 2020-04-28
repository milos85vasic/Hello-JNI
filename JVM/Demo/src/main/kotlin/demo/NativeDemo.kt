package demo

class NativeDemo {

    companion object {
        init {
            System.loadLibrary("Demo")
        }
    }

    external fun helloNative()
}
