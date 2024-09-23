package br.edu.ufam.icomp.devtitans;

import android.util.Log;
import br.edu.ufam.icomp.devtitans.hellojavalib.*;

class HelloJava {
    public static final String TAG = "DevTITANS.HelloJava";

    void printHello() {
        System.out.println("Hello World in Java!");
        Log.v(TAG, "Hello World in Java (LogCat)!");
        
        HelloJavaLib helloLib = new HelloJavaLib();
        System.out.println("Pi value from Lib: " + helloLib.computePiValue());
    }

    public static void main(String args[]) {
        HelloJava hello = new HelloJava();
        hello.printHello();
    }
}
